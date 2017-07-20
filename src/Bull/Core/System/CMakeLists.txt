set(BULL_INC_CORE_SYSTEM ${BULL_INC_CORE}/System)
set(BULL_SRC_CORE_SYSTEM ${BULL_SRC_CORE}/System)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_SYSTEM}/Clipboard.hpp
            ${BULL_SRC_CORE_SYSTEM}/Clipboard.cpp
            ${BULL_INC_CORE_SYSTEM}/Export.hpp
            ${BULL_INC_CORE_SYSTEM}/Integer.hpp
            ${BULL_INC_CORE_SYSTEM}/Library.hpp
            ${BULL_SRC_CORE_SYSTEM}/Library.cpp
            ${BULL_INC_CORE_SYSTEM}/OS.hpp
        PRIVATE
            ${BULL_SRC_CORE_SYSTEM}/ClipboardImpl.hpp
            ${BULL_SRC_CORE_SYSTEM}/LibraryImpl.cpp
            ${BULL_SRC_CORE_SYSTEM}/LibraryImpl.hpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
else()
    add_subdirectory(Unix)
endif()