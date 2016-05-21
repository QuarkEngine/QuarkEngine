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
#include "System/Window/WindowAttribute.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// [DEFINITION]
////////////////////////////////////////////////////////////////////////////////////////////////////
namespace QE
{
	//!
	//! \brief Encapsulate the base definition of a window
	//!
	class Window
	{
	public:
		//!
		//! \brief Get the dimension of the window (in screen coordinates)
		//!
		//! \param[in] width    -   The value to store the width in
		//! \param[in] height   -   The value to store the height in
		//!
		virtual Void GetDimension(UInt32& width, UInt32& height) const = 0;

		//!
		//! \brief Changes the size of the window
		//!
		//! \param[in] width    -   The new width (in screen coordinates)
		//! \param[in] height   -   The new height (in screen coordinates)
		//!
		virtual Void SetDimension(UInt32 width, UInt32 height) = 0;

		//!
		//! \brief Changes the title of the window
		//!
		//! \param[in] title    -	The new title of the window
		//!
		virtual Void SetTitle(const String & title) = 0;

		//!
		//! \brief Check whenever the window is resizable (windowed mode)
		//!
		//! \return True if the window is resizable, false otherwise
		//!
		virtual Bool IsResizable() const = 0;

		//!
		//! \brief Check whenever the window is borderless (windowed mode)
		//!
		//! \return True if the window is borderless, false otherwise
		//!
		virtual Bool IsBorderless() const = 0;

		//!
		//! \brief Check whenever the window is in windowed mode
		//!
		//! \return True if the window is in windowed mode, false otherwise
		//!
		virtual Bool IsWindowed() const = 0;

		//!
		//! \brief Check whenever the window is in fullscreen mode
		//!
		//! \return True if the window is in fullscreen mode, false otherwise
		//!
		virtual Bool IsFullscreen() const = 0;

		//!
		//! \brief Change the current mode of the window to windowed mode
		//!
		virtual Void SwitchToWindowed() = 0;

		//!
		//! \brief Change the current mode of the window to fullscreen mode
		//!
		virtual Void SwitchToFullscreen() = 0;
	};
}
