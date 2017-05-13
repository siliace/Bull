namespace Bull
{
    template<typename TChild>
    template<typename... Args>
    TChild* Singleton<TChild>::get(Args... args)
    {
        if(!s_instance)
        {
            Lock lock(s_mutex);

            if(!s_instance)
            {
                s_instance = new TChild(args...);
            }
        }

        return s_instance;
    }

    template<typename TChild>
    TChild* Singleton<TChild>::getIfExists()
    {
        return isSet() ? s_instance : nullptr;
    }

    template <typename TChild>
    bool Singleton<TChild>::isSet()
    {
        return s_instance != nullptr;
    }

    template <typename TChild>
    void Singleton<TChild>::destroy()
    {
        delete s_instance;
        s_instance = nullptr;
    }
}
