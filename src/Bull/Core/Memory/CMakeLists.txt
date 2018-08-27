set(BULL_INC_CORE_MEMORY ${BULL_INC_CORE}/Memory)
set(BULL_SRC_CORE_MEMORY ${BULL_SRC_CORE}/Memory)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_MEMORY}/AbstractBuffer.hpp
            ${BULL_INC_CORE_MEMORY}/ByteArray.hpp
            ${BULL_SRC_CORE_MEMORY}/ByteArray.cpp
            ${BULL_INC_CORE_MEMORY}/RangeCheck.hpp
            ${BULL_SRC_CORE_MEMORY}/RangeCheck.cpp
            ${BULL_INC_CORE_MEMORY}/String.hpp
            ${BULL_SRC_CORE_MEMORY}/String.cpp
        )