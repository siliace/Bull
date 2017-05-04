cmake_minimum_required(VERSION 3.5.0)
project(Bull)

option(BUILD_SHARED_LIBS "Build Shared Libraries" OFF)

include(cmake/Macro.cmake)
include(cmake/Config.cmake)
include(cmake/Platform.cmake)

add_definitions(-DBULL_BUILD)
add_definitions(-DBULL_DYNAMIC)

if(BULL_OS_WINDOWS)
    add_definitions(-DBULL_BUILD_WINDOWS_8)
endif()

include_directories(libs/include)
include_directories(include)
include_directories(src)

if(BULL_OS_WINDOWS)
    link_directories(libs/Windows/x64)
else()
    link_directories(libs/Unix/x64)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

add_subdirectory(demo)
add_subdirectory(src)