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
#include "Render/Texture/ImageFormat.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// [DEFINITION]
////////////////////////////////////////////////////////////////////////////////////////////////////

namespace QE
{
	//!
	//!
	//!
	class Image
	{
	public:
		//!
		//! \brief Constructs an Image
		//!
		//! \param[in] data     -   The pixel data
		//! \param[in] width    -   The width of the image
		//! \param[in] height   -   The height of the image
		//! \param[in] depth    -   The depth of the image
		//! \param[in] format   -   The format of the image
		//!
		Image(const std::vector<UInt8>& data, UInt16 width, Uint16 height, UInt16 depth, const ImageFormat& format);
	public:
		//!
		//! \brief Returns the pixel data of the image
		//!
		//! \return The pixel data
		//!
		auto& GetData() const
		{
			return mData;
		}

		//!
		//! \brief Returns the width of the image
		//!
		//! \return The width
		//!
		auto GetWidth() const
		{
			return mWidth;
		}

		//!
		//! \brief Returns the height of the image
		//!
		//! \return The height
		//!
		auto GetHeight() const
		{
			return mHeight;
		}

		//!
		//! \brief Returns the depth of the image
		//!
		//! \return The depth
		//!
		auto GetDepth() const
		{
			return mDepth;
		}

		//!
		//! \brief Returns the format of the image
		//!
		//! \return The image format
		//!
		auto GetFormat() const
		{
			return mFormat;
		}
	private:
		const std::vector<UInt8> mData;
		const UInt16 mWidth;
		const UInt16 mHeight;
		const UInt16 mDepth;
		const ImageFormat mFormat;
	};
}
