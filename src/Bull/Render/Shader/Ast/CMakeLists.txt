set(BULL_INC_RENDER_SHADER_AST ${BULL_INC_RENDER_SHADER}/Ast)
set(BULL_SRC_RENDER_SHADER_AST ${BULL_SRC_RENDER_SHADER}/Ast)

target_sources(bull-render
        PUBLIC
            ${BULL_INC_RENDER_SHADER_AST}/Constant.hpp
            ${BULL_INC_RENDER_SHADER_AST}/Function.hpp
            ${BULL_INC_RENDER_SHADER_AST}/InVariable.hpp
            ${BULL_INC_RENDER_SHADER_AST}/Node.hpp
            ${BULL_SRC_RENDER_SHADER_AST}/Node.cpp
            ${BULL_INC_RENDER_SHADER_AST}/OutVariable.hpp
            ${BULL_INC_RENDER_SHADER_AST}/Uniform.hpp
            ${BULL_INC_RENDER_SHADER_AST}/Variable.hpp
        )

add_subdirectory(Glsl)