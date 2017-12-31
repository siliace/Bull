#ifndef BULL_RENDER_DRAW_DRAWER_HPP
#define BULL_RENDER_DRAW_DRAWER_HPP

#include <utility>

#include <Bull/Core/Utility/DataType.hpp>

#include <Bull/Render/Draw/RenderPrimitive.hpp>
#include <Bull/Render/Export.hpp>

namespace Bull
{
    class BULL_RENDER_API Drawer
    {
    public:

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

    private:

        /*! \brief Convert a RenderPrimitive to the corresponding OpenGL rendering mode
         *
         * \param primitive The RenderPrimitive to convert
         *
         * \return The OpenGL rendering mode
         *
         */
        static unsigned int convertPrimitive(RenderPrimitive primitive);

        /*! \brief Convert a DataType to the corresponding OpenGL data type
         *
         * \param primitive The DataType to convert
         *
         * \return The OpenGL data type
         *
         */
        static unsigned int convertDataType(DataType type);
    };
}

#endif // BULL_RENDER_DRAW_DRAWER_HPP
