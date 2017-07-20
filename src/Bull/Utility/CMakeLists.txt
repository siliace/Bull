set(BULL_INC_UTILITY ${BULL_INC}/Utility)
set(BULL_SRC_UTILITY ${BULL_SRC}/Utility)

bull_add_library(bull-utility)

target_sources(bull-utility
        PUBLIC
            ${BULL_INC_UTILITY}/CallOnExit.hpp
            ${BULL_SRC_UTILITY}/CallOnExit.cpp
            ${BULL_INC_UTILITY}/Color.hpp
            ${BULL_SRC_UTILITY}/Color.cpp
            ${BULL_INC_UTILITY}/Export.hpp
            ${BULL_INC_UTILITY}/Random.hpp
            ${BULL_SRC_UTILITY}/Random.cpp
            ${BULL_INC_UTILITY}/Vertex.hpp
            ${BULL_SRC_UTILITY}/Vertex.cpp
        )

add_subdirectory(Image)
add_subdirectory(Logger)

target_link_libraries(bull-utility stb)

target_link_libraries(bull-utility bull-core)