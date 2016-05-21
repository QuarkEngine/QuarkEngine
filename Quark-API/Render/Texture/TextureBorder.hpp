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

////////////////////////////////////////////////////////////////////////////////////////////////////
/// [DEFINITION]
////////////////////////////////////////////////////////////////////////////////////////////////////

namespace QE
{
	//!
	//! \brief Encapuslates the texture border address modes
	//!
	class TextureBorder
	{
	public:
		//!
		//! \brief Constructs a TextureBorder
		//!
		//! \param[in] mode	-	The border mode
		//!
		constexpr TextureBorder(UInt32 mode) :
			mMode(mode)
		{
		}
	public:
		//!
		//! \brief Operator-Overload which allows TextureBorder to be implicitly casted to an integral type
		//!
		//! \return The casted integral type
		//!
		template<typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
		constexpr operator T() const
		{
			return static_cast<T>(mMode);
		}
	public:
		static TextureBorder REPEAT;
		static TextureBorder MIRRORED;
		static TextureBorder MIRRORED_REPEAT;
		static TextureBorder CLAMP_TO_BORDER;
		static TextureBorder CLAMP_TO_EDGE;
	private:
		const UInt32 mMode;
	};
}
