set(BULL_INC_RENDER_BUFFER ${BULL_INC_RENDER}/Buffer)
set(BULL_SRC_RENDER_BUFFER ${BULL_SRC_RENDER}/Buffer)

target_sources(bull-render
        PUBLIC
        ${BULL_INC_RENDER_BUFFER}/ArrayBuffer.hpp
        ${BULL_SRC_RENDER_BUFFER}/ArrayBuffer.cpp
        ${BULL_INC_RENDER_BUFFER}/HardwareBuffer.hpp
        ${BULL_SRC_RENDER_BUFFER}/HardwareBuffer.cpp
        ${BULL_INC_RENDER_BUFFER}/HardwareBufferType.hpp
        ${BULL_INC_RENDER_BUFFER}/HardwareBufferUsage.hpp
        ${BULL_INC_RENDER_BUFFER}/IndexBuffer.hpp
        ${BULL_SRC_RENDER_BUFFER}/IndexBuffer.cpp
        ${BULL_INC_RENDER_BUFFER}/VertexArrayObject.hpp
        ${BULL_SRC_RENDER_BUFFER}/VertexArrayObject.cpp
        )