#include <Bull/Render/Vertex/VertexArray.hpp>

namespace Bull
{
    VertexArray VertexArray::createPolygon(const Polygon<float>& polygon, const Color& color, const Vector3F& normal, float depth)
    {
        VertexArray vertices;
        Vector4F colorVector = Vector4F::makeFromColor(color);

        for(std::size_t i = 0; i < polygon.getVertexCount(); i++)
        {
            Vertex vertex;
            {
                vertex.position = polygon.getVertex(i);
                vertex.position.z() = depth;
                vertex.color = colorVector;
                vertex.texCoord = Vector2F::Zero;
                vertex.normal = normal;
            }

            vertices.add(vertex);
        }

        return vertices;
    }

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

    void VertexArray::add(const Vertex& vertex)
    {
        m_vertices.push_back(vertex);
    }

    std::size_t VertexArray::getSize() const
    {
        return m_vertices.size();
    }

    Vertex* VertexArray::getBuffer()
    {
        return m_vertices.data();
    }

    const Vertex* VertexArray::getBuffer() const
    {
        return m_vertices.data();
    }
}