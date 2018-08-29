#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Memory/ByteArray.hpp>
#include <Bull/Core/Memory/RangeCheck.hpp>

namespace Bull
{
    ByteArray ByteArray::fromString(const String& string)
    {
        return memoryCopy(string.getBuffer(), string.getSize());
    }

    ByteArray ByteArray::memoryCopy(const void* data, std::size_t length)
    {
        ByteArray bytes;
        Expect(data && length, Throw(InvalidParameter, "ByteArray::memoryCopy", "Invalid buffer"));

        bytes.create(length);

        std::memcpy(&bytes[0], data, length);

        return bytes;
    }

    ByteArray::ByteArray(std::size_t length) :
        m_array(length)
    {
        /// Nothing
    }

    void ByteArray::create(std::size_t capacity)
    {
        m_array.resize(capacity);
    }

    void ByteArray::fill(const void* data, std::size_t size, std::size_t offset)
    {
        if(m_array.size() < offset + size)
        {
            m_array.resize(offset + size);
        }

        std::memcpy(&m_array[offset], data, size);
    }

    bool ByteArray::isEmpty() const
    {
        return getCapacity() == 0;
    }

    void ByteArray::resize(std::size_t length)
    {
        m_array.resize(length);
    }

    void ByteArray::clear()
    {
        m_array.clear();
    }

    size_t ByteArray::getCapacity() const
    {
        return m_array.size();
    }

    const Uint8* ByteArray::getBuffer() const
    {
        return m_array.data();
    }

    String ByteArray::toString() const
    {
        return String(reinterpret_cast<const char*>(m_array.data()), m_array.size());
    }

    Uint8& ByteArray::operator[](std::size_t index)
    {
        RangeCheck(index, m_array.size());

        return m_array.at(index);
    }

    const Uint8& ByteArray::operator[](std::size_t index) const
    {
        RangeCheck(index, m_array.size());

        return m_array.at(index);
    }

    bool ByteArray::operator==(const ByteArray& right) const
    {
        return m_array == right.m_array;
    }

    bool ByteArray::operator!=(const ByteArray& right) const
    {
        return !(*this == right);
    }
}