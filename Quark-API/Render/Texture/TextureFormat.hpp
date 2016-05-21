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
	//! \brief Encapuslates the texture formats
	//!
	class TextureFormat
	{
	public:
		//!
		//! \brief Constructs a TextureFormat
		//!
		//! \param[in] format	-	The format
		//!
		constexpr TextureFormat(UInt32 format) :
			mFormat(format)
		{
		}
	public:
		//!
		//! \brief Operator-Overload which allows TextureFormat to be implicitly casted to an integral type
		//!
		//! \return The casted integral type
		//!
		template<typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
		constexpr operator T() const
		{
			return static_cast<T>(mFormat);
		}
	public:
		static TextureFormat RED;               // Red normalised-integer/float
		static TextureFormat RED_INT;           // Red integer
		static TextureFormat GREEN;             // Green normalised-integer/float
		static TextureFormat GREEN_INT;         // Green integer
		static TextureFormat BLUE;              // Blue normalised-integer/float
		static TextureFormat BLUE_INT;          // Blue integer
		static TextureFormat RG;                // Red/Green normalised-integer/float
		static TextureFormat RG_INT;            // Red/Green integer
		static TextureFormat RGB;               // Red/Green/Blue normalised-integer/float
		static TextureFormat RGB_INT;           // Red/Green/Blue integer
		static TextureFormat BGR;               // Blue/Green/Red normalised-integer/float
		static TextureFormat BGR_INT;           // Blue/Green/Red integer
		static TextureFormat RGBA;              // Red/Green/Blue/Alpha normalised-integer/float
		static TextureFormat RGBA_INT;          // Red/Green/Blue/Alpha integer
		static TextureFormat BGRA;              // Blue/Green/Red/Alpha normalised-integer/float
		static TextureFormat BGRA_INT;          // Blue/Green/Red/Alpha integer
		static TextureFormat DEPTH;             // Depth
		static TextureFormat STENCIL;           // Stencil
		static TextureFormat DEPTH_STENCIL;     // Depth/Stencil
		static TextureFormat COMPRESSED_RED;    // Compressed Red
		static TextureFormat COMPRESSED_RG;     // Compressed Red/Green
		static TextureFormat COMPRESSED_RGB;    // Compressed Red/Green/Blue
		static TextureFormat COMPRESSED_RGBA;   // Compressed Red/Green/Blue/Alpha
	private:
		const UInt32 mFormat;
	};
}
