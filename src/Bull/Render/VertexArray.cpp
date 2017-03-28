#include <Bull/Render/VertexArray.hpp>

namespace Bull
{
    VertexArray::VertexArray(const std::vector<Vertex>& vertices) :
        m_vertices(vertices)
    {
        /// Nothing
    }

    Vertex& VertexArray::operator[](std::size_t index)
    {
        return m_vertices.at(index);
    }

    const Vertex& VertexArray::operator[](std::size_t index) const
    {
        return m_vertices.at(index);
    }
}