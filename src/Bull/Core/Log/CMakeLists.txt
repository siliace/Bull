set(BULL_INC_CORE_LOG ${BULL_INC_CORE}/Log)
set(BULL_SRC_CORE_LOG ${BULL_SRC_CORE}/Log)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_LOG}/AbstractLogger.hpp
            ${BULL_INC_CORE_LOG}/Log.hpp
            ${BULL_SRC_CORE_LOG}/Log.cpp
        )