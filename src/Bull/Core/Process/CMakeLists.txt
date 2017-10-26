set(BULL_INC_CORE_PROCESS ${BULL_INC_CORE}/Process)
set(BULL_SRC_CORE_PROCESS ${BULL_SRC_CORE}/Process)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_PROCESS}/CommandLine.hpp
            ${BULL_SRC_CORE_PROCESS}/CommandLine.cpp
            ${BULL_INC_CORE_PROCESS}/Process.hpp
            ${BULL_SRC_CORE_PROCESS}/Process.cpp
            ${BULL_INC_CORE_PROCESS}/ProcessState.hpp
        PRIVATE
            ${BULL_SRC_CORE_PROCESS}/ProcessImpl.hpp
            ${BULL_SRC_CORE_PROCESS}/ProcessImpl.cpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
endif()