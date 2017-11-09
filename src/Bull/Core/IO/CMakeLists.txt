set(BULL_INC_CORE_IO ${BULL_INC_CORE}/IO)
set(BULL_SRC_CORE_IO ${BULL_SRC_CORE}/IO)

target_sources(bull-core
        PUBLIC
            ${BULL_INC_CORE_IO}/CursorAwareInOutStream.hpp
            ${BULL_SRC_CORE_IO}/CursorAwareInOutStream.cpp
            ${BULL_INC_CORE_IO}/CursorAwareOutStream.hpp
            ${BULL_SRC_CORE_IO}/CursorAwareOutStream.cpp
            ${BULL_INC_CORE_IO}/CursorAwareInStream.hpp
            ${BULL_SRC_CORE_IO}/CursorAwareInStream.cpp
            ${BULL_INC_CORE_IO}/InOutStream.hpp
            ${BULL_SRC_CORE_IO}/InOutStream.cpp
            ${BULL_INC_CORE_IO}/InStream.hpp
            ${BULL_SRC_CORE_IO}/InStream.cpp
            ${BULL_INC_CORE_IO}/InStringStream.hpp
            ${BULL_SRC_CORE_IO}/InStringStream.cpp
            ${BULL_INC_CORE_IO}/OutStream.hpp
            ${BULL_SRC_CORE_IO}/OutStream.cpp
            ${BULL_INC_CORE_IO}/OutStringStream.hpp
            ${BULL_SRC_CORE_IO}/OutStringStream.cpp
        )