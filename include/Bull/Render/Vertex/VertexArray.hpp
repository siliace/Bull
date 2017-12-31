#ifndef BULL_RENDER_VERTEX_VERTEXARRAY_HPP
#define BULL_RENDER_VERTEX_VERTEXARRAY_HPP

#include <vector>

#include <Bull/Core/Utility/Color.hpp>

#include <Bull/Math/Polygon/Polygon.hpp>

#include <Bull/Render/Vertex/Vertex.hpp>

namespace Bull
{
    class BULL_RENDER_API VertexArray
    {
    public:

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

        /*! \brief Add a Vertex in the VertexArray
         *
         * \param vertex The Vertex to add
         *
         */
        void addVertex(const Vertex& vertex);

        /*! \brief Get the number of Vertex in the VertexArray
         *
         * \return The number of Vertex
         *
         */
        std::size_t getVertexCount() const;

        /*! \brief Access operator
         *
         * \param index The index of the Vertex to get
         *
         * \return The Vertex
         *
         */
        Vertex& operator[](std::size_t index);

        /*! \brief Access operator
         *
         * \param index The index of the Vertex to get
         *
         * \return The Vertex
         *
         */
        const Vertex& operator[](std::size_t index) const;

    private:

        std::vector<Vertex> m_vertices;
    };
}

#endif // BULL_RENDER_VERTEX_VERTEXARRAY_HPP
