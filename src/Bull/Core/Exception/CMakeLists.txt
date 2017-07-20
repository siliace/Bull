set(BULL_INC_CORE_EXCEPTION ${BULL_INC_CORE}/Exception)
set(BULL_SRC_CORE_EXCEPTION ${BULL_SRC_CORE}/Exception)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_EXCEPTION}/Exception.hpp
            ${BULL_SRC_CORE_EXCEPTION}/Exception.cpp
            ${BULL_INC_CORE_EXCEPTION}/InvalidArgument.hpp
            ${BULL_SRC_CORE_EXCEPTION}/InvalidArgument.cpp
            ${BULL_INC_CORE_EXCEPTION}/LogicError.hpp
            ${BULL_SRC_CORE_EXCEPTION}/LogicError.cpp
            ${BULL_INC_CORE_EXCEPTION}/OutOfRange.hpp
            ${BULL_SRC_CORE_EXCEPTION}/OutOfRange.cpp
            ${BULL_INC_CORE_EXCEPTION}/RuntimeError.hpp
            ${BULL_SRC_CORE_EXCEPTION}/RuntimeError.cpp
        )