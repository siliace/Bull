set(BULL_INC_CORE_UTILITY ${BULL_INC_CORE}/Utility)
set(BULL_SRC_CORE_UTILITY ${BULL_SRC_CORE}/Utility)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_UTILITY}/ArrayList.hpp
            ${BULL_INC_CORE_UTILITY}/CleanupCallback.hpp
            ${BULL_SRC_CORE_UTILITY}/CleanupCallback.cpp
            ${BULL_INC_CORE_UTILITY}/Color.hpp
            ${BULL_SRC_CORE_UTILITY}/Color.cpp
            ${BULL_INC_CORE_UTILITY}/DataType.hpp
            ${BULL_INC_CORE_UTILITY}/List.hpp
            ${BULL_INC_CORE_UTILITY}/Random.hpp
            ${BULL_SRC_CORE_UTILITY}/Random.cpp
            ${BULL_INC_CORE_UTILITY}/Size.hpp
            ${BULL_SRC_CORE_UTILITY}/Size.cpp
        )