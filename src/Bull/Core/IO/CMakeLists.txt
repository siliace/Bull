set(BULL_INC_CORE_IO ${BULL_INC_CORE}/IO)
set(BULL_SRC_CORE_IO ${BULL_SRC_CORE}/IO)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_IO}/InOutStream.hpp
            ${BULL_INC_CORE_IO}/InStream.hpp
            ${BULL_SRC_CORE_IO}/InStream.cpp
            ${BULL_INC_CORE_IO}/OutStream.hpp
            ${BULL_INC_CORE_IO}/StringStream.hpp
            ${BULL_SRC_CORE_IO}/StringStream.cpp
        )