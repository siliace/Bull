set (INC_ROOT ${PROJECT_SOURCE_DIR}/include/Bull/Hardware)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/src/Bull/Hardware)

########################################################################################################################
# Hardware files                                                                                                       #
########################################################################################################################

set(SRC ${SRC_ROOT}/CPU.cpp
        ${INC_ROOT}/CPU.hpp
        ${SRC_ROOT}/CPUImpl.hpp
        ${SRC_ROOT}/Joystick.cpp
        ${INC_ROOT}/Joystick.hpp
        ${SRC_ROOT}/JoystickImpl.hpp
        ${SRC_ROOT}/Keyboard.cpp
        ${INC_ROOT}/Keyboard.hpp
        ${SRC_ROOT}/KeyboardImpl.hpp
        ${SRC_ROOT}/Mouse.cpp
        ${INC_ROOT}/Mouse.hpp
        ${SRC_ROOT}/MouseImpl.hpp
        ${SRC_ROOT}/RAM.cpp
        ${INC_ROOT}/RAM.hpp
        ${SRC_ROOT}/RAMImpl.hpp)

if(BULL_OS_WINDOWS)
    list(APPEND SRC ${SRC_ROOT}/Win32/CPUImpl.cpp)
    list(APPEND SRC ${SRC_ROOT}/Win32/CPUImpl.hpp)
    list(APPEND SRC ${SRC_ROOT}/Win32/JoystickImpl.cpp)
    list(APPEND SRC ${SRC_ROOT}/Win32/JoystickImpl.hpp)
    list(APPEND SRC ${SRC_ROOT}/Win32/KeyboardImpl.cpp)
    list(APPEND SRC ${SRC_ROOT}/Win32/KeyboardImpl.hpp)
    list(APPEND SRC ${SRC_ROOT}/Win32/MouseImpl.cpp)
    list(APPEND SRC ${SRC_ROOT}/Win32/MouseImpl.hpp)
    list(APPEND SRC ${SRC_ROOT}/Win32/RAMImpl.cpp)
    list(APPEND SRC ${SRC_ROOT}/Win32/RAMImpl.hpp)
else()
    list(APPEND SRC ${SRC_ROOT}/Unix/CPUImpl.cpp)
    list(APPEND SRC ${SRC_ROOT}/Unix/CPUImpl.hpp)
    list(APPEND SRC ${SRC_ROOT}/Unix/JoystickImpl.cpp)
    list(APPEND SRC ${SRC_ROOT}/Unix/JoystickImpl.hpp)
    list(APPEND SRC ${SRC_ROOT}/Unix/KeyboardImpl.cpp)
    list(APPEND SRC ${SRC_ROOT}/Unix/KeyboardImpl.hpp)
    list(APPEND SRC ${SRC_ROOT}/Unix/MouseImpl.cpp)
    list(APPEND SRC ${SRC_ROOT}/Unix/MouseImpl.hpp)
    list(APPEND SRC ${SRC_ROOT}/Unix/RAMImpl.cpp)
    list(APPEND SRC ${SRC_ROOT}/Unix/RAMImpl.hpp)
endif()

source_group("" FILES ${SRC})

bull_add_library(bull-hardware SOURCES ${SRC}
                               DEPENDS bull-core)