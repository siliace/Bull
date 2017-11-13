#include <Bull/Core/Memory/ByteVector.hpp>

namespace Bull
{
    ByteVector::ByteVector(std::size_t size) :
        ByteVector(size, 0)
    {
        /// Nothing
    }

    ByteVector::ByteVector(std::size_t size, Uint8 value) :
        MemoryVector<Uint8>(size, value)
    {
        /// Nothing
    }

    String ByteVector::toString() const
    {
        return String(reinterpret_cast<const char*>(getBuffer(), getCapacity()));
    }
}