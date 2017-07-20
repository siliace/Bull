set(BULL_INC_HARDWARE ${BULL_INC}/Hardware)
set(BULL_SRC_HARDWARE ${BULL_SRC}/Hardware)

bull_add_library(bull-hardware)

target_sources(bull-hardware
        PUBLIC
            ${BULL_INC_HARDWARE}/CPU.hpp
            ${BULL_SRC_HARDWARE}/CPU.cpp
            ${BULL_INC_HARDWARE}/Export.hpp
            ${BULL_INC_HARDWARE}/Joystick.hpp
            ${BULL_SRC_HARDWARE}/Joystick.cpp
            ${BULL_INC_HARDWARE}/Keyboard.hpp
            ${BULL_SRC_HARDWARE}/Keyboard.cpp
            ${BULL_INC_HARDWARE}/Mouse.hpp
            ${BULL_SRC_HARDWARE}/Mouse.cpp
            ${BULL_INC_HARDWARE}/RAM.hpp
            ${BULL_SRC_HARDWARE}/RAM.cpp
        PRIVATE
            ${BULL_SRC_HARDWARE}/CPUImpl.hpp
            ${BULL_SRC_HARDWARE}/JoystickImpl.hpp
            ${BULL_SRC_HARDWARE}/KeyboardImpl.hpp
            ${BULL_SRC_HARDWARE}/MouseImpl.hpp
            ${BULL_SRC_HARDWARE}/RAMImpl.hpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
    target_link_libraries(bull-hardware winmm)
else()
    add_subdirectory(Unix)
    if(WINDOW_LIBRARY STREQUAL "BULL_BUILD_XLIB")
        add_subdirectory(Xlib)
    elseif(WINDOW_LIBRARY STREQUAL "BULL_BUILD_XCB")
        add_subdirectory(XCB)
    elseif(WINDOW_LIBRARY STREQUAL "BULL_BUILD_WEYLAND")
        add_subdirectory(Weyland)
    endif()
endif()

target_link_libraries(bull-hardware bull-core)
