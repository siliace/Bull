cmake_minimum_required(VERSION 3.5.0)
project(test-render-shader)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

include_directories(include)
include_directories(${BULL_ROOT}/include)

link_directories(${BULL_ROOT}/bin/${CMAKE_BUILD_TYPE})

add_executable(bull-test-render-shader src/main.cpp)
target_link_libraries(bull-test-render-shader bull-core)
target_link_libraries(bull-test-render-shader bull-hardware)
target_link_libraries(bull-test-render-shader bull-utility)
target_link_libraries(bull-test-render-shader bull-window)
target_link_libraries(bull-test-render-shader bull-render)

add_test(NAME render-shader COMMAND bull-test-render-shader)