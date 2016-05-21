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
#include "System/Input/Keyboard.hpp"
#include "System/Input/Mouse.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// [DEFINITION]
////////////////////////////////////////////////////////////////////////////////////////////////////
namespace QE
{
	//!
	//! \brief Function callback for a key event
	//!
	using KeyCallback = std::function<void(KeyState, KeyModifier)>;

	//!
	//! \brief Function callback for a mouse button event
	//!
	using MouseButtonCallback = std::function<void(MouseButton, Int32, Int32)>;

	//!
	//! \brief Function callback for a mouse move event
	//!
	using MouseMoveCallback = std::function<void(Int32, Int32)>;

	//!
	//! \brief Encapsulate the base definition of an input manager
	//!
	class InputManager
	{
	public:
		//!
		//! \brief Checks if the specified key is currently pressed
		//!
		//! \param[in] key	-	The key to check if it is pressed
		//!
		//! \return True if the key is pressed
		//!
		virtual Bool IsKeyPressed(Key key) const = 0;

		//!
		//! \brief Registers the callback to the key
		//!
		//! \param[in] key		-	The key to associate the callback with
		//! \param[in] callback	-	The callback to invoke
		//!
		virtual Void RegisterKeyCallback(Key key, KeyCallback callback) = 0;

		//!
		//! \brief Registers the callback to the mouse button
		//!
		//! \param[in] button	-	The button to associate the callback with
		//! \param[in] callback	-	The callback to invoke
		//!
		virtual Void RegisterMouseButtonCallback(MouseButton button, MouseButtonCallback callback) = 0;

		//!
		//! \brief Registers the callback for any mouse movement
		//!
		//! \param[in] callback	-	The callback to invoke
		//!
		virtual Void RegisterMouseMoveCallback(MouseMoveCallback callback) = 0;
	};
}
