namespace Bull
{
    /*! \brief Constructor
     *
     * \param value The value of the local
     *
     */
    template<typename TPtr>
    LocalPtr<TPtr>::LocalPtr(TPtr* value) :
        Local(value)
    {
        /// Nothing
    }

    /*! \brief Basic assignment operator override
     *
     * \param copy The LocalPtr to copy
     *
     * \return Return this after the copy
     *
     */
    template<typename TPtr>
    LocalPtr<TPtr>& LocalPtr<TPtr>::operator=(const LocalPtr<TPtr>& copy)
    {
        set(copy.get());

        return (*this);
    }

    /*! \brief Basic assignment operator override
     *
     * \param value The new value of the local-thread pointer
     *
     * \return Return this after the copy
     *
     */
    template<typename TPtr>
    LocalPtr<TPtr>& LocalPtr<TPtr>::operator=(TPtr* value)
    {
        set(value);

        return (*this);
    }

    /*! \brief unary * operator override
     *
     * \return Return a reference to the local-thread value
     *
     */
    template<typename TPtr>
    TPtr& LocalPtr<TPtr>::operator*() const
    {
        return (*static_cast<TPtr*>(get()));
    }

    /*! \brief -> operator override
     *
     * \return Return the pointer on the local-thread value
     *
     */
    template<typename TPtr>
    TPtr* LocalPtr<TPtr>::operator->() const
    {
        return static_cast<TPtr*>(get());
    }

    /*! \brief Cast operator of the local-thread value to its row type
     *
     * \return Return the pointer on the local-thread value
     *
     */
    template<typename TPtr>
    LocalPtr<TPtr>::operator TPtr*()
    {
        return static_cast<TPtr*>(get());
    }
}
