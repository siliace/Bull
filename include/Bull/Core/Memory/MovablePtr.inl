#include <utility>

namespace Bull
{
    template <typename T>
    MovablePtr<T>::MovablePtr(T* pointer) :
        m_pointer(pointer)
    {
        /// Nothing
    }

    template <typename T>
    MovablePtr<T>::MovablePtr(MovablePtr<T>&& move) noexcept
    {
        std::swap(get(), move.get());
    }

    template <typename T>
    MovablePtr<T>& MovablePtr<T>::operator=(T* pointer)
    {
        std::swap(get(), pointer);

        return (*this);
    }

    template <typename T>
    MovablePtr<T>& MovablePtr<T>::operator=(MovablePtr<T>&& move) noexcept
    {
        std::swap(get(), move.get());

        return (*this);
    }

    template <typename T>
    T* MovablePtr<T>::get() const
    {
        return m_pointer;
    }

    template <typename T>
    T* MovablePtr<T>::operator->() const
    {
        return get();
    }

    template <typename T>
    MovablePtr<T>::operator bool() const
    {
        return m_pointer != nullptr;
    }

    template <typename T>
    MovablePtr<T>::operator T*() const
    {
        return get();
    }
}

namespace std
{
    template <typename T>
    void swap(Bull::MovablePtr<T>& left, Bull::MovablePtr<T>& right)
    {
        swap(left.get(), right.get());
    }

    template <typename T>
    void swap(Bull::MovablePtr<T>& left, T* right)
    {
        swap(left.get(), right);
    }

    template <typename T>
    void swap(T* left, Bull::MovablePtr<T>& right)
    {
        swap(left, right.get());
    }
}