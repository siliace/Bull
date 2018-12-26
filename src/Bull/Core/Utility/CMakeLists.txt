set(BULL_INC_CORE_UTILITY ${BULL_INC_CORE}/Utility)
set(BULL_SRC_CORE_UTILITY ${BULL_SRC_CORE}/Utility)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_UTILITY}/AtInit.hpp
            ${BULL_SRC_CORE_UTILITY}/AtInit.cpp
            ${BULL_INC_CORE_UTILITY}/Character.hpp
            ${BULL_SRC_CORE_UTILITY}/Character.cpp
            ${BULL_INC_CORE_UTILITY}/Color.hpp
            ${BULL_SRC_CORE_UTILITY}/Color.cpp
            ${BULL_INC_CORE_UTILITY}/DataType.hpp
            ${BULL_INC_CORE_UTILITY}/Finally.hpp
            ${BULL_SRC_CORE_UTILITY}/Finally.cpp
            ${BULL_INC_CORE_UTILITY}/MapUtils.hpp
            ${BULL_INC_CORE_UTILITY}/Random.hpp
            ${BULL_SRC_CORE_UTILITY}/Random.cpp
            ${BULL_INC_CORE_UTILITY}/Size.hpp
            ${BULL_INC_CORE_UTILITY}/StringUtils.hpp
            ${BULL_SRC_CORE_UTILITY}/StringUtils.cpp
        )