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
#ifndef __QUARK_ENGINE_MEDIA_WINDOW_HPP__
#define __QUARK_ENGINE_MEDIA_WINDOW_HPP__

////////////////////////////////////////////////////////////////////////////////////////////////////
/// [MODULE::HEADER]
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "QEWindowAttribute.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// [MODULE::DEFINITION]
////////////////////////////////////////////////////////////////////////////////////////////////////
namespace QE
{
    //!
    //! \brief Encapsulate the base definition of a window
    //!
    class Window
    {
    public:
        //!
        //! \brief Get the width of the window (in screen coordinates)
        //!
        //! \return The width of the window (in screen coordinates)
        //!
        virtual UInt16 GetWidth() const = 0;

        //!
        //! \brief Get the height of the window (in screen coordinates)
        //!
        //! \return The height of the window (in screen coordinates)
        //!
        virtual UInt16 GetHeight() const = 0;

        //!
        //! \brief Check whenever the window is visible
        //!
        //! \return True if the window is visible, false otherwise
        //!
        virtual Bool IsVisible() const = 0;

        //!
        //! \brief Check whenever the window is resizable (windowed mode)
        //!
        //! \return True if the window is resizable, false otherwise
        //!
        virtual Bool IsResizable() const = 0;

        //!
        //! \brief Check whenever the window is decorated (windowed mode)
        //!
        //! \return True if the window is decorated, false otherwise
        //!
        virtual Bool IsDecorated() const = 0;

        //!
        //! \brief Check whenever the window is in windowed mode
        //!
        //! \return True if the window is in windowed mode, false otherwise
        //!
        virtual Bool IsWindowed() const = 0;

        //!
        //! \brief Check whenever the window is in fullscreen mode
        //!
        //! \return True if the window is in fullscreen mode, false otherwise
        //!
        virtual Bool IsFullscreen() const = 0;

        //!
        //! \brief Check whenever the window is open
        //!
        //! \return True if the window is open, false otherwise
        //!
        virtual Bool IsOpen() const = 0;

        //!
        //! \brief Check whenever the window is closed
        //!
        //! \return True if the window is closed, false otherwise
        //!
        virtual Bool IsClosed() const = 0;

    public:
        //!
        //! \brief Changes the size of the window
        //!
        //! \param[in] width    -   The new width (in screen coordinates)
        //! \param[in] height   -   The new height (in screen coordinates)
        //!
        virtual Void SetDimension(UInt16 width, UInt16 height) = 0;

        //!
        //! \brief Changes the title of the window
        //!
        //! \param[in] title    -   The new title of the window
        //!
        virtual Void SetTitle(const String & title) = 0;

        //!
        //! \brief Change the visibility of the window (Only applicable for windowed mode)
        //!
        //! \param[in] visibility   -   True to show the window, false otherwise
        //!
        virtual Void SetVisibility(Bool visibility) = 0;

        //!
        //! \brief Change the current mode of the window to windowed mode
        //!
        //! \param[in] width    -   The new width (in screen coordinates)
        //! \param[in] height   -   The new height (in screen coordinates)
        //! \param[in] mode     -   The decoration mode of the window
        //!
        virtual Void SwitchToWindowed(UInt16 width, UInt16 height, WindowAttribute mode) = 0;

        //!
        //! \brief Change the current mode of the window to fullscreen mode
        //!
        virtual Void SwitchToFullscreen() = 0;

        //!
        //! \brief Change the current mode of the window to fullscreen mode
        //!
        //! \param[in] width    -   The new width (in screen coordinates)
        //! \param[in] height   -   The new height (in screen coordinates)
        //!
        virtual Void SwitchToFullscreen(UInt16 width, UInt16 height) = 0;
    };
}

#endif // __QUARK_ENGINE_MEDIA_WINDOW_HPP__