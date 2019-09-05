#include <Bull/Core/IO/InStream.hpp>

namespace Bull
{
    InStream::~InStream() = default;

    InStream::operator bool() const
    {
        return !isAtEnd();
    }
}
