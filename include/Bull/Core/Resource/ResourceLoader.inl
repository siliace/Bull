namespace Bull
{
    template <typename T, typename P>
    bool ResourceLoader<T, P>::loadFromPath(T* resource, const Path& path, const P& parameters) const
    {
        for(const LoaderPtr& loader: m_loaders)
        {
            if(loader->isParametersSupported(parameters) || loader->isFormatSupported(path.getFileExtension()))
            {
                return loader->loadFromPath(resource, path, parameters);
            }
        }

        return false;
    }

    template <typename T, typename P>
    bool ResourceLoader<T, P>::loadFromStream(T* resource, InStream& stream, const P& parameters) const
    {
        for(const LoaderPtr& loader: m_loaders)
        {
            if(loader->isParametersSupported(parameters))
            {
                return loader->loadFromStream(resource, stream, parameters);
            }
        }

        return false;
    }

    template <typename T, typename P>
    bool ResourceLoader<T, P>::loadFromMemory(T* resource, const void* data, Index length, const P& parameters) const
    {
        for(const LoaderPtr& loader: m_loaders)
        {
            if(loader->isParametersSupported(parameters))
            {
                return loader->loadFromMemory(resource, data, length, parameters);
            }
        }

        return false;
    }

    template <typename T, typename P>
    bool ResourceLoader<T, P>::isFormatSupported(const String& extension) const
    {
        for(const LoaderPtr& loader : m_loaders)
        {
            if(loader->isFormatSupported(extension))
            {
                return true;
            }
        }

        return false;
    }

    template <typename T, typename P>
    template <typename L, typename... Args>
    L& ResourceLoader<T, P>::registerLoader(Args&&... args)
    {
        LoaderPtr saver = std::make_unique<L>(std::forward<Args>(args)...);
        m_loaders.emplace_back(std::move(saver));

        return static_cast<L&>(*m_loaders.back().get());
    }
}