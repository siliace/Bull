target_sources(bull-core
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/Library.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Clipboard.cpp
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/ClipboardImpl.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Config.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/LibraryImpl.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/LibraryImpl.hpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
else()
    add_subdirectory(Unix)
endif()