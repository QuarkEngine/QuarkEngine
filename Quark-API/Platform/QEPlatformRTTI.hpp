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
#ifndef __QUARK_ENGINE_PLATFORM_RTTI_HPP__
#define __QUARK_ENGINE_PLATFORM_RTTI_HPP__

////////////////////////////////////////////////////////////////////////////////////////////////////
/// [HEADER]
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <type_traits>
#include <typeinfo>

////////////////////////////////////////////////////////////////////////////////////////////////////
/// [DEFINITION]
////////////////////////////////////////////////////////////////////////////////////////////////////
namespace QE
{
    ////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Allow scoped enumeration to be used with bit operation(s).
    ////////////////////////////////////////////////////////////////////////////////////////////////
#   define TRAIT_ENUM_ALLOW_BIT_OPERATION(type)                                                \
        constexpr type operator&(type l, type r)                                               \
        {                                                                                      \
            const auto lType = std::underlying_type_t<type>(l);                                \
            const auto rType = std::underlying_type_t<type>(r);                                \
            return static_cast<type>(lType & rType);                                           \
        }                                                                                      \
        constexpr type operator|(type l, type r)                                               \
        {                                                                                      \
            const auto lType = std::underlying_type_t<type>(l);                                \
            const auto rType = std::underlying_type_t<type>(r);                                \
            return static_cast<type>(lType | rType);                                           \
        }                                                                                      \
        constexpr type operator~(type l)                                                       \
        {                                                                                      \
            const auto lType = std::underlying_type_t<type>(l);                                \
            return static_cast<type>(~lType);                                                  \
        }                                                                                      \
        constexpr type operator^(type l, type r)                                               \
        {                                                                                      \
            const auto lType = std::underlying_type_t<type>(l);                                \
            const auto rType = std::underlying_type_t<type>(r);                                \
            return static_cast<type>(lType ^ rType);                                           \
        }
}

#endif // __QUARK_ENGINE_PLATFORM_RTTI_HPP__
