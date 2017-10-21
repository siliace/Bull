set(BULL_INC_CORE_LOG ${BULL_INC_CORE}/Log)
set(BULL_SRC_CORE_LOG ${BULL_SRC_CORE}/Log)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_LOG}/AbstractLogger.hpp
            ${BULL_SRC_CORE_LOG}/AbstractLogger.cpp
            ${BULL_INC_CORE_LOG}/ConsoleLogger.hpp
            ${BULL_SRC_CORE_LOG}/ConsoleLogger.cpp
            ${BULL_INC_CORE_LOG}/FileLogger.hpp
            ${BULL_SRC_CORE_LOG}/FileLogger.cpp
            ${BULL_INC_CORE_LOG}/Log.hpp
            ${BULL_INC_CORE_LOG}/Log.inl
            ${BULL_INC_CORE_LOG}/LogLevel.hpp
            ${BULL_SRC_CORE_LOG}/Log.cpp
            ${BULL_INC_CORE_LOG}/MessageWindowLogger.hpp
            ${BULL_SRC_CORE_LOG}/MessageWindowLogger.cpp
        )