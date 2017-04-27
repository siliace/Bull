cmake_minimum_required(VERSION 3.5.0)
project(test-render-texture)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

include_directories(include)
include_directories(${BULL_ROOT}/include)

link_directories(${BULL_ROOT}/bin/${CMAKE_BUILD_TYPE})

add_executable(bull-test-render-texture src/main.cpp)
target_link_libraries(bull-test-render-texture bull-core)
target_link_libraries(bull-test-render-texture bull-hardware)
target_link_libraries(bull-test-render-texture bull-utility)
target_link_libraries(bull-test-render-texture bull-window)
target_link_libraries(bull-test-render-texture bull-render)


add_test(NAME render-texture COMMAND bull-test-render-texture)