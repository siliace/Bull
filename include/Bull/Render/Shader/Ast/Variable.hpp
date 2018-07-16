#ifndef BULL_RENDER_SHADER_AST_VARIABLE_HPP
#define BULL_RENDER_SHADER_AST_VARIABLE_HPP

#include <Bull/Render/Shader/Ast/Node.hpp>

namespace Bull
{
    namespace Ast
    {
        template <typename T>
        class Variable : public Node
        {
        public:

            explicit Variable(const String& name) :
                Node(name)
            {
                /// Nothing
            }
        };
    }
}

#endif // BULL_RENDER_SHADER_AST_VARIABLE_HPP
