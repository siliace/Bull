cmake_minimum_required(VERSION 3.5.0)
project(test-core-fs)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${BULL_ROOT}/include)

link_directories(${BULL_ROOT}/bin/${CMAKE_BUILD_TYPE})

add_executable(test-core-fs src/main.cpp)
target_link_libraries(test-core-fs bull-core)