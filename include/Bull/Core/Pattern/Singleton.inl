namespace Bull
{
    template<typename TChild>
    template<typename... Args>
    std::unique_ptr<TChild>& Singleton<TChild>::get(Args... args)
    {
        if(!s_instance.get())
        {
            s_mutex.lock();

            if(!s_instance.get())
            {
                s_instance = std::make_unique<TChild>(args...);
            }

            s_mutex.unlock();
        }

        return s_instance;
    }

    template<typename TChild>
    std::unique_ptr<TChild>& Singleton<TChild>::getIfExists()
    {
        return isSet() ? s_instance : nullptr;
    }

    template <typename TChild>
    bool Singleton<TChild>::isSet()
    {
        return s_instance.get() != nullptr;
    }

    template <typename TChild>
    void Singleton<TChild>::destroy()
    {
        s_instance.reset(nullptr);
    }
}
