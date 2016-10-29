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
        if(!m_instance.get())
        {
            m_mutex.lock();

            if(!m_instance.get())
            {
                m_instance = std::make_shared<TChild>(args...);
            }

            m_mutex.unlock();
        }

        return m_instance;
    }

    /*! \brief Get the instance only if exists
     *
     * \return Return the instance is exists, nullptr otherwise
     *
     */
    template<typename TChild>
    std::shared_ptr<TChild> Singleton<TChild>::getIfExists()
    {
        return isSet() ? m_instance : nullptr;
    }

    /*! \brief Check whether the instance is set
     *
     * \param Return true if the instance is set, false otherwise
     *
     */
    template <typename TChild>
    bool Singleton<TChild>::isSet()
    {
        return m_instance.get() != nullptr;
    }
}
