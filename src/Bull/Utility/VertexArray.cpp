#include <Bull/Render/VertexArray.hpp>

namespace Bull
{
    VertexArray::VertexArray(std::size_t size) :
        m_vertices(size)
    {
        /// Nothing
    }

    VertexArray::VertexArray(const std::vector<Vertex>& vertices) :
        m_vertices(vertices)
    {
        /// Nothing
    }

    void VertexArray::addVertex(const Vertex& vertex)
    {
        m_vertices.push_back(vertex);
    }

    Vertex VertexArray::removeVertex(std::size_t index)
    {
        Vertex vertex = m_vertices.at(index);

        m_vertices.erase(m_vertices.begin() + index);

        return vertex;
    }

    std::size_t VertexArray::getSize() const
    {
        return m_vertices.size();
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