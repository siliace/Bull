cmake_minimum_required(VERSION 3.5.0)
project(Bull)

include(cmake/Macro.cmake)
include(cmake/Config.cmake)
include(cmake/Platform.cmake)

add_definitions(-DBULL_BUILD)
add_definitions(-DBULL_DYNAMIC)

include_directories(libs/include)
include_directories(include)
include_directories(src)

link_directories(libs/mingw/x64)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

add_subdirectory(demo)
add_subdirectory(src)

enable_testing()
add_subdirectory(test)