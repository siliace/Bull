bull_add_library(bull-window)

target_sources(bull-window
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/Cursor.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Window.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/VideoMode.cpp
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/CursorHandler.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CursorImpl.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CursorImpl.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/JoystickManager.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/JoystickManager.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/JoystickState.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/JoystickState.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/VideoModeImpl.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/WindowHandler.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/WindowImpl.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/WindowImpl.hpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
else()
    if(WINDOW_LIBRARY STREQUAL "BULL_BUILD_XLIB")
        add_subdirectory(Xlib)
        target_link_libraries(bull-window X11)
        target_link_libraries(bull-window Xrandr)
    elseif(WINDOW_LIBRARY STREQUAL "BULL_BUILD_XCB")
        add_subdirectory(XCB)
        target_link_libraries(bull-window xcb)
    elseif(WINDOW_LIBRARY STREQUAL "BULL_BUILD_WEYLAND")
        add_subdirectory(Weyland)
    endif()
endif()

target_link_libraries(bull-window bull-core)
target_link_libraries(bull-window bull-hardware)
target_link_libraries(bull-window bull-utility)