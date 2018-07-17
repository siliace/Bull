set(BULL_INC_RENDER_SHADER_AST_TYPE ${BULL_INC_RENDER_SHADER_AST}/Type)
set(BULL_SRC_RENDER_SHADER_AST_TYPE ${BULL_SRC_RENDER_SHADER_AST}/Type)

target_sources(bull-render
        PUBLIC
            ${BULL_INC_RENDER_SHADER_AST_TYPE}/BuiltIn.hpp
            ${BULL_INC_RENDER_SHADER_AST_TYPE}/Constant.hpp
            ${BULL_INC_RENDER_SHADER_AST_TYPE}/Function.hpp
            ${BULL_INC_RENDER_SHADER_AST_TYPE}/InVariable.hpp
            ${BULL_INC_RENDER_SHADER_AST_TYPE}/OutVariable.hpp
            ${BULL_INC_RENDER_SHADER_AST_TYPE}/Uniform.hpp
            ${BULL_INC_RENDER_SHADER_AST_TYPE}/Type.hpp
            ${BULL_SRC_RENDER_SHADER_AST_TYPE}/Type.cpp
            ${BULL_INC_RENDER_SHADER_AST_TYPE}/Variable.hpp
        )