#include <Bull/Render/Shader/Ast/Node.hpp>

namespace Bull
{
    namespace Ast
    {
        Node::Node(const String& name) :
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