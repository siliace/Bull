set(BULL_INC_SYSTEM ${BULL_INC}/System)
set(BULL_SRC_SYSTEM ${BULL_SRC}/System)

bull_add_library(bull-system)

target_sources(bull-system
        PUBLIC
            ${BULL_INC_SYSTEM}/Clipboard.hpp
            ${BULL_SRC_SYSTEM}/Clipboard.cpp
            ${BULL_INC_SYSTEM}/CPU.hpp
            ${BULL_SRC_SYSTEM}/CPU.cpp
            ${BULL_INC_SYSTEM}/Cursor.hpp
            ${BULL_SRC_SYSTEM}/Cursor.cpp
            ${BULL_INC_SYSTEM}/Export.hpp
            ${BULL_INC_SYSTEM}/Joystick.hpp
            ${BULL_SRC_SYSTEM}/Joystick.cpp
            ${BULL_INC_SYSTEM}/Keyboard.hpp
            ${BULL_SRC_SYSTEM}/Keyboard.cpp
            ${BULL_INC_SYSTEM}/Library.hpp
            ${BULL_SRC_SYSTEM}/Library.cpp
            ${BULL_INC_SYSTEM}/Mouse.hpp
            ${BULL_SRC_SYSTEM}/Mouse.cpp
            ${BULL_INC_SYSTEM}/Process.hpp
            ${BULL_SRC_SYSTEM}/Process.cpp
            ${BULL_INC_SYSTEM}/RAM.hpp
            ${BULL_SRC_SYSTEM}/RAM.cpp
            ${BULL_INC_SYSTEM}/VideoMode.hpp
            ${BULL_SRC_SYSTEM}/VideoMode.cpp
            ${BULL_INC_SYSTEM}/Window.hpp
            ${BULL_SRC_SYSTEM}/Window.cpp
            ${BULL_INC_SYSTEM}/WindowEvent.hpp
            ${BULL_SRC_SYSTEM}/WindowEvent.cpp
            ${BULL_INC_SYSTEM}/WindowStyle.hpp
        PRIVATE
            ${BULL_SRC_SYSTEM}/AbstractInputManager.hpp
            ${BULL_SRC_SYSTEM}/AbstractJoystickManager.hpp
            ${BULL_SRC_SYSTEM}/ClipboardImpl.hpp
            ${BULL_SRC_SYSTEM}/CPUImpl.hpp
            ${BULL_SRC_SYSTEM}/CursorHandler.hpp
            ${BULL_SRC_SYSTEM}/CursorImpl.hpp
            ${BULL_SRC_SYSTEM}/CursorImpl.cpp
            ${BULL_SRC_SYSTEM}/JoystickImpl.hpp
            ${BULL_SRC_SYSTEM}/JoystickManager.hpp
            ${BULL_SRC_SYSTEM}/JoystickManager.cpp
            ${BULL_SRC_SYSTEM}/KeyboardImpl.hpp
            ${BULL_SRC_SYSTEM}/LibraryImpl.hpp
            ${BULL_SRC_SYSTEM}/LibraryImpl.cpp
            ${BULL_SRC_SYSTEM}/MouseImpl.hpp
            ${BULL_SRC_SYSTEM}/ProcessImpl.hpp
            ${BULL_SRC_SYSTEM}/ProcessImpl.cpp
            ${BULL_SRC_SYSTEM}/RAMImpl.hpp
            ${BULL_SRC_SYSTEM}/JoystickState.hpp
            ${BULL_SRC_SYSTEM}/JoystickState.cpp
            ${BULL_SRC_SYSTEM}/VideoModeImpl.hpp
            ${BULL_SRC_SYSTEM}/WindowHandler.hpp
            ${BULL_SRC_SYSTEM}/WindowImpl.hpp
            ${BULL_SRC_SYSTEM}/WindowImpl.cpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)

    target_link_libraries(bull-system winmm)
else()
    add_subdirectory(Xlib)
    add_subdirectory(Unix)

    target_link_libraries(bull-system dl)
    target_link_libraries(bull-system X11)
    target_link_libraries(bull-system Xrandr)
endif()

target_link_libraries(bull-system bull-core)
target_link_libraries(bull-system bull-utility)