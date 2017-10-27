#ifndef BULL_CORE_MEMORY_MOVABLEPTR_HPP
#define BULL_CORE_MEMORY_MOVABLEPTR_HPP

#include <Bull/Core/Export.hpp>
#include <Bull/Core/Meta/TypeTrait.hpp>

namespace Bull
{
    template <typename T>
    class BULL_CORE_API MovablePtr
    {
    public:

        /*! \brief Default constructor
         *
         */
        MovablePtr() :
            m_pointer(nullptr)
        {
            /// Nothing
        }

        /*! \brief Constructor
         *
         * \param pointer The pointer to handle
         *
         */
        template <typename U, typename = EnableIfBaseOf<T, U>>
        explicit MovablePtr(U* pointer) :
            m_pointer(pointer)
        {
            /// Nothing
        }

        /*! \brief Constructor by moving semantic
         *
         * \param move The pointer to move
         *
         */
        template <typename U, typename = EnableIfBaseOf<T, U>>
        explicit MovablePtr(MovablePtr<U>&& move) noexcept :
            m_pointer(move.get())
        {
            move.reset();
        }

        /*! \brief Basic assignment nullptr operator
         *
         * \return This
         *
         */
        MovablePtr<T>& operator=(std::nullptr_t)
        {
            m_pointer = nullptr;

            return (*this);
        }

        /*! \brief Basic assignment operator
         *
         * \param pointer The pointer to handle
         *
         * \return This
         *
         */
        template <typename U, typename = EnableIfBaseOf<T, U>>
        MovablePtr<T>& operator=(U* pointer)
        {
            m_pointer = pointer;

            return (*this);
        }

        /*! \brief Basic assignment operator by moving semantic
         *
         * \param move The pointer to move
         *
         * \return This
         *
         */
        template <typename U, typename = EnableIfBaseOf<T, U>>
        MovablePtr<T>& operator=(MovablePtr<U>&& move) noexcept
        {
            std::swap(get(), move.get());

            return (*this);
        }

        /*! \brief Set the handled pointer to nullptr
         *
         */
        void reset()
        {
            m_pointer = nullptr;
        }

        /*! \brief Get the pointer handled
         *
         * \return The pointer
         *
         */
        T* get() const
        {
            return m_pointer;
        }

        /*! \brief Get the pointer handled
         *
         * \return The pointer
         *
         */
        T* operator->() const
        {
            return get();
        }

        /*! \brief Tell whether the handled pointer is null
         *
         * \return True if the handled pointer is null
         *
         */
        operator bool() const
        {
            return get() != nullptr;
        }

        /*! \brief Cast the MovablePtr to its raw type
         *
         * \return The pointer
         *
         */
        explicit operator T*() const
        {
            return get();
        }

    private:

        T* m_pointer;
    };
}

namespace std
{
    template <typename T, typename U>
    void swap(Bull::MovablePtr<T>& left, Bull::MovablePtr<U>& right)
    {
        std::swap(left.get(), right.get());
    }

    template <typename T, typename U>
    void swap(Bull::MovablePtr<T>& left, U* right)
    {
        std::swap(left.get(), right);
    }

    template <typename T, typename U>
    void swap(T* left, Bull::MovablePtr<U>& right)
    {
        std::swap(left, right.get());
    }
}

#endif // BULL_CORE_MEMORY_MOVABLEPTR_HPP
