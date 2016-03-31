CMAKE_MINIMUM_REQUIRED(VERSION 3.0 FATAL_ERROR)

####################################################################################################
## [C++::PROJECT]
####################################################################################################
PROJECT(QuarkEngine CXX)

####################################################################################################
## [C++::FLAGS]
####################################################################################################
IF (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    ##
    ## (Requires C++14)
    ##
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
ENDIF ()

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
## [DEPENDENCY::GLFW3]
####################################################################################################
SET(GLFW_STATIC_LIBRARY glfw)
SET(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Build the GLFW example programs")
SET(GLFW_BUILD_TESTS    OFF CACHE BOOL "Build the GLFW test programs")
SET(GLFW_BUILD_DOCS     OFF CACHE BOOL "Build the GLFW documentation")
SET(GLFW_INSTALL        OFF CACHE BOOL "Generate installation target")
ADD_SUBDIRECTORY("${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLFW")
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLFW/include")

####################################################################################################
## [C++::SOURCE]
####################################################################################################
FILE(GLOB_RECURSE SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/Quark/*.cpp")

####################################################################################################
## [C++::EXECUTABLE]
####################################################################################################
ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCE_FILES})

####################################################################################################
## [C++::LIBRARIES]
####################################################################################################
TARGET_LINK_LIBRARIES(${PROJECT_NAME} PRIVATE ${GLFW_STATIC_LIBRARY})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} PRIVATE ${GLFW_LIBRARIES})
