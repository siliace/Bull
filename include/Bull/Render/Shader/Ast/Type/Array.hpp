#ifndef BULL_RENDER_SHADER_AST_ARRAY_HPP
#define BULL_RENDER_SHADER_AST_ARRAY_HPP

#include <Bull/Render/Shader/Ast/Type/Variable.hpp>

namespace Bull
{
    namespace Ast
    {
        template <typename T, std::size_t N>
        class Array : public Variable<T>
        {
        public:

            static constexpr std::size_t Size = N;

        public:

            explicit Array(const String& name) :
                Variable<T>(name)
            {
                /// Nothing
            }
        };
    }
}

#endif // BULL_RENDER_SHADER_AST_ARRAY_HPP
