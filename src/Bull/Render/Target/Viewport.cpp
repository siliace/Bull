#include <Bull/Render/Target/Viewport.hpp>

namespace Bull
{
    Viewport::Viewport(const SizeI& position, const SizeUI& size) :
        position(position),
        size(size)
    {
        /// Nothing
    }

    bool Viewport::operator==(const Viewport& right) const
    {
        return position == right.position && size == right.size;
    }

    bool Viewport::operator!=(const Viewport& right) const
    {
        return !(*this == right);
    }

    void Viewport::move(const SizeI& offset)
    {
        position += offset;
    }
}
