set(BULL_INC_CORE_SIGNAL ${BULL_INC_CORE}/Signal)
set(BULL_SRC_CORE_SIGNAL ${BULL_SRC_CORE}/Signal)

target_sources(bull-core
        PUBLIC
        ${BULL_INC_CORE_SIGNAL}/Signal.hpp
        )