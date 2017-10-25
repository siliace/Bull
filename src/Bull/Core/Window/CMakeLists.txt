set(BULL_INC_CORE_WINDOW ${BULL_INC_CORE}/Window)
set(BULL_SRC_CORE_WINDOW ${BULL_SRC_CORE}/Window)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_WINDOW}/Cursor.hpp
            ${BULL_SRC_CORE_WINDOW}/Cursor.cpp
            ${BULL_INC_CORE_WINDOW}/CursorType.hpp
            ${BULL_INC_CORE_WINDOW}/MessageWindow.hpp
            ${BULL_SRC_CORE_WINDOW}/MessageWindow.cpp
            ${BULL_INC_CORE_WINDOW}/MessageWindowButtons.hpp
            ${BULL_INC_CORE_WINDOW}/MessageWindowDefaultButton.hpp
            ${BULL_INC_CORE_WINDOW}/MessageWindowIcon.hpp
            ${BULL_INC_CORE_WINDOW}/MessageWindowResponse.hpp
            ${BULL_INC_CORE_WINDOW}/VideoMode.hpp
            ${BULL_SRC_CORE_WINDOW}/VideoMode.cpp
            ${BULL_INC_CORE_WINDOW}/Window.hpp
            ${BULL_SRC_CORE_WINDOW}/Window.cpp
            ${BULL_INC_CORE_WINDOW}/WindowEvent.hpp
            ${BULL_SRC_CORE_WINDOW}/WindowEvent.cpp
            ${BULL_INC_CORE_WINDOW}/WindowEventType.hpp
            ${BULL_INC_CORE_WINDOW}/WindowStyle.hpp
        PRIVATE
            ${BULL_SRC_CORE_WINDOW}/AbstractInputManager.hpp
            ${BULL_SRC_CORE_WINDOW}/AbstractJoystickManager.hpp
            ${BULL_SRC_CORE_WINDOW}/CursorHandler.hpp
            ${BULL_SRC_CORE_WINDOW}/CursorImpl.hpp
            ${BULL_SRC_CORE_WINDOW}/CursorImpl.cpp
            ${BULL_SRC_CORE_WINDOW}/JoystickManager.hpp
            ${BULL_SRC_CORE_WINDOW}/JoystickManager.cpp
            ${BULL_SRC_CORE_WINDOW}/JoystickState.hpp
            ${BULL_SRC_CORE_WINDOW}/JoystickState.cpp
            ${BULL_SRC_CORE_WINDOW}/MessageWindowImpl.hpp
            ${BULL_SRC_CORE_WINDOW}/VideoModeImpl.hpp
            ${BULL_SRC_CORE_WINDOW}/WindowHandler.hpp
            ${BULL_SRC_CORE_WINDOW}/WindowImpl.hpp
            ${BULL_SRC_CORE_WINDOW}/WindowImpl.cpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
else()
    add_subdirectory(Xlib)
endif()