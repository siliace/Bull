add_executable(file-test FileTest.cpp)
target_link_libraries(file-test bull-core)
target_include_directories(file-test PUBLIC "${BULL_ROOT}/test")

enable_testing()
add_test(NAME FileTest COMMAND file-test)