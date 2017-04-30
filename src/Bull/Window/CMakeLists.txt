add_library(bull-window SHARED "")

target_sources(bull-window
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/Window.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/VideoMode.cpp
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/JoystickManager.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/JoystickManager.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/JoystickState.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/JoystickState.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/VideoModeImpl.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/WindowImpl.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/WindowImpl.hpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
else()
    add_subdirectory(X11)
    target_link_libraries(bull-window X11)
    target_link_libraries(bull-window Xrandr)
endif()

target_link_libraries(bull-window bull-core)
target_link_libraries(bull-window bull-hardware)