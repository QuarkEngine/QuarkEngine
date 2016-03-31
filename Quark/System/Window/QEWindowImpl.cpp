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

////////////////////////////////////////////////////////////////////////////////////////////////////
/// [HEADER]
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "QEWindowImpl.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// [DECLARATION]
////////////////////////////////////////////////////////////////////////////////////////////////////


QE::WindowImpl::WindowImpl() :
	mWindow(nullptr)
{
}


QE::WindowImpl::~WindowImpl()
{
	// Destroy the window
	glfwDestroyWindow(mWindow);

	// Terminate GLFW
	glfwTerminate();
}


QE::Bool QE::WindowImpl::Create(const String& title, Int32 x, Int32 y, UInt32 width, UInt32 height, WindowAttribute attributes)
{
	// Initialise GLFW
	if (!glfwInit())
	{
		return false;
	}

	// Check if the window should be borderless
	if (HasBit(attributes, WindowAttribute::BORDERLESS))
	{
		glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
	}

	// Check if the window should be resizeable
	if (HasBit(attributes, WindowAttribute::RESIZEABLE))
	{
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
	}

	// Check if the window should be hidden
	if (HasBit(attributes, WindowAttribute::HIDDEN))
	{
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	}


	// Create a fullscreen window if applicable
	if (HasBit(attributes, WindowAttribute::FULLSCREEN))
	{
		// Get the primary monitor and its video mode
		const auto primaryMonitor = glfwGetPrimaryMonitor();
		const auto vidMode = glfwGetVideoMode(primaryMonitor);

		// Set the requested refresh rate
		glfwWindowHint(GLFW_REFRESH_RATE, vidMode->refreshRate);

		// Create the window
		mWindow = glfwCreateWindow(width, height, title.c_str(), primaryMonitor, nullptr);
	}
	else
	{
		// Create the window
		mWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	}

	// Ensure the window was created successfully
	if (mWindow == nullptr)
	{
		return false;
	}

	// Set the position of the window

	return true;
}


GLFWwindow* QE::WindowImpl::GetHandle() const
{
	return mWindow;
}


QE::Void QE::WindowImpl::GetDimension(UInt32& width, UInt32& height) const
{
	glfwGetWindowSize(mWindow, reinterpret_cast<int*>(&width), reinterpret_cast<int*>(&height));
}


QE::Bool QE::WindowImpl::IsVisible() const
{
	return glfwGetWindowAttrib(mWindow, GLFW_VISIBLE);
}


QE::Bool QE::WindowImpl::IsResizable() const
{
	return glfwGetWindowAttrib(mWindow, GLFW_RESIZABLE);
}


QE::Bool QE::WindowImpl::IsDecorated() const
{
	return glfwGetWindowAttrib(mWindow, GLFW_DECORATED);
}


QE::Bool QE::WindowImpl::IsWindowed() const
{
	return glfwGetWindowMonitor(mWindow) == nullptr;
}


QE::Bool QE::WindowImpl::IsFullscreen() const
{
	return glfwGetWindowMonitor(mWindow) != nullptr;
}


QE::Void QE::WindowImpl::SetDimension(UInt16 width, UInt16 height)
{
	glfwSetWindowSize(mWindow, width, height);
}


QE::Void QE::WindowImpl::SetTitle(const String& title)
{
	glfwSetWindowTitle(mWindow, title.c_str());
}


QE::Void QE::WindowImpl::SetVisibility(Bool visible)
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


QE::Void QE::WindowImpl::SwitchToWindowed(UInt16 width, UInt16 height)
{
	// Only switch to fullscreen is applicable
	if (IsFullscreen())
	{
		// TODO: Allow custom positioning or auto-centre the window
		glfwSetWindowMonitor(mWindow, nullptr, 0, 0, width, height, 0);
	}
}


QE::Void QE::WindowImpl::SwitchToFullscreen()
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


QE::Void QE::WindowImpl::SwitchToFullscreen(UInt16 width, UInt16 height)
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
