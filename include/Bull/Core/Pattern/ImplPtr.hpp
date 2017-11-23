#ifndef BULL_CORE_PATTERN_IMPLPTR_HPP
#define BULL_CORE_PATTERN_IMPLPTR_HPP

#include <algorithm>

#include <Bull/Core/Pattern/NonCopyable.hpp>

namespace Bull
{
    template <typename T>
    class BULL_CORE_API ImplPtr : public NonCopyable
    {
    public:

        /*! \brief Create an ImplPtr
         *
         * \param args Arguments to create the ImplPtr
         *
         * \return The ImplPtr
         *
         */
        template <typename U, typename... Args>
        static ImplPtr<T> make(Args&&... args)
        {
            return ImplPtr<T>(new U(std::forward<Args>(args)...));
        }

    public:

        /*! \brief Default constructor
         *
         */
        ImplPtr() :
            m_impl(nullptr)
        {
            /// Nothing
        }

        /*! \brief Constructor
         *
         * \param pointer The pointer to use
         *
         */
        explicit ImplPtr(T* pointer) :
            m_impl(pointer)
        {
            /// Nothing
        }

        /*! \brief Constructor by movement
         *
         * \param pointer The pointer to move
         *
         */
        ImplPtr(ImplPtr<T>&& pointer) noexcept
        {
            std::swap(m_impl, pointer.m_impl);
        }

        /*! \brief Destructor
         *
         */
        ~ImplPtr()
        {
            reset();
        }

        /*! \brief Basic assignment operator by movement
         *
         * \param pointer The pointer to move
         *
         */
        ImplPtr<T>& operator=(ImplPtr<T>&& pointer) noexcept
        {
            std::swap(m_impl, pointer.m_impl);

            return (*this);
        }

        /*! \brief Tell whether the pointer is valid
         *
         * The pointer is valid if it's not nullptr
         *
         * \return True if the pointer is valid
         *
         */
        bool isValid() const
        {
            return m_impl != nullptr;
        }

        /*! \brief Get the raw pointer
         *
         * \return The raw pointer
         *
         */
        T* get()
        {
            return m_impl;
        }

        /*! \brief Get the raw pointer
         *
         * \return The raw pointer
         *
         */
        const T* get() const
        {
            return m_impl;
        }

        /*! \brief Get the raw pointer
         *
         * \return The raw pointer
         *
         */
        T* operator->()
        {
            return get();
        }

        /*! \brief Get the raw pointer
         *
         * \return The raw pointer
         *
         */
        const T* operator->() const
        {
            return get();
        }

        /*! \brief Delete and change the pointer
         *
         * \param pointer The new pointer to use
         *
         */
        void reset(T* pointer = nullptr)
        {
            delete m_impl;
            m_impl = pointer;
        }

        /*! \brief Tell whether the pointer is valid
         *
         * The pointer is valid if it's not nullptr
         *
         * \return True if the pointer is valid
         *
         * \see isValid
         *
         */
        operator bool() const
        {
            return isValid();
        }

    private:

        T* m_impl;
    };
}

#endif // BULL_CORE_PATTERN_IMPLPTR_HPP
