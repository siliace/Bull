#ifndef BULL_RENDER_SHADER_AST_OUTVARIABLE_HPP
#define BULL_RENDER_SHADER_AST_OUTVARIABLE_HPP

#include <Bull/Render/Shader/Ast/Variable.hpp>

namespace Bull
{
    namespace Ast
    {
        template <typename T>
        class BULL_RENDER_API OutVariable : public Variable<T>
        {
        public:

            explicit OutVariable(const String& name) :
                Variable<T>(name)
            {
                /// Nothing
            }
        };
    }
}

#endif // BULL_RENDER_SHADER_AST_OUTVARIABLE_HPP
