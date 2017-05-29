cmake_minimum_required(VERSION 3.5.0)
project(demo-filesystem)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${BULL_ROOT}/include)

link_directories(${BULL_ROOT}/bin/${CMAKE_BUILD_TYPE})

add_executable(demo-filesystem src/main.cpp)
target_link_libraries(demo-filesystem bull-core)
target_link_libraries(demo-filesystem bull-hardware)
target_link_libraries(demo-filesystem bull-render)
target_link_libraries(demo-filesystem bull-utility)
target_link_libraries(demo-filesystem bull-window)