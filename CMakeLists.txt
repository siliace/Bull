CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
PROJECT(Bull)

include(cmake/Config.cmake)
include(cmake/Macro.cmake)

add_definitions(-DBULL_BUILD)
add_definitions(-DBULL_DYNAMIC)

include_directories(libs/include)
include_directories(include)
include_directories(src)

set(BULL_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(BULL_INCLUDE ${BULL_ROOT}/include/Bull)
set(BULL_SRC ${BULL_ROOT}/src/Bull)

link_directories(libs)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_ROOT}/libs)

add_subdirectory(src/Bull/Core)
add_subdirectory(src/Bull/Hardware)
add_subdirectory(src/Bull/Render)
add_subdirectory(src/Bull/Network)
add_subdirectory(src/Bull/Utility)
add_subdirectory(src/Bull/Window)