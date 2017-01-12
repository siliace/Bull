cmake_minimum_required(VERSION 3.6)
project(Bull)

set(BULL_MAJOR_VERSION 0)
set(BULL_MINOR_VERSION 1)
set(BULL_PATCH_VERSION 0)
set(BULL_VERSION ${BULL_MAJOR_VERSION}.${BULL_MINOR_VERSION}.${BULL_PATCH_VERSION})

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    set(BULL_OS_WINDOWS 1)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(BULL_OS_LINUX 1)
    set(BULL_OS_UNIX 1)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    set(BULL_OS_OSX 1)
    set(BULL_OS_UNIX 1)
endif()

set(BIN_PATH ${PROJECT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}/Static)

add_subdirectory(src/Bull)