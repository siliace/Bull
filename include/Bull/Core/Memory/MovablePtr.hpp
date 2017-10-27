#ifndef BULL_CORE_MEMORY_MOVABLEPTR_HPP
#define BULL_CORE_MEMORY_MOVABLEPTR_HPP

#include <Bull/Core/Export.hpp>

namespace Bull
{
    template <typename T>
    class BULL_CORE_API MovablePtr
    {
    public:

        /*! \brief Constructor
         *
         * \param pointer The pointer to handle
         *
         */
        explicit MovablePtr(T* pointer = nullptr);

        /*! \brief Constructor by moving semantic
         *
         * \param move The pointer to move
         *
         */
        MovablePtr(MovablePtr&& move) noexcept;

        /*! \brief Basic assignment operator
         *
         * \param pointer The pointer to handle
         *
         * \return This
         *
         */
        MovablePtr<T>& operator=(T* pointer);

        /*! \brief Basic assignment operator by moving semantic
         *
         * \param move The pointer to move
         *
         * \return This
         *
         */
        MovablePtr<T>& operator=(MovablePtr&& move) noexcept;

        /*! \brief Get the pointer handled
         *
         * \return The pointer
         *
         */
        T* get() const;

        /*! \brief Get the pointer handled
         *
         * \return The pointer
         *
         */
        T* operator->() const;

        /*! \brief Tell whether the handled pointer is null
         *
         * \return True if the handled pointer is null
         *
         */
        operator bool() const;

        /*! \brief Cast the MovablePtr to its raw type
         *
         * \return The pointer
         *
         */
        explicit operator T*() const;

    private:

        T* m_pointer;
    };
}

namespace std
{
    template <typename T>
    void swap(Bull::MovablePtr<T>& left, Bull::MovablePtr<T>& right);

    template <typename T>
    void swap(Bull::MovablePtr<T>& left, T* right);

    template <typename T>
    void swap(T* left, Bull::MovablePtr<T>& right);
}

#include <Bull/Core/Memory/MovablePtr.inl>

#endif // BULL_CORE_MEMORY_MOVABLEPTR_HPP
