set(BULL_INC_CORE ${BULL_INC}/Core)
set(BULL_SRC_CORE ${BULL_SRC}/Core)

bull_add_library(bull-core)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE}/Export.hpp
        )

add_subdirectory(Assets)
add_subdirectory(Configuration)
add_subdirectory(Exception)
add_subdirectory(FileSystem)
add_subdirectory(Hardware)
add_subdirectory(Image)
add_subdirectory(IO)
add_subdirectory(Log)
add_subdirectory(Memory)
add_subdirectory(Pattern)
add_subdirectory(Support)
add_subdirectory(System)
add_subdirectory(Time)
add_subdirectory(Utility)
add_subdirectory(Window)

if(BULL_OS_WINDOWS)
    target_link_libraries(bull-core winmm)
else()
    find_package(X11 REQUIRED)

    target_link_libraries(bull-core dl)
    target_link_libraries(bull-core pthread)
    target_link_libraries(bull-core ${X11_X11_LIB})
    target_link_libraries(bull-core ${X11_Xrandr_LIB})
endif()

target_link_libraries(bull-core stbimage)