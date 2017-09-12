set(BULL_INC_RENDER_SHADER ${BULL_INC_RENDER}/Shader)
set(BULL_SRC_RENDER_SHADER ${BULL_SRC_RENDER}/Shader)

target_sources(bull-render
        PUBLIC
            ${BULL_SRC_RENDER_SHADER}/BaseShaderStageLoader.hpp
            ${BULL_SRC_RENDER_SHADER}/BaseShaderStageLoader.cpp
            ${BULL_SRC_RENDER_SHADER}/BaseShaderStageSaver.hpp
            ${BULL_SRC_RENDER_SHADER}/BaseShaderStageSaver.cpp
            ${BULL_INC_RENDER_SHADER}/AbstractShaderStageLoader.hpp
            ${BULL_INC_RENDER_SHADER}/AbstractShaderStageSaver.hpp
            ${BULL_INC_RENDER_SHADER}/Shader.hpp
            ${BULL_SRC_RENDER_SHADER}/Shader.cpp
            ${BULL_INC_RENDER_SHADER}/ShaderStage.hpp
            ${BULL_SRC_RENDER_SHADER}/ShaderStage.cpp
            ${BULL_INC_RENDER_SHADER}/ShaderStageManager.hpp
            ${BULL_SRC_RENDER_SHADER}/ShaderStageManager.cpp
            ${BULL_INC_RENDER_SHADER}/ShaderStageParameters.hpp
            ${BULL_SRC_RENDER_SHADER}/ShaderStageParameters.cpp
        )