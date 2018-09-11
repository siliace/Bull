set(BULL_INC_RENDER_TEXTURE ${BULL_INC_RENDER}/Texture)
set(BULL_SRC_RENDER_TEXTURE ${BULL_SRC_RENDER}/Texture)


target_sources(bull-render
        PUBLIC
            ${BULL_INC_RENDER_TEXTURE}/Texture.hpp
            ${BULL_SRC_RENDER_TEXTURE}/Texture.cpp
            ${BULL_INC_RENDER_TEXTURE}/DepthTexture.hpp
            ${BULL_SRC_RENDER_TEXTURE}/DepthTexture.cpp
        )