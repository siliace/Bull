set(BULL_INC_CORE_TIME ${BULL_INC_CORE}/Time)
set(BULL_SRC_CORE_TIME ${BULL_SRC_CORE}/Time)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_TIME}/Clock.hpp
            ${BULL_SRC_CORE_TIME}/Clock.cpp
            ${BULL_INC_CORE_TIME}/Date.hpp
            ${BULL_SRC_CORE_TIME}/Date.cpp
            ${BULL_INC_CORE_TIME}/Day.hpp
            ${BULL_INC_CORE_TIME}/Month.hpp
            ${BULL_INC_CORE_TIME}/Time.hpp
            ${BULL_SRC_CORE_TIME}/Time.cpp
        PRIVATE
            ${BULL_SRC_CORE_TIME}/ClockImpl.hpp
            ${BULL_SRC_CORE_TIME}/DateImpl.hpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
else()
    add_subdirectory(Unix)
endif()