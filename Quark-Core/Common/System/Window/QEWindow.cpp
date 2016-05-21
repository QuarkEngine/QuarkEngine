//////////////////////////////////////////////////////////////////////////////////////////////////////
///// This file is part of Quark-Engine, licensed under the Apache 2.0 License.
/////
///// Copyright (c) 2015-2016 - Quark-Engine developers <https://github.com/QuarkEngine/QuarkEngine>.
/////
///// Licensed under the Apache License, Version 2.0 (the "License");
///// you may not use this file except in compliance with the License.
///// You may obtain a copy of the License at:
/////
///// http://www.apache.org/licenses/LICENSE-2.0
/////
///// Unless required by applicable law or agreed to in writing, software
///// distributed under the License is distributed on an "AS IS" BASIS,
///// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
///// See the License for the specific language governing permissions and
///// limitations under the License.
//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////////////////////////////////
///// [HEADER]
//////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "QEWindow.hpp"
//
//////////////////////////////////////////////////////////////////////////////////////////////////////
///// [DECLARATION]
//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//namespace QE
//{
//	QEWindow::QEWindow() :
//		mWindow(nullptr)
//	{
//	}
//
//	QEWindow::~QEWindow()
//	{
//		// Destroy the window
//		glfwDestroyWindow(mWindow);
//
//		// Terminate GLFW
//		glfwTerminate();
//	}
//
//	GLFWwindow* QEWindow::GetHandle() const
//	{
//		return mWindow;
//	}
//
//	Bool QEWindow::Create(const String& title, Int32 x, Int32 y, UInt32 width, UInt32 height, WindowAttribute attributes, Void* userdata)
//	{
//		// Initialise GLFW
//		if (!glfwInit())
//		{
//			return false;
//		}
//
//		// Check if the window should be borderless
//		if ((attributes & WindowAttribute::BORDERLESS))
//		{
//			glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
//		}
//
//		// Check if the window should be resizeable
//		if ((attributes & WindowAttribute::RESIZEABLE))
//		{
//			glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
//		}
//
//		// Create a fullscreen window if applicable
//		if ((attributes & WindowAttribute::FULLSCREEN))
//		{
//			// Get the primary monitor and its video mode
//			const auto primaryMonitor = glfwGetPrimaryMonitor();
//			const auto vidMode = glfwGetVideoMode(primaryMonitor);
//
//			// Set the requested refresh rate
//			glfwWindowHint(GLFW_REFRESH_RATE, vidMode->refreshRate);
//
//			// Create the window
//			mWindow = glfwCreateWindow(width, height, title.c_str(), primaryMonitor, nullptr);
//		}
//		else
//		{
//			// Create the window
//			mWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
//		}
//
//		// Ensure the window was created successfully
//		if (mWindow == nullptr)
//		{
//			return false;
//		}
//
//		// Set the window position
//		glfwSetWindowPos(mWindow, x, y);
//
//		// Set the window userdata pointer
//		glfwSetWindowUserPointer(mWindow, userdata);
//
//
//		return true;
//	}
//
//	Void QEWindow::GetDimension(UInt32& width, UInt32& height) const
//	{
//		glfwGetWindowSize(mWindow, reinterpret_cast<int*>(&width), reinterpret_cast<int*>(&height));
//	}
//
//	Void QEWindow::SetTitle(const String& title)
//	{
//		glfwSetWindowTitle(mWindow, title.c_str());
//	}
//
//	Bool QEWindow::IsResizable() const
//	{
//		return glfwGetWindowAttrib(mWindow, GLFW_RESIZABLE) == GLFW_TRUE;
//	}
//
//	Bool QEWindow::IsDecorated() const
//	{
//		return glfwGetWindowAttrib(mWindow, GLFW_DECORATED) == GLFW_TRUE;
//	}
//
//	Bool QEWindow::IsWindowed() const
//	{
//		return glfwGetWindowMonitor(mWindow) == nullptr;
//	}
//
//	Bool QEWindow::IsFullscreen() const
//	{
//		return glfwGetWindowMonitor(mWindow) != nullptr;
//	}
//
//	Void QEWindow::SetDimension(UInt16 width, UInt16 height)
//	{
//		glfwSetWindowSize(mWindow, width, height);
//	}
//
//	Void QEWindow::SwitchToWindowed(UInt16 width, UInt16 height)
//	{
//		// Only switch to windows is applicable
//		if (IsFullscreen())
//		{
//			glfwSetWindowMonitor(mWindow, nullptr, 0, 0, width, height, 0);
//		}
//	}
//
//	Void QEWindow::SwitchToFullscreen()
//	{
//		// Only switch to fullscreen is applicable
//		if (!IsFullscreen())
//		{
//			// Get the primary monitor and its video mode
//			const auto primaryMonitor = glfwGetPrimaryMonitor();
//			const auto vidMode = glfwGetVideoMode(primaryMonitor);
//
//			// Enable fullscreen by setting the monitor (x and y coordinates are ignored)
//			glfwSetWindowMonitor(mWindow, primaryMonitor, 0, 0, vidMode->width, vidMode->height, vidMode->refreshRate);
//		}
//	}
//}
