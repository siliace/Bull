set(BULL_INC_CORE_PROCESS ${BULL_INC_CORE}/Process)
set(BULL_SRC_CORE_PROCESS ${BULL_SRC_CORE}/Process)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_PROCESS}/Process.hpp
            ${BULL_SRC_CORE_PROCESS}/Process.cpp
        PRIVATE
            ${BULL_SRC_CORE_PROCESS}/ProcessImpl.hpp
            ${BULL_SRC_CORE_PROCESS}/ProcessImpl.cpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
else()
    add_subdirectory(Unix)
endif()