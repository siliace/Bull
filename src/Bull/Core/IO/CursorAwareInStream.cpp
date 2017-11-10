#include <Bull/Core/IO/CursorAwareInStream.hpp>

namespace Bull
{
    CursorAwareInStream::~CursorAwareInStream() = default;

    bool CursorAwareInStream::isAtEnd() const
    {
        return getCursor() >= getSize();
    }
}