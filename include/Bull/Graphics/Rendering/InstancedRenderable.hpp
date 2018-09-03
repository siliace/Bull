#ifndef BULL_GRAPHICS_RENDERING_INSTANCEDRENDERABLE_HPP
#define BULL_GRAPHICS_RENDERING_INSTANCEDRENDERABLE_HPP

#include <Bull/Graphics/Rendering/Renderable.hpp>

namespace Bull
{
    struct BULL_GRAPHICS_API InstancedRenderable : public Renderable
    {
        /*! \brief Render the InstancedRenderable
         *
         * \param shader The Shader to use to render
         * \param count  The number of instance of the object to render
         *
         */
        virtual void render(const Shader& shader, std::size_t count) const = 0;
    };
}

#endif // BULL_GRAPHICS_RENDERING_INSTANCEDRENDERABLE_HPP
