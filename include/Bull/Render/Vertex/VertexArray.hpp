#ifndef BULL_RENDER_VERTEX_VERTEXARRAY_HPP
#define BULL_RENDER_VERTEX_VERTEXARRAY_HPP

#include <Bull/Core/Utility/ArrayList.hpp>
#include <Bull/Core/Utility/Color.hpp>

#include <Bull/Math/Polygon/Polygon.hpp>

#include <Bull/Render/Vertex/Vertex.hpp>

namespace Bull
{
    struct BULL_RENDER_API VertexArray : public ArrayList<Vertex>
    {
        /*! \brief Default constructor
         *
         */
        VertexArray() = default;

        /*! \brief Constructor
         *
         * \param list Vertices to copy
         *
         */
        VertexArray(std::initializer_list<Vertex> list);

        /*! \brief Constructor
         *
         * \param polygon The Polygon to copy
         * \param color   The Color of the Polygon
         *
         */
        explicit VertexArray(const Polygon<float>& polygon, const Color& color = Color::White);
    };
}

#endif // BULL_RENDER_VERTEX_VERTEXARRAY_HPP
