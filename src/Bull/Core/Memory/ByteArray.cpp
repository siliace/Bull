#include <Bull/Core/Memory/ByteArray.hpp>

namespace Bull
{
    ByteArray::ByteArray(std::size_t size) :
        ByteArray(size, 0)
    {
        /// Nothing
    }

    ByteArray::ByteArray(std::size_t size, Uint8 value) :
        Array<Uint8>(size, value)
    {
        /// Nothing
    }

    String ByteArray::toString() const
    {
        return String(reinterpret_cast<const char*>(getBuffer(), getCapacity()));
    }
}