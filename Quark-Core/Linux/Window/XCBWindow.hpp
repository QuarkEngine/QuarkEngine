////////////////////////////////////////////////////////////////////////////////////////////////////
/// This file is part of Quark-Engine, licensed under the Apache 2.0 License.
///
/// Copyright (c) 2015-2016 - Quark-Engine developers <https://github.com/QuarkEngine/QuarkEngine>.
///
/// Licensed under the Apache License, Version 2.0 (the "License");
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
#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
/// [HEADER]
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "System/Window/Window.hpp"
#include <xcb/xcb.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
/// [DEFINITION]
////////////////////////////////////////////////////////////////////////////////////////////////////
namespace QE
{
	//!
	//! \brief The XCB window implementation
	//!
	class XCBWindow final : public Window
	{
	public:
		//!
		//! \brief Constructs an instance of XCBWindow
		//!
		XCBWindow();

		//!
		//! \brief Destructs the instance of XCBWindow
		//!
		~XCBWindow();
	public:
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
		Bool Create(const String& title, Int32 x, Int32 y, UInt32 width, UInt32 height, WindowAttribute attributes, Void* userdata);
	public:
		//!
		//! \inheritDoc
		//!
		Void GetDimension(UInt32& width, UInt32& height) const override;

		//!
		//! \inheritDoc
		//!
		Void SetDimension(UInt32 width, UInt32 height) override;

		//!
		//! \inheritDoc
		//!
		Void SetTitle(const String& title) override;

		//!
		//! \inheritDoc
		//!
		Bool IsResizable() const override;

		//!
		//! \inheritDoc
		//!
		Bool IsBorderless() const override;

		//!
		//! \inheritDoc
		//!
		Bool IsWindowed() const override;

		//!
		//! \inheritDoc
		//!
		Bool IsFullscreen() const override;

		//!
		//! \inheritDoc
		//!
		Void SwitchToWindowed() override;

		//!
		//! \inheritDoc
		//!
		Void SwitchToFullscreen() override;
	private:
		//!
		//! \brief Helper method to retrieve an atom from XCB
		//!
		//! \param[in] name -   The name of the atom
		//!
		//! \return The atom
		//!
		xcb_atom_t GetAtom(const String& name) const;
	private:
		xcb_connection_t* mConnection;
		xcb_screen_t* mScreen;
		xcb_window_t mWindow;
		xcb_atom_t ATOM_WM_PROTOCOLS;
		xcb_atom_t ATOM_WM_DELETE_WINDOW;
		xcb_atom_t ATOM_WM_STATE;
		xcb_atom_t ATOM_WM_STATE_FULLSCREEN;
		xcb_atom_t ATOM_WM_STATE_MAXIMISED_HORZ;
		xcb_atom_t ATOM_WM_STATE_MAXIMISED_VERT;
		WindowAttribute mAttributes;
		Bool mIsFullscreen;
	};
}
