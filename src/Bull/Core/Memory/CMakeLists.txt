set(BULL_INC_CORE_MEMORY ${BULL_INC_CORE}/Memory)
set(BULL_SRC_CORE_MEMORY ${BULL_SRC_CORE}/Memory)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_MEMORY}/Buffer.hpp
            ${BULL_INC_CORE_MEMORY}/MemoryStream.hpp
            ${BULL_SRC_CORE_MEMORY}/MemoryStream.cpp
            ${BULL_INC_CORE_MEMORY}/String.hpp
            ${BULL_INC_CORE_MEMORY}/String.inl
            ${BULL_SRC_CORE_MEMORY}/String.cpp
        )