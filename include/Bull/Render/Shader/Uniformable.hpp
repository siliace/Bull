#ifndef BULL_RENDER_SHADER_UNIFORMABLE_HPP
#define BULL_RENDER_SHADER_UNIFORMABLE_HPP

#include <Bull/Render/Export.hpp>

namespace Bull
{
    class Shader;

    struct BULL_RENDER_API Uniformable
    {
    protected:

        friend class Shader;

        /*! \brief Set the a uniform variable
         *
         * \param shader   The Shader
         * \param name     The name of the uniform
         * \param location The location of the uniform
         */
        virtual void setUniform(Shader* shader, const String& name, int location) const = 0;
    };
}

#endif // BULL_RENDER_SHADER_UNIFORMABLE_HPP
