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
	//! \brief Encapuslates the image formats
	//!
	class ImageFormat
	{
	public:
		//!
		//! \brief Constructs an ImageFormat
		//!
		//! \param[in] format	-	The format
		//!
		constexpr ImageFormat(UInt32 format) :
			mFormat(format)
		{
		}
	public:
		//!
		//! \brief Operator-Overload which allows ImageFormat to be implicitly casted to an integral type
		//!
		//! \return The casted integral type
		//!
		template<typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
		constexpr operator T() const
		{
			return static_cast<T>(mFormat);
		}
	public:
		static ImageFormat R8;                // 8bit 1-channel
		static ImageFormat R8_SNORM;          // 8bit signed-normalised 1-channel
		static ImageFormat R8I;               // 8bit integer 1-channel
		static ImageFormat R8UI;              // 8bit unsigned integer 1-channel

		static ImageFormat R16;               // 16bit 1-channel
		static ImageFormat R16_SNORM;         // 16bit signed-normalised 1-channel
		static ImageFormat R16I;              // 16bit integer 1-channel
		static ImageFormat R16UI;             // 16bit unsigned integer 1-channel
		static ImageFormat R16F;              // 16bit float 1-channel

		static ImageFormat R32I;              // 32bit integer 1-channel
		static ImageFormat R32UI;             // 32bit unsigned integer 1-channel
		static ImageFormat R32F;              // 32bit float 1-channel

		static ImageFormat RG8;               // 8bit 2-channel
		static ImageFormat RG8_SNORM;         // 8bit signed normalised 2-channel
		static ImageFormat RG8I;              // 8bit integer 2-channel
		static ImageFormat RG8UI;             // 8bit unsigned integer 2-channel

		static ImageFormat RG16;              // 16bit 2-channel
		static ImageFormat RG16_SNORM;        // 16bit signed-normalised 2-channel
		static ImageFormat RG16I;             // 16bit integer 2-channel
		static ImageFormat RG16UI;            // 16bit unsigned integer 2-channel
		static ImageFormat RG16F;             // 16bit float 2-channel

		static ImageFormat RG32I;             // 32bit integer 2-channel
		static ImageFormat RG32UI;            // 32bit unsigned integer 2-channel
		static ImageFormat RG32F;             // 32bit float 2-channel

		static ImageFormat R3_G3_B2;          // 3bit red, green 2bit blue 3-channel
		static ImageFormat RGB4;              // 4bit 3-channel
		static ImageFormat RGB5;              // 5bit 3-channel
		static ImageFormat RGB8;              // 8bit 3-channel
		static ImageFormat RGB8_SNORM;        // 8bit signed normalised 3-channel
		static ImageFormat RGB9_E5;           // 9bit red, green, blue 5bit shared-exponent 3-channel
		static ImageFormat RGB10;             // 10bit 3-channel
		static ImageFormat RGB12;             // 12bit 3-channel
		static ImageFormat RGB16_SNORM;       // 16bit signed-normalised 3-channel
		static ImageFormat RGB8I;             // 8bit integer 3-channel
		static ImageFormat RGB8UI;            // 8bit unsigned integer 3-channel
		static ImageFormat RGB16I;            // 16bit integer 3-channel
		static ImageFormat RGB16UI;           // 16bit unsigned integer 3-channel
		static ImageFormat RGB32I;            // 32bit integer 3-channel
		static ImageFormat RGB32UI;           // 32bit unsigned integer 3-channel
		static ImageFormat R11F_G11F_B10F;    // 11bit float red, green 10bit float blue 3-channel
		static ImageFormat RGB16F;            // 16bit float 3-channel
		static ImageFormat RGB32F;            // 32bit float 3-channel

		static ImageFormat RGBA2;             // 2bit 4-channel
		static ImageFormat RGBA4;             // 4bit 4-channel
		static ImageFormat RGB5_A1;           // 5bit red, green, blue 1bit alpha 4-channel
		static ImageFormat RGBA8;             // 8bit 4-channel
		static ImageFormat RGBA8_SNORM;       // 8bit signed-normalised 4-channel
		static ImageFormat RGB10_A2;          // 10bit red, green, blue 2bit alpha 4-channel
		static ImageFormat RGB10_A2UI;        // 10bit red, green, blue 2bit unsigned integer alpha 4-channel
		static ImageFormat RGBA12;            // 12bit 4-channel
		static ImageFormat RGBA16;            // 16bit 4-channel
		static ImageFormat RGBA8I;            // 8bit integer 4-channel
		static ImageFormat RGBA8UI;           // 8bit unsigned integer 4-channel
		static ImageFormat RGBA16I;           // 16bit integer 4-channel
		static ImageFormat RGBA16UI;          // 16bit unsigned integer 4-channel
		static ImageFormat RGBA32I;           // 32bit integer 4-channel
		static ImageFormat RGBA32UI;          // 32bit unsigned integer 4-channel
		static ImageFormat RGBA16F;           // 16bit float 4-channel
		static ImageFormat RGBA32F;           // 32bit float 4-channel

		static ImageFormat SRGB8;             // 8bit SRGB 3-channel
		static ImageFormat SRGB8_ALPHA8;      // 8bit SRGB 4-channel

		static ImageFormat DEPTH16;           // 16bit depth
		static ImageFormat DEPTH24;           // 24bit depth
		static ImageFormat DEPTH32;           // 32bit depth
		static ImageFormat DEPTH32F;          // 32bit depth float
		static ImageFormat DEPTH24_STENCIL8;  // 24bit depth 8bit stencil
		static ImageFormat DEPTH32F_STENCIL8; // 32bit depth float 8bit stencil
		static ImageFormat STENCIL8;          // 8bit stencil

		static ImageFormat COMPRESSED_RGB_DXT1;             // Compressed RGB DXT1
		static ImageFormat COMPRESSED_SRGB_DXT1;            // Compressed sRGB DXT1
		static ImageFormat COMPRESSED_RGBA_DXT1;            // Compressed RGBA DXT1
		static ImageFormat COMPRESSED_SRGB_ALPHA_DXT1;      // Compressed sRGB+Alpha DXT1
		static ImageFormat COMPRESSED_RGBA_DXT3;            // Compresed RGBA DXT3
		static ImageFormat COMPRESSED_SRGB_ALPHA_DXT3;      // Compressed sRGB+Alpha DXT3
		static ImageFormat COMPRESSED_RGBA_DXT5;            // Compressed RGBA DXT5
		static ImageFormat COMPRESSED_SRGB_ALPHA_DXT5;      // Compressed sRGB+Alpha DXT5
	private:
		const UInt32 mFormat;
	};
}
