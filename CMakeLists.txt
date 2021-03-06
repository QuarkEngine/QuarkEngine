CMAKE_MINIMUM_REQUIRED(VERSION 3.0 FATAL_ERROR)

####################################################################################################
## [C++::FLAGS]
####################################################################################################
IF(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fno-rtti")
ELSEIF(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fno-rtti")
ENDIF()

####################################################################################################
## [C++::OUTPUT]
####################################################################################################
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Build)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Build)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Build)

####################################################################################################
## [DEPENDENCY::INCLUDE]
####################################################################################################
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/Quark-API")

####################################################################################################
## [C++::SOURCE]
####################################################################################################
ADD_SUBDIRECTORY("${CMAKE_CURRENT_SOURCE_DIR}/Quark-Core/Common")

IF (${CMAKE_SYSTEM_NAME} STREQUAL Windows)
	ADD_SUBDIRECTORY("${CMAKE_CURRENT_SOURCE_DIR}/Quark-Core/Windows")
ELSEIF (${CMAKE_SYSTEM_NAME} STREQUAL Linux)
	ADD_SUBDIRECTORY("${CMAKE_CURRENT_SOURCE_DIR}/Quark-Core/Linux")
ENDIF ()
