cmake_minimum_required(VERSION 3.5.0)
project(test-render-context)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

include_directories(include)
include_directories(${BULL_ROOT}/include)

link_directories(${BULL_ROOT}/bin/${CMAKE_BUILD_TYPE})

add_executable(bull-test-render-context src/main.cpp)
target_link_libraries(bull-test-render-context bull-core)
target_link_libraries(bull-test-render-context bull-render-context)

add_test(NAME render-context COMMAND bull-test-render-context)