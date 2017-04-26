add_library(bull-core SHARED "")

add_subdirectory(FileSystem)
add_subdirectory(IO)
add_subdirectory(Log)
add_subdirectory(Memory)
add_subdirectory(System)
add_subdirectory(Thread)
add_subdirectory(Time)

target_link_libraries(bull-core pthread)
target_link_libraries(bull-core dl)