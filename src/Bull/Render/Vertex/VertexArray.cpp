#include <Bull/Render/Vertex/VertexArray.hpp>

namespace Bull
{
    VertexArray::VertexArray(std::size_t size) :
        m_vertices(size)
    {
        /// Nothing
    }

    VertexArray::VertexArray(const std::initializer_list<Vertex>& vertices) :
        m_vertices(vertices)
    {
        /// Nothing
    }

    std::size_t VertexArray::getSize() const
    {
        return m_vertices.size();
    }
}