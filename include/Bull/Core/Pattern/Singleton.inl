namespace Bull
{
    /*! \brief Get the instance of the singleton
     *
     * \param Return the instance of the singleton
     *
     */
    template<typename TChild>
    template<typename... Args>
    std::shared_ptr<TChild> Singleton<TChild>::get(Args... args)
    {
        if(!s_instance.get())
        {
            s_mutex.lock();

            if(!s_instance.get())
            {
                s_instance = std::make_shared<TChild>(args...);
            }

            s_mutex.unlock();
        }

        return s_instance;
    }

    /*! \brief Get the instance only if exists
     *
     * \return Return the instance is exists, nullptr otherwise
     *
     */
    template<typename TChild>
    std::shared_ptr<TChild> Singleton<TChild>::getIfExists()
    {
        return isSet() ? s_instance : nullptr;
    }

    /*! \brief Check whether the instance is set
     *
     * \param Return true if the instance is set, false otherwise
     *
     */
    template <typename TChild>
    bool Singleton<TChild>::isSet()
    {
        return s_instance.get() != nullptr;
    }

    /*! \brief Destroy the instance
     *
     */
    template <typename TChild>
    void Singleton<TChild>::destroy()
    {
        s_instance.reset();
    }
}
