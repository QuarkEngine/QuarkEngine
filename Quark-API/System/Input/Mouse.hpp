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
#include "QuarkAPI.hpp"
#include "Util/HashHelper.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// [DEFINITION]
////////////////////////////////////////////////////////////////////////////////////////////////////

namespace QE
{
	//!
	//! \brief Enumeration of the supported mouse buttons
	//!
	enum class MouseButton : UInt8
	{
		BUTTON_1 = 0,
		BUTTON_2 = 1,
		BUTTON_3 = 2,
		BUTTON_4 = 3,
		BUTTON_5 = 4,
		BUTTON_6 = 5,
		BUTTON_7 = 6,
		BUTTON_8 = 7,
		BUTTON_LEFT = BUTTON_1,
		BUTTON_RIGHT = BUTTON_2,
		BUTTON_MIDDLE = BUTTON_3
	};
}
