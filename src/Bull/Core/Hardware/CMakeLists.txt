set(BULL_INC_CORE_HARDWARE ${BULL_INC_CORE}/Hardware)
set(BULL_SRC_CORE_HARDWARE ${BULL_SRC_CORE}/Hardware)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_HARDWARE}/CPU.hpp
            ${BULL_SRC_CORE_HARDWARE}/CPU.cpp
            ${BULL_INC_CORE_HARDWARE}/CPUArchitecture.hpp
            ${BULL_INC_CORE_HARDWARE}/Joystick.hpp
            ${BULL_SRC_CORE_HARDWARE}/Joystick.cpp
            ${BULL_INC_CORE_HARDWARE}/JoystickAxis.hpp
            ${BULL_INC_CORE_HARDWARE}/Keyboard.hpp
            ${BULL_SRC_CORE_HARDWARE}/Keyboard.cpp
            ${BULL_INC_CORE_HARDWARE}/KeyboardKey.hpp
            ${BULL_INC_CORE_HARDWARE}/Mouse.hpp
            ${BULL_SRC_CORE_HARDWARE}/Mouse.cpp
            ${BULL_INC_CORE_HARDWARE}/MouseButton.hpp
            ${BULL_INC_CORE_HARDWARE}/MouseWheel.hpp
            ${BULL_INC_CORE_HARDWARE}/RAM.hpp
            ${BULL_SRC_CORE_HARDWARE}/RAM.cpp
        PRIVATE
            ${BULL_SRC_CORE_HARDWARE}/CPUImpl.hpp
            ${BULL_SRC_CORE_HARDWARE}/JoystickImpl.hpp
            ${BULL_SRC_CORE_HARDWARE}/KeyboardImpl.hpp
            ${BULL_SRC_CORE_HARDWARE}/MouseImpl.hpp
            ${BULL_SRC_CORE_HARDWARE}/RAMImpl.hpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
else()
    add_subdirectory(Unix)
    add_subdirectory(Xlib)
endif()