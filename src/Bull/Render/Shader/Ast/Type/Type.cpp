#include <Bull/Render/Shader/Ast/Type/Type.hpp>

namespace Bull
{
    namespace Ast
    {
        Node::Type(const String& name) :
            m_name(name)
        {
            /// Nothing
        }

        const String& Node::getName() const
        {
            return m_name;
        }
    }
}