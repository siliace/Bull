set (INCROOT ${PROJECT_SOURCE_DIR}/include/Bull/Hardware)
set (SRCROOT ${PROJECT_SOURCE_DIR}/src/Bull/Hardware)

set(SRC ${SRCROOT}/CPU.cpp
        ${INCROOT}/CPU.hpp
        ${SRCROOT}/CPUImpl.hpp
        ${SRCROOT}/Joystick.cpp
        ${INCROOT}/Joystick.hpp
        ${SRCROOT}/JoystickImpl.hpp
        ${SRCROOT}/Keyboard.cpp
        ${INCROOT}/Keyboard.hpp
        ${SRCROOT}/KeyboardImpl.hpp
        ${SRCROOT}/Mouse.cpp
        ${INCROOT}/Mouse.hpp
        ${SRCROOT}/MouseImpl.hpp
        ${SRCROOT}/RAM.cpp
        ${INCROOT}/RAM.hpp
        ${SRCROOT}/RAMImpl.hpp)

if(BULL_OS_WINDOWS)
    list(APPEND SRC ${SRCROOT}/Win32/CPUImpl.cpp)
    list(APPEND SRC ${SRCROOT}/Win32/CPUImpl.hpp)
    list(APPEND SRC ${SRCROOT}/Win32/JoystickImpl.cpp)
    list(APPEND SRC ${SRCROOT}/Win32/JoystickImpl.hpp)
    list(APPEND SRC ${SRCROOT}/Win32/KeyboardImpl.cpp)
    list(APPEND SRC ${SRCROOT}/Win32/KeyboardImpl.hpp)
    list(APPEND SRC ${SRCROOT}/Win32/MouseImpl.cpp)
    list(APPEND SRC ${SRCROOT}/Win32/MouseImpl.hpp)
    list(APPEND SRC ${SRCROOT}/Win32/RAMImpl.cpp)
    list(APPEND SRC ${SRCROOT}/Win32/RAMImpl.hpp)
else()
    list(APPEND SRC ${SRCROOT}/Unix/CPUImpl.cpp)
    list(APPEND SRC ${SRCROOT}/Unix/CPUImpl.hpp)
    list(APPEND SRC ${SRCROOT}/Unix/JoystickImpl.cpp)
    list(APPEND SRC ${SRCROOT}/Unix/JoystickImpl.hpp)
    list(APPEND SRC ${SRCROOT}/Unix/KeyboardImpl.cpp)
    list(APPEND SRC ${SRCROOT}/Unix/KeyboardImpl.hpp)
    list(APPEND SRC ${SRCROOT}/Unix/MouseImpl.cpp)
    list(APPEND SRC ${SRCROOT}/Unix/MouseImpl.hpp)
    list(APPEND SRC ${SRCROOT}/Unix/RAMImpl.cpp)
    list(APPEND SRC ${SRCROOT}/Unix/RAMImpl.hpp)
endif()

add_library(bull-hardware ${LIB_TYPE} ${SRC})

target_link_libraries(bull-hardware bull-core)