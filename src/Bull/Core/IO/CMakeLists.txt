set(BULL_INC_CORE_IO ${BULL_INC_CORE}/IO)
set(BULL_SRC_CORE_IO ${BULL_SRC_CORE}/IO)

target_sources(bull-core
        PUBLIC
        ${BULL_INC_CORE_IO}/CursorAwareInStream.hpp
        ${BULL_SRC_CORE_IO}/CursorAwareInStream.cpp
        ${BULL_INC_CORE_IO}/InStream.hpp
        ${BULL_SRC_CORE_IO}/InStream.cpp
        ${BULL_INC_CORE_IO}/MemoryStream.hpp
        ${BULL_SRC_CORE_IO}/MemoryStream.cpp
        ${BULL_INC_CORE_IO}/OutStream.hpp
        ${BULL_SRC_CORE_IO}/OutStream.cpp
        ${BULL_INC_CORE_IO}/TextReader.hpp
        ${BULL_SRC_CORE_IO}/TextReader.cpp
        ${BULL_INC_CORE_IO}/TextWriter.hpp
        ${BULL_SRC_CORE_IO}/TextWriter.cpp
        )