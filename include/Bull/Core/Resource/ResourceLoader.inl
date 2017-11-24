namespace Bull
{
    template <typename T, typename P>
    bool ResourceLoader<T, P>::loadFromPath(T* resource, const Path& path, const P& parameters) const
    {
        for(const LoaderPtr& loader : m_loaders)
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
        for(const LoaderPtr& loader : m_loaders)
        {
            if(loader->isParametersSupported(parameters))
            {
                return loader->loadFromStream(resource, stream, parameters);
            }
        }

        return false;
    }

    template <typename T, typename P>
    bool ResourceLoader<T, P>::loadFromMemory(T* resource, const void* data, std::size_t length, const P& parameters) const
    {
        for(const LoaderPtr& loader : m_loaders)
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
    template <typename L>
    void ResourceLoader<T, P>::registerLoader()
    {
        m_loaders.emplace_back(std::make_unique<L>());
    }
}