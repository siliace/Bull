#include <cstring>

#include <Bull/Core/Memory/RangeCheck.hpp>

namespace Bull
{
    template <typename T>
    Array<T>::Array(std::size_t size) :
        Array<T>(size, T())
    {
        /// nothing
    }

    template <typename T>
    Array<T>::Array(std::size_t size, T value) :
        m_array(size, value)
    {
        /// Nothing
    }

    template <typename T>
    bool Array<T>::create(std::size_t capacity)
    {
        if(isEmpty())
        {
            m_array.resize(capacity);

            return true;
        }

        return false;
    }

    template <typename T>
    bool Array<T>::fill(const void* data, std::size_t size, std::size_t offset)
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
    T& Array<T>::at(std::size_t index)
    {
        RangeCheck(index, getCapacity());

        return m_array[index];
    }

    template <typename T>
    const T& Array<T>::at(std::size_t index) const
    {
        RangeCheck(index, getCapacity());

        return m_array[index];
    }


    template <typename T>
    void Array<T>::resize(std::size_t size)
    {
        m_array.resize(size);
    }

    template <typename T>
    void Array<T>::clear()
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
    std::size_t Array<T>::getCapacity() const
    {
        return m_array.size();
    }

    template <typename T>
    T& Array<T>::operator[](std::size_t index)
    {
        return at(index);
    }

    template <typename T>
    const T& Array<T>::operator[](std::size_t index) const
    {
        return at(index);
    }
}
