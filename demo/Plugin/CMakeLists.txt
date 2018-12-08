cmake_minimum_required(VERSION 3.5.0)
project(demo-plugin)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${BULL_ROOT}/include)

link_directories(${BULL_ROOT}/bin/${CMAKE_BUILD_TYPE})

add_library(plugin SHARED src/Plugin.cpp)
set_target_properties(plugin PROPERTIES PREFIX "")
target_compile_definitions(plugin PUBLIC BULL_BUILD_PLUGIN)
target_link_libraries(plugin bull-core)

add_executable(demo-plugin src/main.cpp)
target_link_libraries(demo-plugin bull-core)
