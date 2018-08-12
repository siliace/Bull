set(BULL_INC_CORE_EXCEPTION ${BULL_INC_CORE}/Exception)
set(BULL_SRC_CORE_EXCEPTION ${BULL_SRC_CORE}/Exception)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_EXCEPTION}/FileNotFound.hpp
            ${BULL_INC_CORE_EXCEPTION}/Exception.hpp
            ${BULL_SRC_CORE_EXCEPTION}/Exception.cpp
            ${BULL_INC_CORE_EXCEPTION}/InternalError.hpp
            ${BULL_INC_CORE_EXCEPTION}/InvalidParameter.hpp
            ${BULL_INC_CORE_EXCEPTION}/LackOfImplementation.hpp
            ${BULL_INC_CORE_EXCEPTION}/LogicError.hpp
            ${BULL_INC_CORE_EXCEPTION}/UnsupportedOperation.hpp
        )