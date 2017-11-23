#ifndef BULL_CORE_PATTERN_IMPLPTR_HPP
#define BULL_CORE_PATTERN_IMPLPTR_HPP

#include <utility>

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

        explicit ImplPtr(T* pointer) :
            m_impl(pointer)
        {
            /// Nothing
        }

        ImplPtr(ImplPtr<T>&& pointer) noexcept
        {
            m_impl = std::move(pointer.m_impl);
        }

        ImplPtr<T>& operator=(ImplPtr<T>&& pointer) noexcept
        {
            m_impl = std::move(pointer.m_impl);

            return (*this);
        }

        bool isValid() const
        {
            return m_impl != nullptr;
        }

        T* get()
        {
            return m_impl;
        }

        const T* get() const
        {
            return m_impl;
        }

        T* operator->()
        {
            return get();
        }

        const T* operator->() const
        {
            return get();
        }

        void reset(T* pointer = nullptr)
        {
            delete m_impl;
            m_impl = pointer;
        }

        operator bool() const
        {
            return isValid();
        }

    private:


        T* m_impl;
    };
}

#endif // BULL_CORE_PATTERN_IMPLPTR_HPP
