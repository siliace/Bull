set(BULL_INC_CORE_SIGNALS ${BULL_INC_CORE}/Signals)
set(BULL_SRC_CORE_SIGNALS ${BULL_SRC_CORE}/Signals)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_SIGNALS}/Connection.hpp
            ${BULL_INC_CORE_SIGNALS}/ScopedConnection.hpp
            ${BULL_INC_CORE_SIGNALS}/Signal.hpp
            ${BULL_INC_CORE_SIGNALS}/Slot.hpp
        )