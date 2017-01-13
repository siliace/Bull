set (INC_ROOT ${PROJECT_SOURCE_DIR}/include/Bull/Utility)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/src/Bull/Utility)

########################################################################################################################
# Utility files                                                                                                        #
########################################################################################################################

include_directories(${PROJECT_SOURCE_DIR}/extlibs/include)

set(SRC ${SRC_ROOT}/CallOnExit.cpp
        ${INC_ROOT}/CallOnExit.hpp
        ${SRC_ROOT}/ConsoleLogger.cpp
        ${INC_ROOT}/ConsoleLogger.hpp
        ${SRC_ROOT}/FileLogger.cpp
        ${INC_ROOT}/FileLogger.hpp
        ${SRC_ROOT}/Random.cpp
        ${INC_ROOT}/Random.hpp
        ${SRC_ROOT}/Image.cpp
        ${INC_ROOT}/Image.hpp
        ${SRC_ROOT}/ImageLoader.cpp
        ${SRC_ROOT}/ImageLoader.hpp)

source_group("" FILES ${SRC})

########################################################################################################################
# Utility/Window files                                                                                                 #
########################################################################################################################

set(SRC_WINDOW ${SRC_ROOT}/Window/VideoMode.cpp
               ${INC_ROOT}/Window/VideoMode.hpp
               ${SRC_ROOT}/Window/VideoModeImpl.hpp
               ${SRC_ROOT}/Window/Window.cpp
               ${INC_ROOT}/Window/Window.hpp
               ${SRC_ROOT}/Window/WindowImpl.cpp
               ${SRC_ROOT}/Window/WindowImpl.hpp
               ${INC_ROOT}/Window/WindowHandler.hpp
               ${SRC_ROOT}/Window/JoystickManager.cpp
               ${SRC_ROOT}/Window/JoystickManager.hpp)

if(BULL_OS_WINDOWS)
    list(APPEND SRC_WINDOW ${SRC_ROOT}/Window/Win32/WindowImplWin32.cpp)
    list(APPEND SRC_WINDOW ${SRC_ROOT}/Window/Win32/WindowImplWin32.hpp)
    list(APPEND SRC_WINDOW ${SRC_ROOT}/Window/Win32/VideoModeImpl.cpp)
    list(APPEND SRC_WINDOW ${SRC_ROOT}/Window/Win32/VideoModeImpl.hpp)
else()
    list(APPEND SRC_WINDOW ${SRC_ROOT}/Window/X11/WindowImplX11.cpp)
    list(APPEND SRC_WINDOW ${SRC_ROOT}/Window/X11/WindowImplX11.hpp)
    list(APPEND SRC_WINDOW ${SRC_ROOT}/Window/X11/VideoModeImpl.cpp)
    list(APPEND SRC_WINDOW ${SRC_ROOT}/Window/X11/VideoModeImpl.hpp)
    list(APPEND SRC_WINDOW ${SRC_ROOT}/Window/X11/ErrorHandler.cpp)
    list(APPEND SRC_WINDOW ${SRC_ROOT}/Window/X11/ErrorHandler.hpp)
    list(APPEND SRC_WINDOW ${SRC_ROOT}/Window/X11/Display.cpp)
    list(APPEND SRC_WINDOW ${SRC_ROOT}/Window/X11/Display.hpp)
endif()

source_group("window" FILES ${SRC_WINDOW})

set(EXTERNAL_LIBS)

if(BULL_OS_LINUX)
    find_package(X11 REQUIRED)
    if(NOT X11_FOUND)
        message(FATAL_ERROR "X11 library not found")
    endif()
    if(NOT X11_Xrandr_FOUND)
        message(FATAL_ERROR "Xrandr library not found")
    endif()
    include_directories(${X11_INCLUDE_DIR})
endif()

if(BULL_OS_WINDOWS)
    list(APPEND EXTERNAL_LIBS gdi32)
    list(APPEND EXTERNAL_LIBS winmm)
else()
    list(APPEND EXTERNAL_LIBS ${X11_X11_LIB})
    list(APPEND EXTERNAL_LIBS ${X11_Xrandr_LIB})
endif()

bull_add_library(bull-utility SOURCES ${SRC} ${SRC_WINDOW}
                              DEPENDS bull-core
                              EXTERNALS ${EXTERNAL_LIBS})