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

    ByteArray& ByteArray::resize(std::size_t size)
    {
        m_array.resize(size);

        return (*this);
    }

    ByteArray& ByteArray::clear(bool keepMemory)
    {
        if(keepMemory)
        {
            std::fill(m_array.begin(), m_array.end(), 0);
        }
        else
        {
            m_array.clear();
        }

        return (*this);
    }

    bool ByteArray::isEmpty() const
    {
        return getSize() == 0;
    }

    std::size_t ByteArray::getSize() const
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
        RangeCheck(index, getSize());

        return m_array[index];
    }

    const Uint8& ByteArray::operator[](std::size_t index) const
    {
        RangeCheck(index, getSize());

        return m_array[index];
    }

    String ByteArray::toString() const
    {
        return String(reinterpret_cast<const char*>(m_array.data()), getSize());
    }
}