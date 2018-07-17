#ifndef BULL_RENDER_SHADER_AST_VARIABLE_HPP
#define BULL_RENDER_SHADER_AST_VARIABLE_HPP

#include <Bull/Render/Shader/Ast/Type/Type.hpp>

namespace Bull
{
    namespace Ast
    {
        template <typename T>
        class Variable : public Type
        {
        public:

            explicit Variable(const String& name) :
                Type(name)
            {
                /// Nothing
            }
        };
    }
}

#endif // BULL_RENDER_SHADER_AST_VARIABLE_HPP
