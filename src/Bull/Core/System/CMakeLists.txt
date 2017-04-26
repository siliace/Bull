target_sources(bull-core
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/Library.cpp
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/LibraryImpl.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/LibraryImpl.hpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
else()
    add_subdirectory(Unix)
endif()