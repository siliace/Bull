#include <Bull/Render/Vertex/VertexArray.hpp>

namespace Bull
{
    VertexArray::VertexArray(std::initializer_list<Vertex> list) :
        ArrayList(list)
    {
        /// Nothing
    }

    VertexArray::VertexArray(const Polygon<float>& polygon, const Color& color) :
        ArrayList(polygon.getVertexCount())
    {
        for(std::size_t i = 0; i < getSize(); i++)
        {
            Vector2F position = polygon.getVertex(i);

            at(i).color    = Vector4F::makeFromColor(color);
            at(i).position = Vector3F(position.x(), position.y(), 0);
        }
    }
}