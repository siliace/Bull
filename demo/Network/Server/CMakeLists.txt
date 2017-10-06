cmake_minimum_required(VERSION 3.5.0)
project(demo-network-server)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${BULL_ROOT}/include)

link_directories(${BULL_ROOT}/bin/${CMAKE_BUILD_TYPE})

add_executable(demo-network-server src/main.cpp)
target_link_libraries(demo-network-server bull-core)
target_link_libraries(demo-network-server bull-network)
