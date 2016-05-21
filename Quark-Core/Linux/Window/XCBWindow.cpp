////////////////////////////////////////////////////////////////////////////////////////////////////
/// This file is part of Quark-Engine, licensed under the Apache 2.0 License.
///
/// Copyright (c) 2015-2016 - Quark-Engine developers <https://github.com/QuarkEngine/QuarkEngine>.
///
/// Licensed under the Apache License, Version 2.0 (the "License");F
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at:
///
/// http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
/// [HEADER]
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "XCBWindow.hpp"
#include <xcb/xcb_icccm.h>

// This is needed to make QE compile with XKB. xkb.h is using a variable
// which is called 'explicit', this is a reserved keyword in C++
#define explicit _explicit
#include <xcb/xkb.h>
#undef explicit

////////////////////////////////////////////////////////////////////////////////////////////////////
/// [DEFINITION]
////////////////////////////////////////////////////////////////////////////////////////////////////

namespace QE
{
	//!
	//! \brief Constructs an instance of XCBWindow
	//!
	XCBWindow::XCBWindow() :
		mConnection(nullptr),
		mScreen(nullptr),
		mWindow(0U),
		ATOM_WM_PROTOCOLS(XCB_ATOM_NONE),
		ATOM_WM_DELETE_WINDOW(XCB_ATOM_NONE),
		ATOM_WM_STATE(XCB_ATOM_NONE),
		ATOM_WM_STATE_FULLSCREEN(XCB_ATOM_NONE),
		ATOM_WM_STATE_MAXIMISED_HORZ(XCB_ATOM_NONE),
		ATOM_WM_STATE_MAXIMISED_VERT(XCB_ATOM_NONE),
		mIsFullscreen(false)
	{
	}

	//!
	//! \brief Destructs the instance of XCBWindow
	//!
	XCBWindow::~XCBWindow()
	{
		// Destory the window
		xcb_destroy_window(mConnection, mWindow);

		// Disconnect from the X server
		xcb_disconnect(mConnection);
	}

