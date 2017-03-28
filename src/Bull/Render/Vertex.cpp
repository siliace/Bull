#include <Bull/Render/Vertex.hpp>

namespace Bull
{
    Vertex::Vertex(const Vector3F& position, const Vector4F& color, const Vector2F& texCoord) :
        position(position),
        color(color),
        texCoord(texCoord)
    {
        /// Nothing
    }

    bool Vertex::operator==(const Vertex& right)
    {
        return position == right.position &&
               color    == right.color    &&
               texCoord == right.texCoord;
    }

    bool Vertex::operator!=(const Vertex& right)
    {
        return !((*this) == right);
    }
}