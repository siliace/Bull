namespace Bull
{
    /*! \brief Get the instance of the singleton
     *
     * \param Return the instance of the singleton
     *
     */
    template <typename TChild>
    std::shared_ptr<TChild> Singleton<TChild>::get()
    {
        if(!m_instance.get())
        {
            m_mutex.lock();

            if(!m_instance.get())
            {
                m_instance = std::make_shared<TChild>();
            }

            m_mutex.unlock();
        }

        return m_instance;
    }
}
