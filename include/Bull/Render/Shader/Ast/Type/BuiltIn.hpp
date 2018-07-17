#ifndef BULL_RENDER_SHADER_AST_BUILTIN_HPP
#define BULL_RENDER_SHADER_AST_BUILTIN_HPP

#include <Bull/Render/Shader/Ast/Type/Variable.hpp>

namespace Bull
{
    namespace Ast
    {
        template <typename T>
        class BULL_RENDER_API BuiltIn : public Variable<T>
        {
        public:

            explicit BuiltIn(const String& name) :
                    Variable<T>(name)
            {
                /// Nothing
            }
        };
    }
}

#endif // BULL_RENDER_SHADER_AST_BUILTIN_HPP
