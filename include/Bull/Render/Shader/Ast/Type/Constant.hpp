#ifndef BULL_RENDER_SHADER_AST_CONSTANT_HPP
#define BULL_RENDER_SHADER_AST_CONSTANT_HPP

#include <Bull/Render/Shader/Ast/Type/Variable.hpp>

namespace Bull
{
    namespace Ast
    {
        template <typename T>
        class BULL_RENDER_API Constant : public Variable<T>
        {
        public:

            Constant(const String& name, const T& value) :
                    Variable<T>(name),
                    m_value(value)
            {
                /// Nothing
            }

            const T& getValue() const
            {
                return m_value;
            }

        private:

            T m_value;
        };
    }
}

#endif // BULL_RENDER_SHADER_AST_CONSTANT_HPP
