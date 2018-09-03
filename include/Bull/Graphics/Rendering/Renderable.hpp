#ifndef BULL_GRAPHICS_RENDERING_RENDERABLE_HPP
#define BULL_GRAPHICS_RENDERING_RENDERABLE_HPP

#include <Bull/Graphics/Export.hpp>

#include <Bull/Render/Shader/Shader.hpp>

namespace Bull
{
    struct BULL_GRAPHICS_API Renderable
    {
        /*! \brief Render the Renderable
         *
         * \param shader The Shader to use to render
         *
         */
        virtual void render(const Shader& shader) const = 0;
    };
}

#endif // BULL_GRAPHICS_RENDERING_RENDERABLE_HPP
