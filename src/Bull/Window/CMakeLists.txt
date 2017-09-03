set(BULL_INC_WINDOW ${BULL_INC}/Window)
set(BULL_SRC_WINDOW ${BULL_SRC}/Window)

bull_add_library(bull-window)

target_sources(bull-window
        PUBLIC
            ${BULL_INC_WINDOW}/Export.hpp
            ${BULL_INC_WINDOW}/Cursor.hpp
            ${BULL_SRC_WINDOW}/Cursor.cpp
            ${BULL_INC_WINDOW}/VideoMode.hpp
            ${BULL_SRC_WINDOW}/VideoMode.cpp
            ${BULL_INC_WINDOW}/Window.hpp
            ${BULL_SRC_WINDOW}/Window.cpp
            ${BULL_INC_WINDOW}/WindowEvent.hpp
            ${BULL_INC_WINDOW}/WindowStyle.hpp
        PRIVATE
            ${BULL_SRC_WINDOW}/CursorHandler.hpp
            ${BULL_SRC_WINDOW}/CursorImpl.cpp
            ${BULL_SRC_WINDOW}/CursorImpl.hpp
            ${BULL_SRC_WINDOW}/JoystickManager.cpp
            ${BULL_SRC_WINDOW}/JoystickManager.hpp
            ${BULL_SRC_WINDOW}/JoystickState.cpp
            ${BULL_SRC_WINDOW}/JoystickState.hpp
            ${BULL_SRC_WINDOW}/VideoModeImpl.hpp
            ${BULL_SRC_WINDOW}/WindowHandler.hpp
            ${BULL_SRC_WINDOW}/WindowImpl.cpp
            ${BULL_SRC_WINDOW}/WindowImpl.hpp
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