	//!
	//! \brief Creates a new window
	//!
	//! \param[in] title        -   The title of the window
	//! \param[in] x            -   The X position of the window (in screen coordinates)
	//! \param[in] y            -   The Y position of the window (in screen coordinates)
	//! \param[in] width        -   The width of the window
	//! \param[in] height       -   The height of the window
	//! \param[in] attributes   -   The window attributes
	//!
	//! \return True if the window was successfully created, false otherwise
	//!
	Bool XCBWindow::Create(const String& title, Int32 x, Int32 y, UInt32 width, UInt32 height, WindowAttribute attributes, Void* userdata)
	{
		// Open the connection to the X server
		auto screenNumber = 0;
		mConnection = xcb_connect(nullptr, &screenNumber);
		if (xcb_connection_has_error(mConnection))
		{
			return false;
		}

		// Retrieve the first screen
		const auto setup = xcb_get_setup(mConnection);
		auto iter = xcb_setup_roots_iterator(setup);
		for (; iter.rem; --screenNumber, xcb_screen_next(&iter))
		{
			if (screenNumber == 0)
			{
				mScreen = iter.data;
				break;
			}
		}

		// Generate a window ID
		mWindow = xcb_generate_id(mConnection);

		// The window mask
		const auto value_mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;

		// The window mask values
		const UInt32 value_list[] = {
			mScreen->white_pixel,
			XCB_EVENT_MASK_EXPOSURE | XCB_EVENT_MASK_BUTTON_PRESS | XCB_EVENT_MASK_BUTTON_RELEASE | XCB_EVENT_MASK_KEY_PRESS | XCB_EVENT_MASK_KEY_RELEASE | XCB_EVENT_MASK_POINTER_MOTION
		};

		// Create the window
		xcb_create_window(mConnection, XCB_COPY_FROM_PARENT, mWindow, mScreen->root, x, y, width, height, 0U, XCB_WINDOW_CLASS_INPUT_OUTPUT, mScreen->root_visual, value_mask, value_list);

		// Retrieve the required atoms
		ATOM_WM_PROTOCOLS = GetAtom("WM_PROTOCOLS");
		ATOM_WM_DELETE_WINDOW = GetAtom("WM_DELETE_WINDOW");
		ATOM_WM_STATE = GetAtom("_NET_WN_STATE");
		ATOM_WM_STATE_FULLSCREEN = GetAtom("_NET_WM_STATE_FULLSCREEN");
		ATOM_WM_STATE_MAXIMISED_HORZ = GetAtom("_NET_WM_STATE_MAXIMIZED_HORZ");
		ATOM_WM_STATE_MAXIMISED_VERT = GetAtom("_NET_WM_STATE_MAXIMIZED_VERT");

		// Copy the window attributes and store them
		mAttributes = attributes;

		// Set the borderless state
		if (attributes & WindowAttribute::BORDERLESS)
		{
			struct MotifHints
			{
				UInt32 flags;
				UInt32 functions;
				UInt32 decorations;
				Int32 inputMode;
				UInt32 status;
			} hints;

			hints.flags = 2U;
			hints.functions = 0U;
			hints.decorations = 0U;
			hints.inputMode = 0;
			hints.status = 0U;

			// Get the motif hints atom
			const std::string name = "_MOTIF_WM_HINTS";
			const auto atom = xcb_intern_atom(mConnection, false, name.length(), name.data());
			// Get the atom reply
			const auto reply = xcb_intern_atom_reply(mConnection, atom, nullptr);

			if (reply != nullptr)
			{
				// Change the border property
				xcb_change_property(mConnection, XCB_PROP_MODE_REPLACE, mWindow, reply->atom, reply->atom, 32U, 5U, &hints);

				// Free the reply
				std::free(reply);
			}
		}

		// Set the maximised state
		if (attributes & WindowAttribute::MAXIMISED)
		{
			xcb_client_message_event_t event{ };
			event.response_type = XCB_CLIENT_MESSAGE;
			event.format = 32U;
			event.window = mWindow;
			event.type = ATOM_WM_STATE;
			event.data.data32[0] = 1U;
			event.data.data32[1] = ATOM_WM_STATE_MAXIMISED_HORZ;
			event.data.data32[2] = ATOM_WM_STATE_MAXIMISED_VERT;
			event.data.data32[3] = XCB_ATOM_NONE;
			event.data.data32[4] = 0U;

			// Send the event
			xcb_send_event(mConnection, false, mWindow, XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT | XCB_EVENT_MASK_STRUCTURE_NOTIFY, reinterpret_cast<const char*>(&event));
		}

		// Set the fullscreen state
		if (attributes & WindowAttribute::FULLSCREEN)
		{
			SwitchToFullscreen();
		}

		// Set the resizeable state
		if (!(attributes & WindowAttribute::RESIZEABLE))
		{
			xcb_size_hints_t hints;

			xcb_icccm_size_hints_set_min_size(&hints, width, height);
			xcb_icccm_size_hints_set_max_size(&hints, width, height);

			xcb_icccm_set_wm_size_hints(mConnection, mWindow, XCB_ATOM_WM_NORMAL_HINTS, &hints);
		}

		// Allow the window to be close via the close button
		xcb_change_property(mConnection, XCB_PROP_MODE_REPLACE, mWindow, ATOM_WM_PROTOCOLS, XCB_ATOM_ATOM, 32U, 1U, &ATOM_WM_DELETE_WINDOW);

		// Set the window title
		SetTitle(title);

		// Map the window to the screen
		xcb_map_window(mConnection, mWindow);

		// Ensure commands have been sent
		xcb_flush(mConnection);

		// Temporary
		{
			auto running = true;

			while (running)
			{
				// Poll XCB for the next event
				const auto event = xcb_poll_for_event(mConnection);

				if (event != nullptr)
				{
					const auto eventType = event->response_type & ~0x80;
					switch (eventType)
					{
						case XCB_MOTION_NOTIFY:
						{
							//const auto message = reinterpret_cast<xcb_motion_notify_event_t*>(event);
							//std::printf("Mouse Coordinates [%u, %u]\n", message->event_x, message->event_y);
							break;
						}
						case XCB_BUTTON_PRESS:
						{
							const auto message = reinterpret_cast<xcb_button_press_event_t*>(event);
							std::printf("Mouse Clicked [%u, %u]\n", message->event_x, message->event_y);
							break;
						}
						case XCB_BUTTON_RELEASE:
						{
							const auto message = reinterpret_cast<xcb_button_release_event_t*>(event);
							std::printf("Mouse Released [%u, %u]\n", message->event_x, message->event_y);
							break;
						}
						case XCB_KEY_PRESS:
						{
							const auto message = reinterpret_cast<xcb_key_press_event_t*>(event);
							std::printf("Key Pressed [%u]\n", message->detail);
							break;
						}
						case XCB_KEY_RELEASE:
						{
							const auto message = reinterpret_cast<xcb_key_release_event_t*>(event);
							std::printf("Key Released [%u]\n", message->detail);
							break;
						}
						case XCB_EXPOSE:
						{
							const auto message = reinterpret_cast<xcb_expose_event_t*>(event);
							std::printf("Window Exposed in the Region [%u, %u] to [%u, %u]\n", message->x, message->y, (message->x + message->width), (message->y + message->height));
							break;
						}
						case XCB_CLIENT_MESSAGE:
						{
							const auto message = reinterpret_cast<xcb_client_message_event_t*>(event);
							if (message->data.data32[0] == ATOM_WM_DELETE_WINDOW)
							{
								running = false;
							}
							break;
						}
						default:
							std::printf("Unknown Event: %u\n", eventType);
							break;
					}
					std::free(event);
				}
			}
		}

		return true;
	}

