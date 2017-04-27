cmake_minimum_required(VERSION 3.5.0)
project(test-core-functor)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${BULL_ROOT}/include)

link_directories(${BULL_ROOT}/bin/${CMAKE_BUILD_TYPE})

add_executable(bull-test-core-functor src/main.cpp)
target_link_libraries(bull-test-core-functor bull-core)

add_test(NAME core-functor COMMAND bull-test-core-functor)