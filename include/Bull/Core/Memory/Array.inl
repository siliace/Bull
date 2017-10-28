#include <cstring>

#include <Bull/Core/Memory/RangeCheck.hpp>

namespace Bull
{
    template <typename T>
    Array<T>::Array(Index size) :
        Array<T>(size, T())
    {
        /// nothing
    }

    template <typename T>
    Array<T>::Array(Index size, T value) :
        m_array(size, value)
    {
        /// Nothing
    }

    template <typename T>
    bool Array<T>::create(Index capacity)
    {
        if(isEmpty())
        {
            m_array.resize(capacity);

            return true;
        }

        return false;
    }

    template <typename T>
    bool Array<T>::fill(const void* data, Index size, Index offset)
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

    template <typename T>
    T& Array<T>::at(Index index)
    {
        RangeCheck(index, getCapacity());

        return m_array[index];
    }

    template <typename T>
    const T& Array<T>::at(Index index) const
    {
        RangeCheck(index, getCapacity());

        return m_array[index];
    }


    template <typename T>
    void Array<T>::resize(Index size)
    {
        m_array.resize(size);
    }

    template <typename T>
    void Array<T>::flush()
    {
        std::fill(m_array.begin(), m_array.end(), 0);
    }

    template <typename T>
    void Array<T>::destroy()
    {
        m_array.clear();
    }

    template <typename T>
    bool Array<T>::isEmpty() const
    {
        return getCapacity() == 0;
    }

    template <typename T>
    const T* Array<T>::getBuffer() const
    {
        return m_array.data();
    }

    template <typename T>
    Index Array<T>::getCapacity() const
    {
        return m_array.size();
    }

    template <typename T>
    T& Array<T>::operator[](Index index)
    {
        return at(index);
    }

    template <typename T>
    const T& Array<T>::operator[](Index index) const
    {
        return at(index);
    }
}
