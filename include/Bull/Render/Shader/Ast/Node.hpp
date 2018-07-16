#ifndef BULL_RENDER_SHADER_AST_NODE_HPP
#define BULL_RENDER_SHADER_AST_NODE_HPP

#include <Bull/Core/Memory/String.hpp>

#include <Bull/Render/Export.hpp>

namespace Bull
{
    namespace Ast
    {
        class BULL_RENDER_API Node
        {
        public:

            /*! \brief Constructor
             *
             * \param name The name of the node
             *
             */
            explicit Node(const String& name);

            /*! \brief Get the name of the Node
             *
             * \return The name
             *
             */
            const String& getName() const;

        private:

            String m_name;
        };
    }
}

#endif // BULL_RENDER_SHADER_AST_NODE_HPP
