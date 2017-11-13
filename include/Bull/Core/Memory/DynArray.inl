#include <cstring>

namespace Bull
{
    template <typename T>
    DynArray<T>::DynArray() :
        m_capacity(0)
    {
        /// Nothing
    }

    template <typename T>
    DynArray<T>::DynArray(std::size_t capacity)
    {
        create(capacity);
    }

    template <typename T>
    bool DynArray<T>::create(std::size_t capacity)
    {
        if(!isAllocated())
        {
            m_array = std::make_unique<T[]>(capacity);
            m_capacity = capacity;

            return true;
        }

        return false;
    }

    template <typename T>
    bool DynArray<T>::isAllocated() const
    {
        return m_array != nullptr;
    }

    template <typename T>
    bool DynArray<T>::fill(const void* data, std::size_t size, std::size_t offset)
    {
        if(size + offset < getCapacity())
        {
            std::memcpy(m_array[offset], data, size);

            return true;
        }

        return false;
    }

    template <typename T>
    T& DynArray<T>::at(std::size_t index)
    {
        RangeCheck(index, getCapacity());

        return m_array[index];
    }

    template <typename T>
    const T& DynArray<T>::at(std::size_t index) const
    {
        RangeCheck(index, getCapacity());

        return m_array[index];
    }

    template <typename T>
    T& DynArray<T>::operator[](std::size_t index)
    {
        return at(index);
    }

    template <typename T>
    const T& DynArray<T>::operator[](std::size_t index) const
    {
        return at(index);
    }

    template <typename T>
    void DynArray<T>::clear()
    {
        std::fill_n(&m_array[0], getCapacity(), 0);
    }

    template <typename T>
    std::size_t DynArray<T>::getCapacity() const
    {
        return m_capacity;
    }
}