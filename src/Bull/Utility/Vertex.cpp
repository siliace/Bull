#include <Bull/Utility/Vertex.hpp>

namespace Bull
{
    Vertex::Vertex(const Vector3F& position) :
        position(position)
    {
        /// Nothing
    }

    Vertex::Vertex(const Vector3F& position, const Vector2F& texCoord) :
        position(position),
        texCoord(texCoord)
    {
        /// Nothing
    }

    Vertex::Vertex(const Vector3F& position, const Vector2F& texCoord, const Vector3F& normal) :
        position(position),
        texCoord(texCoord),
        normal(normal)
    {
        /// Nothing
    }

    Vertex::Vertex(const Vector3F& position, const Vector4F& color, const Vector2F& texCoord, const Vector3F& normal) :
        position(position),
        color(color),
        texCoord(texCoord),
        normal(normal)
    {
        /// Nothing
    }

    bool Vertex::operator==(const Vertex& right) const
    {
        return position == right.position &&
               color    == right.color    &&
               texCoord == right.texCoord &&
               normal   == right.normal;
    }

    bool Vertex::operator!=(const Vertex& right) const
    {
        return !((*this) == right);
    }
}