#ifndef BULL_RENDER_DRAW_DRAWER_HPP
#define BULL_RENDER_DRAW_DRAWER_HPP

#include <utility>

#include <Bull/Core/Utility/DataType.hpp>

#include <Bull/Render/Draw/RenderPrimitive.hpp>
#include <Bull/Render/Export.hpp>

namespace Bull
{
    struct BULL_RENDER_API Drawer
    {
        /*! \brief Draw arrays
         *
         * \param primitive The primitive to use to draw
         * \param start     The index of the first vertex to draw
         * \param count     The number of vertices to draw
         *
         */
        static void drawArrays(RenderPrimitive primitive, std::size_t start, std::size_t count);

        /*! \brief Draw elements
         *
         * \param primitive The primitive to use to draw
         * \param count     The number of elements to draw
         * \param type      The DataType of the element array
         * \param indices   A pointer to the first element
         *
         */
        static void drawElements(RenderPrimitive primitive, std::size_t count, DataType type, const void* indices = nullptr);
    };
}

#endif // BULL_RENDER_DRAW_DRAWER_HPP
