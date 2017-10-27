set(BULL_INC_CORE_META ${BULL_INC_CORE}/Meta)
set(BULL_SRC_CORE_META ${BULL_SRC_CORE}/Meta)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_META}/EnableIfBaseOf.hpp
            ${BULL_INC_CORE_META}/Operators.hpp
        )