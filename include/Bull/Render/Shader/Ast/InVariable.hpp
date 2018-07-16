#ifndef BULL_RENDR_SHADER_AST_INVARIABLE_HPP
#define BULL_RENDR_SHADER_AST_INVARIABLE_HPP

#include <Bull/Core/Utility/Optional.hpp>

#include <Bull/Render/Shader/Ast/Variable.hpp>

namespace Bull
{
    namespace Ast
    {
        template <typename T>
        class InVariable : public Variable<T>
        {
        public:

            explicit InVariable(const String& name) :
                Variable<T>(name),
                m_layout(0),
                m_hasLayout(false)
            {
                /// Nothing
            }

            InVariable(const String& name, unsigned int layout) :
                Variable<T>(name),
                m_layout(layout),
                m_hasLayout(true)
            {
                /// Nothing
            }

            void setLayout(unsigned int layout)
            {
                m_layout = layout;
                m_hasLayout = true;
            }

            Optional<const unsigned int> getLayout() const
            {
                if(!m_hasLayout)
                {
                    return Optional<const unsigned int>();
                }

                return Optional<const unsigned int>(&m_layout);
            }

        private:

            unsigned int m_layout;
            bool         m_hasLayout;
        };
    }
}

#endif // BULL_RENDR_SHADER_AST_INVARIABLE_HPP
