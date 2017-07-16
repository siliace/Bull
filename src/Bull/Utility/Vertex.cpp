#include <Bull/Utility/Vertex.hpp>

namespace Bull
{
    Vertex::Vertex(const Vector3F& position) :
        Vertex(position, Vector4F::Unit, Vector2F::Zero, Vector3F::Zero)
    {
        /// Nothing
    }

    Vertex::Vertex(const Vector3F& position, const Vector2F& texCoord) :
        Vertex(position, Vector4F::Unit, texCoord, Vector3F::Zero)
    {
        /// Nothing
    }

    Vertex::Vertex(const Vector3F& position, const Vector3F& normal) :
        Vertex(position, Vector4F::Unit, Vector2F::Zero, normal)
    {
        /// Nothing
    }

    Vertex::Vertex(const Vector3F& position, const Vector2F& texCoord, const Vector3F& normal) :
        Vertex(position, Vector4F::Unit, texCoord, normal)
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