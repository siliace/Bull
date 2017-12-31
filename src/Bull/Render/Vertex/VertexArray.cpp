#include <Bull/Render/Vertex/VertexArray.hpp>

namespace Bull
{
    VertexArray::VertexArray(std::initializer_list<Vertex> list) :
        m_vertices(list)
    {
        /// Nothing
    }

    VertexArray::VertexArray(const Polygon<float>& polygon, const Color& color) :
        m_vertices(polygon.getVertexCount())
    {
        for(std::size_t i = 0; i < m_vertices.size(); i++)
        {
            Vector2F position = polygon.getVertex(i);

            m_vertices[i].color    = Vector4F::makeFromColor(color);
            m_vertices[i].position = Vector3F(position.x(), position.y(), 0);
        }
    }

    void VertexArray::addVertex(const Vertex& vertex)
    {
        m_vertices.push_back(vertex);
    }

    std::size_t VertexArray::getVertexCount() const
    {
        return m_vertices.size();
    }

    Vertex& VertexArray::operator[](std::size_t index)
    {
        RangeCheck(index, getVertexCount());

        return m_vertices[index];
    }

    const Vertex& VertexArray::operator[](std::size_t index) const
    {
        RangeCheck(index, getVertexCount());

        return m_vertices[index];
    }
}