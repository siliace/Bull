#include <Bull/Core/IO/CursorAwareInStream.hpp>

namespace Bull
{
    void CursorAwareInStream::skip(std::size_t length)
    {
        setCursor(getCursor() + length);
    }

    bool CursorAwareInStream::isAtEnd() const
    {
        return getCursor() >= getSize();
    }
}