set(BULL_INC_CORE_PLUGIN ${BULL_INC_CORE}/Plugin)
set(BULL_SRC_CORE_PLUGIN ${BULL_SRC_CORE}/Plugin)

target_sources(bull-core
        PUBLIC
        ${BULL_INC_CORE_PLUGIN}/Plugin.hpp
        ${BULL_SRC_CORE_PLUGIN}/Plugin.cpp
        )