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
#ifndef __QUARK_ENGINE_SYSTEM_WINDOWIMPL_HPP__
#define __QUARK_ENGINE_SYSTEM_WINDOWIMPL_HPP__

////////////////////////////////////////////////////////////////////////////////////////////////////
/// [HEADER]
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "System/Window/QEWindow.hpp"
#include <GLFW/glfw3.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
/// [DEFINITION]
////////////////////////////////////////////////////////////////////////////////////////////////////
namespace QE
{
	//!
	//! \brief Encapsulate the base definition of a window
	//!
	class WindowImpl : public Window
	{
	public:
		//!
		//! \brief Constructs an instance of WindowImpl
		//!
		WindowImpl();

		//!
		//! \brief Destructs the instance of WindowImpl
		//!
		~WindowImpl();
	public:
		//!
		//! \brief Get the dimension of the window (in screen coordinates)
		//!
		//! \param[in] width    -   The value to store the width in
		//! \param[in] height   -   The value to store the height in
		//!
		Void GetDimension(UInt32& width, UInt32& height) const override;

		//!
		//! \brief Check whenever the window is visible
		//!
		//! \return True if the window is visible, false otherwise
		//!
		Bool IsVisible() const override;

		//!
		//! \brief Check whenever the window is resizable (windowed mode)
		//!
		//! \return True if the window is resizable, false otherwise
		//!
		Bool IsResizable() const override;

		//!
		//! \brief Check whenever the window is decorated (windowed mode)
		//!
		//! \return True if the window is decorated, false otherwise
		//!
		Bool IsDecorated() const override;

		//!
		//! \brief Check whenever the window is in windowed mode
		//!
		//! \return True if the window is in windowed mode, false otherwise
		//!
		Bool IsWindowed() const override;

		//!
		//! \brief Check whenever the window is in fullscreen mode
		//!
		//! \return True if the window is in fullscreen mode, false otherwise
		//!
		Bool IsFullscreen() const override;
	public:
		//!
		//! \brief Changes the size of the window
		//!
		//! \param[in] width    -   The new width (in screen coordinates)
		//! \param[in] height   -   The new height (in screen coordinates)
		//!
		Void SetDimension(UInt16 width, UInt16 height) override;

		//!
		//! \brief Changes the title of the window
		//!
		//! \param[in] title    -   The new title of the window
		//!
		Void SetTitle(const String& title) override;

		//!
		//! \brief Change the visibility of the window (Only applicable for windowed mode)
		//!
		//! \param[in] visible   -   True to show the window, false otherwise
		//!
		Void SetVisibility(Bool visibility) override;

		//!
		//! \brief Change the current mode of the window to windowed mode
		//!
		//! \param[in] width    -   The new width (in screen coordinates)
		//! \param[in] height   -   The new height (in screen coordinates)
		//!
		Void SwitchToWindowed(UInt16 width, UInt16 height) override;

		//!
		//! \brief Change the current mode of the window to fullscreen mode
		//!
		Void SwitchToFullscreen() override;

		//!
		//! \brief Change the current mode of the window to fullscreen mode
		//!
		//! \param[in] width    -   The new width (in screen coordinates)
		//! \param[in] height   -   The new height (in screen coordinates)
		//!
		Void SwitchToFullscreen(UInt16 width, UInt16 height) override;
	private:
		GLFWwindow* mWindow;
	};
}

#endif // __QUARK_ENGINE_SYSTEM_WINDOWIMPL_HPP__