	//!
	//! \inheritDoc
	//!
	Void XCBWindow::GetDimension(UInt32& width, UInt32& height) const
	{
		// Ask XCB for the window geometry
		const auto geo = xcb_get_geometry(mConnection, mWindow);
		const auto reply = xcb_get_geometry_reply(mConnection, geo, nullptr);

		// Store the window width and height
		width = reply->width;
		height = reply->height;

		// Release the reply
		std::free(reply);
	}

	//!
	//! \inheritDoc
	//!
	Void XCBWindow::SetDimension(UInt32 width, UInt32 height)
	{
		const UInt32 values[] = { width, height };
		xcb_configure_window(mConnection, mWindow, XCB_CONFIG_WINDOW_WIDTH | XCB_CONFIG_WINDOW_HEIGHT, values);
		xcb_flush(mConnection);
	}

	//!
	//! \inheritDoc
	//!
	Void XCBWindow::SetTitle(const String& title)
	{
		xcb_change_property(mConnection, XCB_PROP_MODE_REPLACE, mWindow, XCB_ATOM_WM_NAME, XCB_ATOM_STRING, 8U, title.length(), title.data());
		xcb_flush(mConnection);
	}

	//!
	//! \inheritDoc
	//!
	Bool XCBWindow::IsResizable() const
	{
		return (mAttributes & WindowAttribute::RESIZEABLE) != 0;
	}

	//!
	//! \inheritDoc
	//!
	Bool XCBWindow::IsBorderless() const
	{
		return (mAttributes & WindowAttribute::BORDERLESS) != 0;
	}

	//!
	//! \inheritDoc
	//!
	Bool XCBWindow::IsWindowed() const
	{
		return !mIsFullscreen;
	}

	//!
	//! \inheritDoc
	//!
	Bool XCBWindow::IsFullscreen() const
	{
		return mIsFullscreen;
	}

	//!
	//! \inheritDoc
	//!
	Void XCBWindow::SwitchToWindowed()
	{
		// Only switch to windowed if currently in fullscreen mode
		if (IsFullscreen())
		{
			xcb_client_message_event_t event{ };
			event.response_type = XCB_CLIENT_MESSAGE;
			event.format = 32U;
			event.window = mWindow;
			event.type = ATOM_WM_STATE;
			event.data.data32[0] = 0U;
			event.data.data32[1] = ATOM_WM_STATE_FULLSCREEN;
			event.data.data32[2] = XCB_ATOM_NONE;
			event.data.data32[3] = 0U;
			event.data.data32[4] = 0U;

			// Send the event
			xcb_send_event(mConnection, true, mWindow, XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT | XCB_EVENT_MASK_STRUCTURE_NOTIFY, reinterpret_cast<const char*>(&event));

			// Set the fullscreen state
			mIsFullscreen = false;
		}
	}

	//!
	//! \inheritDoc
	//!
	Void XCBWindow::SwitchToFullscreen()
	{
		// Only switch to fullscreen if currently in windowed mode
		if (IsWindowed())
		{
			xcb_client_message_event_t event{ };
			event.response_type = XCB_CLIENT_MESSAGE;
			event.format = 32U;
			event.window = mWindow;
			event.type = ATOM_WM_STATE;
			event.data.data32[0] = 1U;
			event.data.data32[1] = ATOM_WM_STATE_FULLSCREEN;
			event.data.data32[2] = XCB_ATOM_NONE;
			event.data.data32[3] = 0U;
			event.data.data32[4] = 0U;

			// Send the event
			xcb_send_event(mConnection, true, mWindow, XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT | XCB_EVENT_MASK_STRUCTURE_NOTIFY, reinterpret_cast<const char*>(&event));

			// Set the fullscreen state
			mIsFullscreen = true;
		}
	}

	//!
	//! \brief Helper method to retrieve an atom from XCB
	//!
	//! \param[in] name -   The name of the atom
	//!
	//! \return The atom
	//!
	xcb_atom_t XCBWindow::GetAtom(const String& name) const
	{
		// Get the intern atom
		const auto internAtom = xcb_intern_atom(mConnection, false, name.length(), name.data());
		// Get the atom reply
		const auto reply = xcb_intern_atom_reply(mConnection, internAtom, nullptr);

		if (reply != nullptr)
		{
			// Copy the atom
			const auto atom = reply->atom;

			// Free the reply
			std::free(reply);

			return atom;
		}
		return XCB_ATOM_NONE;
	}
}
