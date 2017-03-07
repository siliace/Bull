#ifndef Bull_LocalPtr_hpp
#define Bull_LocalPtr_hpp

#include <Bull/Core/Thread/Local.hpp>

namespace Bull
{
    template<typename TPtr>
    class BULL_API LocalPtr : private Local
    {
    public:

        /*! \brief Constructor
         *
         * \param value The value of the local
         *
         */
        LocalPtr(TPtr* value = nullptr);

        /*! \brief Basic assignment operator override
         *
         * \param copy The LocalPtr to copy
         *
         * \return Return this after the copy
         *
         */
        LocalPtr<TPtr>& operator=(const LocalPtr<TPtr>& copy);

        /*! \brief Basic assignment operator override
         *
         * \param value The new value of the local-thread pointer
         *
         * \return Return this after the copy
         *
         */
        LocalPtr<TPtr>& operator=(TPtr* value);

        /*! \brief unary * operator override
         *
         * \return Return a reference to the local-thread value
         *
         */
        TPtr& operator*() const;

        /*! \brief -> operator override
         *
         * \return Return the pointer on the local-thread value
         *
         */
        TPtr* operator->() const;

        /*! \brief Cast operator of the local-thread value to its row type
         *
         * \return Return the pointer on the local-thread value
         *
         */
        operator TPtr*();
    };
}

#include <Bull/Core/Thread/LocalPtr.inl>

#endif // Bull_LocalPtr_hpp
