namespace Bull
{
    /*! \brief Create a logger
     *
     * \param args Arguments to use to create the logger
     *
     * \return Return a pointer to the created logger
     *
     */
    template<typename T, typename... Args>
    Log::AbstractLoggerHandler Log::createLogger(Args... args)
    {
        static_assert(std::is_base_of<AbstractLogger, T>::value, "T must inherit of AbstractLogger");

        m_listeners.push_back(std::make_unique<T>(args...));

        return m_listeners.back();
    }
}
