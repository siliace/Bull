#include <cstring>

#include <Bull/Core/Memory/RangeCheck.hpp>
#include <Bull/Core/Memory/ByteArray.hpp>

namespace Bull
{
    ByteArray::ByteArray(std::size_t size) :
        ByteArray(size, 0)
    {
        /// Nothing
    }

    ByteArray::ByteArray(std::size_t size, Uint8 value) :
        m_array(size, value)
    {
        /// Nothing
    }

    bool ByteArray::create(Index capacity)
    {
        if(isEmpty())
        {
            m_array.resize(capacity);

            return true;
        }

        return false;
    }

    bool ByteArray::fill(const void* data, Index size, Index offset)
    {
        if(data && size)
        {
            if(getCapacity() < size + offset)
            {
                resize(size + offset);
            }

            std::memcpy(&m_array[offset] + offset, data, size);

            return true;
        }

        return false;
    }

    ByteArray& ByteArray::resize(std::size_t size)
    {
        m_array.resize(size);

        return (*this);
    }

    void ByteArray::flush()
    {
        std::fill(m_array.begin(), m_array.end(), 0);
    }

    void ByteArray::destroy()
    {
        m_array.clear();
    }

    bool ByteArray::isEmpty() const
    {
        return getCapacity() == 0;
    }

    std::size_t ByteArray::getCapacity() const
    {
        return m_array.size();
    }

    bool ByteArray::operator==(const ByteArray& right) const
    {
        return m_array == right.m_array;
    }

    bool ByteArray::operator!=(const ByteArray& right) const
    {
        return m_array != right.m_array;
    }

    ByteArray& ByteArray::operator+=(const ByteArray& right)
    {
        return (*this);
    }

    ByteArray ByteArray::operator+(const ByteArray& right) const
    {

    }

    Uint8& ByteArray::operator[](std::size_t index)
    {
        RangeCheck(index, getCapacity());

        return m_array[index];
    }

    const Uint8& ByteArray::operator[](std::size_t index) const
    {
        RangeCheck(index, getCapacity());

        return m_array[index];
    }

    String ByteArray::toString() const
    {
        return String(reinterpret_cast<const char*>(m_array.data()), getCapacity());
    }
}