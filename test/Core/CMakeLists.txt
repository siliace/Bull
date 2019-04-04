add_executable(bull-core-test main.cpp)

add_subdirectory(FileSystem)
add_subdirectory(Utility)
add_subdirectory(Window)

target_link_libraries(bull-core-test bull-core)

add_test(NAME Core COMMAND bull-core-test)