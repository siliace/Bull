#ifndef BULL_RENDER_SHADER_AST_FUNCTION_HPP
#define BULL_RENDER_SHADER_AST_FUNCTION_HPP

#include <Bull/Render/Shader/Ast/Type/Type.hpp>
#include <functional>

namespace Bull
{
    namespace Ast
    {
        template <typename T, typename... Args>
        class BULL_RENDER_API Function : public Type
        {
        public:

            explicit Function(const String& name, std::function<T(Args...)> code) :
                    Type(name),
                    m_code(code)
            {
                /// Nothing
            }

        private:

            std::function<T(Args...)> m_code;
        };
    }
}

#endif // BULL_RENDER_SHADER_AST_FUNCTION_HPP
