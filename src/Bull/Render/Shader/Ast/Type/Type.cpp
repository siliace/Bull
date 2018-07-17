#include <Bull/Render/Shader/Ast/Type/Type.hpp>

namespace Bull
{
    namespace Ast
    {
        Type::Type(const String& name) :
            m_name(name)
        {
            /// Nothing
        }

        const String& Type::getName() const
        {
            return m_name;
        }
    }
}