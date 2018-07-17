#ifndef BULL_RENDER_SHADER_AST_TYPE_HPP
#define BULL_RENDER_SHADER_AST_TYPE_HPP

#include <Bull/Core/Memory/String.hpp>

#include <Bull/Render/Export.hpp>

namespace Bull
{
    namespace Ast
    {
        class BULL_RENDER_API Type
        {
        public:

            /*! \brief Constructor
             *
             * \param name The name of the Type
             *
             */
            explicit Type(const String& name);

            /*! \brief Get the name of the Type
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

#endif // BULL_RENDER_SHADER_AST_TYPE_HPP
