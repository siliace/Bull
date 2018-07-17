#ifndef BULL_RENDER_SHADER_AST_UNIFORM_HPP
#define BULL_RENDER_SHADER_AST_UNIFORM_HPP

#include <Bull/Core/Utility/Optional.hpp>

#include <Bull/Render/Shader/Ast/Type/Variable.hpp>

namespace Bull
{
    namespace Ast
    {
        template <typename T>
        class BULL_RENDER_API Uniform : public Variable<T>
        {
        public:

            explicit Uniform(const String& name) :
                    Variable<T>(name),
                    m_hasFallback(false)
            {
                /// Nothing
            }

            Uniform(const String& name, const T& fallback) :
                    Variable<T>(name),
                    m_fallback(fallback),
                    m_hasFallback(true)
            {
                /// Nothing
            }

            Optional<T> getFallback() const
            {
                if(!m_hasFallback)
                {
                    return Optional<T>();
                }

                return Optional<T>(&m_fallback);
            }

        private:

            T    m_fallback;
            bool m_hasFallback;
        };
    }
}

#endif // BULL_RENDER_SHADER_AST_UNIFORM_HPP
