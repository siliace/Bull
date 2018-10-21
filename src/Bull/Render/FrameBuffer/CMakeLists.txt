set(BULL_INC_RENDER_FRAMEBUFFER ${BULL_INC_RENDER}/FrameBuffer)
set(BULL_SRC_RENDER_FRAMEBUFFER ${BULL_SRC_RENDER}/FrameBuffer)

target_sources(bull-render
        PUBLIC
            ${BULL_INC_RENDER_FRAMEBUFFER}/AttachmentPoint.hpp
            ${BULL_INC_RENDER_FRAMEBUFFER}/FrameBuffer.hpp
            ${BULL_SRC_RENDER_FRAMEBUFFER}/FrameBuffer.cpp
        )