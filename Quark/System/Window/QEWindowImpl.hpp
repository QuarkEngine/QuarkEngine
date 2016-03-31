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
		//! Get the underlying GLFW window handle
		//!
		//! \return The GLFW window handle
		//!
		GLFWwindow* GetHandle() const;
	public:
		//!
		//! \inheritDoc
		//!
		Void GetDimension(UInt32& width, UInt32& height) const override;

		//!
		//! \inheritDoc
		//!
		Bool IsVisible() const override;

		//!
		//! \inheritDoc
		//!
		Bool IsResizable() const override;

		//!
		//! \inheritDoc
		//!
		Bool IsDecorated() const override;

		//!
		//! \inheritDoc
		//!
		Bool IsWindowed() const override;

		//!
		//! \inheritDoc
		//!
		Bool IsFullscreen() const override;
	public:
		//!
		//! \inheritDoc
		//!
		Void SetDimension(UInt16 width, UInt16 height) override;

		//!
		//! \inheritDoc
		//!
		Void SetTitle(const String& title) override;

		//!
		//! \inheritDoc
		//!
		Void SetVisibility(Bool visibility) override;

		//!
		//! \inheritDoc
		//!
		Void SwitchToWindowed(UInt16 width, UInt16 height) override;

		//!
		//! \inheritDoc
		//!
		Void SwitchToFullscreen() override;

		//!
		//! \inheritDoc
		//!
		Void SwitchToFullscreen(UInt16 width, UInt16 height) override;
	private:
		GLFWwindow* mWindow;
	};
}

#endif // __QUARK_ENGINE_SYSTEM_WINDOWIMPL_HPP__
