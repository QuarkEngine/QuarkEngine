//#include "QEInputManager.hpp"
//
//namespace QE
//{
//	Void QEInputManager::Initialise(GLFWwindow* window)
//	{
//		// Set the window
//		mWindow = window;
//
//		// Set the input callbacks
//		glfwSetKeyCallback(window, &HandleKeyInput);
//	}
//
//	Void QEInputManager::PollInput()
//	{
//		glfwPollEvents();
//	}
//
//	Bool QEInputManager::IsKeyPressed(Key key) const
//	{
//		// Get the state of the key
//		const auto keyState = glfwGetKey(mWindow, static_cast<UInt16>(key));
//		return keyState == GLFW_PRESS;
//	}
//
//	Void QEInputManager::RegisterKeyCallback(Key key, KeyCallback callback)
//	{
//		// Check if a callback has already been registered for this key
//		const auto iter = mKeyCallbacks.find(key);
//		if (iter != mKeyCallbacks.end())
//		{
//			// Add the callback to the vector
//			iter->second.emplace_back(callback);
//		}
//		else
//		{
//			// Create a new vector to store the callbacks in
//			std::vector<KeyCallback> callbacks = { callback };
//
//			// Store the new vector in the map
//			mKeyCallbacks.emplace(key, callbacks);
//		}
//	}
//
//	Void QEInputManager::RegisterMouseButtonCallback(MouseButton button, MouseButtonCallback callback)
//	{
//		// Check if a callback has already been registered for this mouse button
//		const auto iter = mMouseButtonCallbacks.find(button);
//		if (iter != mMouseButtonCallbacks.end())
//		{
//			// Add the callback to the vector
//			iter->second.emplace_back(callback);
//		}
//		else
//		{
//			// Create a new vector to store the callbacks in
//			std::vector<MouseButtonCallback> callbacks = { callback };
//
//			// Store the new vector in the map
//			mMouseButtonCallbacks.emplace(button, callbacks);
//		}
//	}
//
//	Void QEInputManager::RegisterMouseMoveCallback(MouseMoveCallback callback)
//	{
//		// Store the callback in the vector
//		mMouseMoveCallbacks.emplace_back(callback);
//	}
//
//	Void QEInputManager::HandleKeyInput(GLFWwindow* window, int key, int scancode, int action, int mods)
//	{
//		// Get the window userdata which contains the address of the input manager instance
//		const auto inputManager = static_cast<QEInputManager*>(glfwGetWindowUserPointer(window));
//
//		// Get the callbacks associated with the the key which was pressed
//		const auto& callbacks = inputManager->mKeyCallbacks;
//		const auto iter = callbacks.find(static_cast<Key>(key));
//		if (iter != callbacks.end())
//		{
//			// Convert the key action to the key state enum
//			const auto state = (action == GLFW_PRESS) ? KeyState::PRESSED : KeyState::RELEASED;
//			// Convert the modifiers to the key modifier enum
//			const auto modifiers = static_cast<KeyModifier>(mods);
//
//			// Invoke the callbacks
//			for (const auto& callback : iter->second)
//			{
//				callback(state, modifiers);
//			}
//		}
//	}
//}
//
//
