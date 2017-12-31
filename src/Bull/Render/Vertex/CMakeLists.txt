set(BULL_INC_RENDER_VERTEX ${BULL_INC_RENDER}/Vertex)
set(BULL_SRC_RENDER_VERTEX ${BULL_SRC_RENDER}/Vertex)

target_sources(bull-render
        PUBLIC
            ${BULL_INC_RENDER_VERTEX}/Vertex.hpp
            ${BULL_SRC_RENDER_VERTEX}/Vertex.cpp
            ${BULL_INC_RENDER_VERTEX}/VertexArray.hpp
            ${BULL_SRC_RENDER_VERTEX}/VertexArray.cpp
        )