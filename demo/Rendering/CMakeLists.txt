set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories(${PROJECT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

add_executable(demo-rendering src/main.cpp)
target_link_libraries(demo-rendering bull-core)
target_link_libraries(demo-rendering bull-hardware)
target_link_libraries(demo-rendering bull-network)
target_link_libraries(demo-rendering bull-render)
target_link_libraries(demo-rendering bull-utility)
target_link_libraries(demo-rendering bull-window)