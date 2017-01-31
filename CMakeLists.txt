cmake_minimum_required(VERSION 3.6)
project(Bull)

include("cmake/Config.cmake")
include("cmake/Macro.cmake")

set(BULL_MAJOR_VERSION 0)
set(BULL_MINOR_VERSION 1)
set(BULL_PATCH_VERSION 0)
set(BULL_VERSION ${BULL_MAJOR_VERSION}.${BULL_MINOR_VERSION}.${BULL_PATCH_VERSION})

set(CMAKE_CXX_STANDARD 14)

add_definitions(-DBULL_BUILD)

if(BULL_OS_WINDOWS)
    add_definitions(-DBULL_BUILD_WINDOWS_8)
elseif(BULL_OS_UNIX)
    bull_set_option(BULL_BUILD_WEYLAND OFF BOOLEAN "Whether Unix version must be built with Wayland instead of X11")
    if(BULL_BUILD_WEYLAND)
        add_definitions(-DBULL_BUILD_WEYLAND)
    endif()
endif()

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)

bull_set_option(BUILD_SHARED_LIB OFF BOOLEAN "Whether the Bull must be built as a shared library")
bull_set_option(BIN_PATH ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE} STRING "The build directory output")

add_subdirectory(src/Bull)