set(BULL_INC_CORE_TIME ${BULL_INC_CORE}/Time)
set(BULL_SRC_CORE_TIME ${BULL_SRC_CORE}/Time)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_TIME}/Clock.hpp
            ${BULL_SRC_CORE_TIME}/Clock.cpp
            ${BULL_SRC_CORE_TIME}/ClockImpl.hpp
            ${BULL_INC_CORE_TIME}/Date.hpp
            ${BULL_SRC_CORE_TIME}/Date.cpp
            ${BULL_INC_CORE_TIME}/DateDay.hpp
            ${BULL_SRC_CORE_TIME}/DateImpl.hpp
            ${BULL_INC_CORE_TIME}/DateMonth.hpp
            ${BULL_INC_CORE_TIME}/DateTime.hpp
            ${BULL_SRC_CORE_TIME}/DateTime.cpp
            ${BULL_INC_CORE_TIME}/Duration.hpp
            ${BULL_SRC_CORE_TIME}/Duration.cpp
            ${BULL_INC_CORE_TIME}/Time.hpp
            ${BULL_SRC_CORE_TIME}/Time.cpp
            ${BULL_SRC_CORE_TIME}/TimeImpl.hpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Win32)
else()
    add_subdirectory(Unix)
endif()