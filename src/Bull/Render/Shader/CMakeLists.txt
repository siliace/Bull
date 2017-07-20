set(BULL_INC_RENDER_SHADER ${BULL_INC_RENDER}/Shader)
set(BULL_SRC_RENDER_SHADER ${BULL_SRC_RENDER}/Shader)

target_sources(bull-render
        PUBLIC
            ${BULL_INC_RENDER_SHADER}/Shader.hpp
            ${BULL_SRC_RENDER_SHADER}/Shader.cpp
            ${BULL_INC_RENDER_SHADER}/ShaderStage.hpp
            ${BULL_SRC_RENDER_SHADER}/ShaderStage.cpp
        )