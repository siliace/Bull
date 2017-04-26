target_sources(bull-core
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/Directory.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/File.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Path.cpp
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/DirectoryImpl.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/DirectoryImpl.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/FileImpl.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/FileImpl.hpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
else()
    add_subdirectory(Unix)
endif()