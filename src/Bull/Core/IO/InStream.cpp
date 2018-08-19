#include <Bull/Core/IO/InStream.hpp>
#include <Bull/Core/Utility/StringUtils.hpp>

namespace Bull
{
    InStream::~InStream() = default;

    InStream::operator bool() const
    {
        return !isAtEnd();
    }
}
