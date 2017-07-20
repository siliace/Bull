cmake_minimum_required(VERSION 3.5.0)
project(Bull)

include(cmake/Macro.cmake)
include(cmake/Config.cmake)
include(cmake/Platform.cmake)

add_definitions(-DBULL_BUILD)

if(BULL_OS_WINDOWS)
    set(WINDOWS_BUILD_VERSION "BULL_BUILD_WINDOWS_VISTA")
else()
    option(WINDOW_LIBRARY "The library to use to manage windowing" "BULL_BUILD_XCB")
endif()

add_definitions(-DBULL_DYNAMIC)

if(BULL_OS_WINDOWS)
    add_definitions("-D${WINDOWS_BUILD_VERSION}")
else()
    add_definitions("-D${WINDOW_LIBRARY}")
endif()

include_directories(libs/include)
include_directories(include)
include_directories(src)

if(BULL_OS_WINDOWS)
    link_directories(libs/Windows/x64)
else()
    link_directories(libs/Unix/x64)
endif()

set(BULL_INC ${CMAKE_CURRENT_SOURCE_DIR}/include/Bull)
set(BULL_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/Bull)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

add_subdirectory(demo)
add_subdirectory(src)