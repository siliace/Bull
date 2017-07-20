set(BULL_INC_UTILITY_LOGGER ${BULL_INC_UTILITY}/Logger)
set(BULL_SRC_UTILITY_LOGGER ${BULL_SRC_UTILITY}/Logger)

target_sources(bull-utility
        PUBLIC
            ${BULL_INC_UTILITY_LOGGER}/ConsoleLogger.hpp
            ${BULL_SRC_UTILITY_LOGGER}/ConsoleLogger.cpp
            ${BULL_INC_UTILITY_LOGGER}/FileLogger.hpp
            ${BULL_SRC_UTILITY_LOGGER}/FileLogger.cpp
        )