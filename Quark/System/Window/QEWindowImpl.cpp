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

#include "QEWindowImpl.hpp"
using namespace QE;

//!
//! \brief Constructs an instance of WindowImpl
//!
WindowImpl::WindowImpl() :
	mWindow(nullptr)
{
}

//!
//! \brief Destructs the instance of WindowImpl
//!
WindowImpl::~WindowImpl()
{
	// Destroy the window
	glfwDestroyWindow(mWindow);
}

//!
//! \brief Get the width of the window (in screen coordinates)
//!
//! \return The width of the window (in screen coordinates)
//!
UInt16 WindowImpl::GetWidth() const
{
	Int32 width;
	glfwGetWindowSize(mWindow, &width, nullptr);

	return width;
}

//!
//! \brief Get the height of the window (in screen coordinates)
//!
//! \return The height of the window (in screen coordinates)
//!
UInt16 WindowImpl::GetHeight() const
{
	Int32 height;
	glfwGetWindowSize(mWindow, nullptr, &height);

	return height;
}

//!
//! \brief Check whenever the window is visible
//!
//! \return True if the window is visible, false otherwise
//!
Bool WindowImpl::IsVisible() const
{
	return glfwGetWindowAttrib(mWindow, GLFW_VISIBLE);
}

//!
//! \brief Check whenever the window is resizable (windowed mode)
//!
//! \return True if the window is resizable, false otherwise
//!
Bool WindowImpl::IsResizable() const
{
	return glfwGetWindowAttrib(mWindow, GLFW_RESIZABLE);
}

//!
//! \brief Check whenever the window is decorated (windowed mode)
//!
//! \return True if the window is decorated, false otherwise
//!
Bool WindowImpl::IsDecorated() const
{
	return glfwGetWindowAttrib(mWindow, GLFW_DECORATED);
}

//!
//! \brief Check whenever the window is in windowed mode
//!
//! \return True if the window is in windowed mode, false otherwise
//!
Bool WindowImpl::IsWindowed() const
{
	return glfwGetWindowMonitor(mWindow) == nullptr;
}

//!
//! \brief Check whenever the window is in fullscreen mode
//!
//! \return True if the window is in fullscreen mode, false otherwise
//!
Bool WindowImpl::IsFullscreen() const
{
	return glfwGetWindowMonitor(mWindow) != nullptr;
}

//!
//! \brief Changes the size of the window
//!
//! \param[in] width    -   The new width (in screen coordinates)
//! \param[in] height   -   The new height (in screen coordinates)
//!
Void WindowImpl::SetDimension(UInt16 width, UInt16 height)
{
	glfwSetWindowSize(mWindow, width, height);
}

//!
//! \brief Changes the title of the window
//!
//! \param[in] title    -   The new title of the window
//!
Void WindowImpl::SetTitle(const String& title)
{
	glfwSetWindowTitle(mWindow, title.c_str());
}

//!
//! \brief Change the visibility of the window (Only applicable for windowed mode)
//!
//! \param[in] visible   -   True to show the window, false otherwise
//!
Void WindowImpl::SetVisibility(Bool visible)
{
	if (visible)
	{
		glfwShowWindow(mWindow);
	}
	else
	{
		glfwHideWindow(mWindow);
	}
}

//!
//! \brief Change the current mode of the window to windowed mode
//!
//! \param[in] width    -   The new width (in screen coordinates)
//! \param[in] height   -   The new height (in screen coordinates)
//! \param[in] mode     -   The decoration mode of the window
//!
Void WindowImpl::SwitchToWindowed(UInt16 width, UInt16 height)
{
	// Only switch to fullscreen is applicable
	if (IsFullscreen())
	{
		// TODO: Allow custom positioning or auto-centre the window
		glfwSetWindowMonitor(mWindow, nullptr, 0, 0, width, height, 0);
	}
}

//!
//! \brief Change the current mode of the window to fullscreen mode
//!
Void WindowImpl::SwitchToFullscreen()
{
	// Only switch to fullscreen is applicable
	if (!IsFullscreen())
	{
		// Get the primary monitor and its video mode
		const auto primaryMonitor = glfwGetPrimaryMonitor();
		const auto vidMode = glfwGetVideoMode(primaryMonitor);

		// Enable fullscreen by setting the monitor (x and y coordinates are ignored)
		glfwSetWindowMonitor(mWindow, primaryMonitor, 0, 0, vidMode->width, vidMode->height, vidMode->refreshRate);
	}
}

//!
//! \brief Change the current mode of the window to fullscreen mode
//!
//! \param[in] width    -   The new width (in screen coordinates)
//! \param[in] height   -   The new height (in screen coordinates)
//!
Void WindowImpl::SwitchToFullscreen(UInt16 width, UInt16 height)
{
	// Only switch to fullscreen is applicable
	if (!IsFullscreen())
	{
		// Get the primary monitor and its video mode
		const auto primaryMonitor = glfwGetPrimaryMonitor();
		const auto vidMode = glfwGetVideoMode(primaryMonitor);

		// Enable fullscreen by setting the monitor (x and y coordinates are ignored)
		glfwSetWindowMonitor(mWindow, primaryMonitor, 0, 0, width, height, vidMode->refreshRate);
	}
}