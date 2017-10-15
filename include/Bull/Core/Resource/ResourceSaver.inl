namespace Bull
{
    template <typename T, typename P>
    bool ResourceSaver<T, P>::saveToPath(const T* resource, const Path& path, const P& parameters) const
    {
        for(const SaverPtr& saver: m_savers)
        {
            if(saver->isParametersSupported(parameters) || saver->isFormatSupported(path.getFileExtension()))
            {
                return saver->saveToPath(resource, path, parameters);
            }
        }

        return false;
    }

    template <typename T, typename P>
    bool ResourceSaver<T, P>::saveToStream(const T* resource, OutStream& stream, const P& parameters) const
    {
        for(const SaverPtr& saver: m_savers)
        {
            if(saver->isParametersSupported(parameters))
            {
                return saver->saveToStream(resource, stream, parameters);
            }
        }

        return false;
    }

    template <typename T, typename P>
    bool ResourceSaver<T, P>::saveToMemory(const T* resource, void* data, Index length, const P& parameters) const
    {
        for(const SaverPtr& saver: m_savers)
        {
            if(saver->isParametersSupported(parameters))
            {
                return saver->saveToMemory(resource, data, length, parameters);
            }
        }

        return false;
    }

    template <typename T, typename P>
    bool ResourceSaver<T, P>::isFormatSupported(const String& extension) const
    {
        for(const SaverPtr& saver : m_savers)
        {
            if(saver->isExtensionSupported(extension))
            {
                return true;
            }
        }

        return false;
    }

    template <typename T, typename P>
    template <typename S>
    void ResourceSaver<T, P>::registerSaver()
    {
        m_savers.emplace_back(std::make_unique<S>());
    }
}