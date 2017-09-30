#include <cstring>

#include <Bull/Core/Memory/ByteArray.hpp>
#include <Bull/Core/Memory/RangeCheck.hpp>

namespace Bull
{
    ByteArray::ByteArray(Index size) :
        ByteArray(size, 0)
    {
        /// Nothing
    }

    ByteArray::ByteArray(Index size, Uint8 value) :
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

            std::memcpy(&m_array[offset], data, size);

            return true;
        }

        return false;
    }

    Uint8& ByteArray::at(Index index)
    {
        RangeCheck(index, getCapacity());

        return m_array[index];
    }

    const Uint8& ByteArray::at(Index index) const
    {
        RangeCheck(index, getCapacity());

        return m_array[index];
    }

    ByteArray& ByteArray::resize(Index size)
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

    const Uint8* ByteArray::getBuffer() const
    {
        return m_array.data();
    }

    Index ByteArray::getCapacity() const
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
        m_array.insert(m_array.end(), right.m_array.begin(), right.m_array.end());

        return (*this);
    }

    ByteArray ByteArray::operator+(const ByteArray& right) const
    {
        return ByteArray((*this)) += right;
    }

    Uint8& ByteArray::operator[](Index index)
    {
        return at(index);
    }

    const Uint8& ByteArray::operator[](Index index) const
    {
        return at(index);
    }

    String ByteArray::toString() const
    {
        return String(reinterpret_cast<const char*>(m_array.data()), getCapacity());
    }
}