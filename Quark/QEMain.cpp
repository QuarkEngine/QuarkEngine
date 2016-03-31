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

////////////////////////////////////////////////////////////////////////////////////////////////////
/// [MODULE::HEADER]
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <Platform/QEPlatform.hpp>
#include "System/Window/QEWindowImpl.hpp"

QE::Int32 main()
{
	// Create a test window
	auto window = new QE::WindowImpl();

	if (window->Create("Quark Engine", 0, 0, 800, 600, QE::WindowAttribute::RESIZEABLE))
	{
		return EXIT_SUCCESS;
	}

    return EXIT_FAILURE;
}
