add_library(bull-hardware SHARED "")

target_sources(bull-hardware
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/CPU.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Joystick.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Keyboard.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Mouse.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/RAM.cpp
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/CPUImpl.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/JoystickImpl.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/KeyboardImpl.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/MouseImpl.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/RAMImpl.hpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
else()
    add_subdirectory(Unix)
endif()