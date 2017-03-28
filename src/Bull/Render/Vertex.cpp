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

    Vertex::Vertex(const Vector3F& position, const Color& color, const Vector2F& texCoord) :
        Vertex(position, Vector4F(color.red, color.green, color.blue, color.alpha), texCoord)
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