set(BULL_INC_CORE_PATTERN ${BULL_INC_CORE}/Pattern)
set(BULL_SRC_CORE_PATTERN ${BULL_SRC_CORE}/Pattern)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_PATTERN}/NonCopyable.hpp
            ${BULL_INC_CORE_PATTERN}/NonMovable.hpp
            ${BULL_INC_CORE_PATTERN}/Singleton.hpp
        )