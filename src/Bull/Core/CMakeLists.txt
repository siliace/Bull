set(BULL_INC_CORE ${BULL_INC}/Core)
set(BULL_SRC_CORE ${BULL_SRC}/Core)

bull_add_library(bull-core)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE}/Export.hpp
        )

add_subdirectory(Configuration)
add_subdirectory(Exception)
add_subdirectory(FileSystem)
add_subdirectory(Functor)
add_subdirectory(Hardware)
add_subdirectory(Image)
add_subdirectory(IO)
add_subdirectory(Log)
add_subdirectory(Memory)
add_subdirectory(Pattern)
add_subdirectory(Process)
add_subdirectory(Resource)
add_subdirectory(Support)
add_subdirectory(System)
add_subdirectory(Thread)
add_subdirectory(Time)
add_subdirectory(Utility)
add_subdirectory(Window)

if(BULL_OS_WINDOWS)
    target_link_libraries(bull-core winmm)
else()
    target_link_libraries(bull-core dl)
    target_link_libraries(bull-core X11)
    target_link_libraries(bull-core Xrandr)
    target_link_libraries(bull-core pthread)
endif()

target_link_libraries(bull-core stbimage)