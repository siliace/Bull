#include <Bull/Core/Memory/ByteArray.hpp>

namespace Bull
{
    ByteArray::ByteArray(Index size) :
        ByteArray(size, 0)
    {
        /// Nothing
    }

    ByteArray::ByteArray(Index size, Uint8 value) :
        Array<Uint8>(size, value)
    {
        /// Nothing
    }

    String ByteArray::toString() const
    {
        return String(reinterpret_cast<const char*>(getBuffer(), getCapacity()));
    }
}