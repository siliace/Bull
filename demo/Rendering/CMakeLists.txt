cmake_minimum_required(VERSION 3.5.0)
project(demo-rendering)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${BULL_ROOT}/include)

link_directories(${BULL_ROOT}/bin/${CMAKE_BUILD_TYPE})

add_executable(demo-rendering include/Camera.hpp include/Cube.hpp src/Camera.cpp src/Cube.cpp src/main.cpp)
target_link_libraries(demo-rendering bull-core)
target_link_libraries(demo-rendering bull-graphics)
target_link_libraries(demo-rendering bull-math)
target_link_libraries(demo-rendering bull-render)
