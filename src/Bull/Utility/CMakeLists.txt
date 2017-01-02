set (INCROOT ${PROJECT_SOURCE_DIR}/include/Bull/Utility)
set (SRCROOT ${PROJECT_SOURCE_DIR}/src/Bull/Utility)

include_directories(${PROJECT_SOURCE_DIR}/extlibs/include)

set(SRC ${SRCROOT}/CallOnExit.cpp
        ${INCROOT}/CallOnExit.hpp
        ${SRCROOT}/ConsoleLogger.cpp
        ${INCROOT}/ConsoleLogger.hpp
        ${SRCROOT}/FileLogger.cpp
        ${INCROOT}/FileLogger.hpp
        ${SRCROOT}/Random.cpp
        ${INCROOT}/Random.hpp
        ${SRCROOT}/Image.cpp
        ${INCROOT}/Image.hpp
        ${SRCROOT}/ImageLoader.cpp
        ${SRCROOT}/ImageLoader.hpp)

set(SRCWINDOW ${SRCROOT}/Window/VideoMode.cpp
              ${INCROOT}/Window/VideoMode.hpp
              ${SRCROOT}/Window/VideoModeImpl.hpp
              ${SRCROOT}/Window/Window.cpp
              ${INCROOT}/Window/Window.hpp
              ${SRCROOT}/Window/WindowImpl.cpp
              ${SRCROOT}/Window/WindowImpl.hpp
              ${INCROOT}/Window/WindowHandler.hpp
              ${SRCROOT}/Window/JoystickManager.cpp
              ${SRCROOT}/Window/JoystickManager.hpp)

if(BULL_OS_WINDOWS)
    list(APPEND SRCWINDOW ${SRCROOT}/Window/Win32/WindowImplWin32.cpp)
    list(APPEND SRCWINDOW ${SRCROOT}/Window/Win32/WindowImplWin32.hpp)
    list(APPEND SRCWINDOW ${SRCROOT}/Window/Win32/VideoModeImpl.cpp)
    list(APPEND SRCWINDOW ${SRCROOT}/Window/Win32/VideoModeImpl.hpp)
else()
    list(APPEND SRCWINDOW ${SRCROOT}/Window/X11/WindowImplX11.cpp)
    list(APPEND SRCWINDOW ${SRCROOT}/Window/X11/WindowImplX11.hpp)
    list(APPEND SRCWINDOW ${SRCROOT}/Window/X11/VideoModeImpl.cpp)
    list(APPEND SRCWINDOW ${SRCROOT}/Window/X11/VideoModeImpl.hpp)
    list(APPEND SRCWINDOW ${SRCROOT}/Window/X11/ErrorHandler.cpp)
    list(APPEND SRCWINDOW ${SRCROOT}/Window/X11/ErrorHandler.hpp)
    list(APPEND SRCWINDOW ${SRCROOT}/Window/X11/Display.cpp)
    list(APPEND SRCWINDOW ${SRCROOT}/Window/X11/Display.hpp)
endif()

add_library(bull-utility ${LIB_TYPE} ${SRC} ${SRCWINDOW})

if(BULL_OS_UNIX)
    target_link_libraries(bull-utility X11)
endif()

target_link_libraries(bull-utility bull-core)