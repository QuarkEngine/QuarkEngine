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
//#pragma once
//
//////////////////////////////////////////////////////////////////////////////////////////////////////
///// [HEADER]
//////////////////////////////////////////////////////////////////////////////////////////////////////
//#include "System/Input/InputManager.hpp"
//#include <GLFW/glfw3.h>
//
//////////////////////////////////////////////////////////////////////////////////////////////////////
///// [DEFINITION]
//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//namespace QE
//{
//	//!
//	//! \brief Encapsulate the base definition of an input manager
//	//!
//	class QEInputManager final : public InputManager
//	{
//	public:
//		//!
//		//! \brief Handles the initialises of the input manager
//		//!
//		Void Initialise(GLFWwindow* window);
//
//		//!
//		//! \brief Polls the window for input
//		//!
//		Void PollInput();
//
//		//!
//		//! \inheritDoc
//		//!
//		Bool IsKeyPressed(Key key) const override;
//
//		//!
//		//! \inheritDoc
//		//!
//		Void RegisterKeyCallback(Key key, KeyCallback callback) override;
//
//		//!
//		//! \inheritDoc
//		//!
//		Void RegisterMouseButtonCallback(MouseButton button, MouseButtonCallback callback) override;
//
//		//!
//		//! \inheritDoc
//		//!
//		Void RegisterMouseMoveCallback(MouseMoveCallback callback) override;
//	private:
//		//!
//		//! \brief The callback inserted into GLFW to receive input when the window is polled
//		//!
//		//! \param[in] window	-	The window the input is received from
//		//! \param[in] key		-	The key which the event is about
//		//! \param[in] scancode	-	The system scancode of the key
//		//! \param[in] action	-	The action down to the key
//		//! \param[in] mods		-	Modifiers applied with the key
//		//!
//		static Void HandleKeyInput(GLFWwindow* window, int key, int scancode, int action, int modifiers);
//	private:
//		template<typename T>
//		struct HashHelper
//		{
//			std::size_t operator()(T key) const
//			{
//				const auto value = static_cast<std::underlying_type_t<T>>(key);
//				const auto hash = std::hash<std::underlying_type_t<T>>();
//				return hash(value);
//			}
//		};
//	private:
//		GLFWwindow* mWindow;
//		std::unordered_map<Key, std::vector<KeyCallback>, HashHelper<Key>> mKeyCallbacks;
//		std::unordered_map<MouseButton, std::vector<MouseButtonCallback>, HashHelper<MouseButton>> mMouseButtonCallbacks;
//		std::vector<MouseMoveCallback> mMouseMoveCallbacks;
//	};
//}
