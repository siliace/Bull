set(BULL_INC_CORE_CONFIGURATION ${BULL_INC_CORE}/Configuration)
set(BULL_SRC_CORE_CONFIGURATION ${BULL_SRC_CORE}/Configuration)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_CONFIGURATION}/Compiler.hpp
            ${BULL_INC_CORE_CONFIGURATION}/Export.hpp
            ${BULL_INC_CORE_CONFIGURATION}/Integer.hpp
            ${BULL_INC_CORE_CONFIGURATION}/OS.hpp
        )