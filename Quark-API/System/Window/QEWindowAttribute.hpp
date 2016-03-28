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
#ifndef __QUARK_ENGINE_SYSTEM_WINDOW_ATTRIBUTE_HPP__
#define __QUARK_ENGINE_SYSTEM_WINDOW_ATTRIBUTE_HPP__

////////////////////////////////////////////////////////////////////////////////////////////////////
/// [HEADER]
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Platform/QEPlatform.hpp"
#include "Platform/QEPlatformRTTI.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// [DEFINITION]
////////////////////////////////////////////////////////////////////////////////////////////////////
namespace QE
{
    //!
    //! \brief Enumerate possible attribute(s) for a windowed \see QE::Window
    //!
    enum class WindowAttribute : UInt8
    {
        WINDOWED_BORDERLESS = 0x00,  //!< Specifies if the \see QE::Window doesn't have decoration.
        WINDOWED_RESIZABLE  = 0x01,  //!< Specifies if the \see QE::Window will be resizable
        WINDOWED_DECORATED  = 0x02   //!< Specifies if the \see QE::Window will be decorated
    };

    //!
    //! \brief Allows \see QE::WindowAttribute to be used as flag
    //!
    TRAIT_ENUM_ALLOW_BIT_OPERATION(WindowAttribute);
}

#endif // __QUARK_ENGINE_SYSTEM_WINDOW_ATTRIBUTE_HPP__