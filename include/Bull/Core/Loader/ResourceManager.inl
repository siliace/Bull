#include <Bull/Core/Loader/FailedToLoad.hpp>

namespace Bull
{
    template <typename T, typename Saver, typename Loader>
    T& ResourceManager<T, Saver, Loader>::castToReference(std::unique_ptr<T>& resource)
    {
        return static_cast<T&>(*resource.get());
    }

    template <typename T, typename Saver, typename Loader>
    bool ResourceManager<T, Saver, Loader>::registerResource(T* resource, const String& name)
    {
        if(!hasResource(name))
        {
            std::unique_ptr<T> handler(resource);

            m_resources[name] = std::move(handler);

            return true;
        }

        return false;
    }

    template <typename T, typename Saver, typename Loader>
    bool ResourceManager<T, Saver, Loader>::hasResource(const String& name) const
    {
        return m_resources.find(name) != m_resources.end();
    }

    template <typename T, typename Saver, typename Loader>
    T& ResourceManager<T, Saver, Loader>::loadFromPath(const Path& path, const String& name, const ParameterBag& parameters)
    {
        std::unique_ptr<T> resource = std::make_unique<T>();

        if(getLoader()->isSupportedExtension(path.getExtension()))
        {
            if(hasResource(name))
            {
                return getResource(name);
            }

            if(getLoader()->loadFromPath(resource, path, parameters))
            {
                return pushResource(name, resource);
            }
        }

        throw FailedToLoad<T>(name, castToReference(resource));
    }

    template <typename T, typename Saver, typename Loader>
    T& ResourceManager<T, Saver, Loader>::loadFromStream(InStream& stream, const String& name, const ParameterBag& parameters)
    {
        std::unique_ptr<T> resource = std::make_unique<T>();

        if(hasResource(name))
        {
            return getResource(name);
        }

        if(getLoader()->loadFromStream(resource, stream, parameters))
        {
            return pushResource(name, resource);
        }

        throw FailedToLoad<T>(name, castToReference(resource));
    }

    template <typename T, typename Saver, typename Loader>
    T& ResourceManager<T, Saver, Loader>::loadFromMemory(const void* data, Index length, const String& name, const ParameterBag& parameters)
    {
        std::unique_ptr<T> resource = std::make_unique<T>();

        if(hasResource(name))
        {
            return getResource(name);
        }

        if(getLoader()->loadFromMemory(resource, data, length, parameters))
        {
            return pushResource(name, resource);
        }

        throw FailedToLoad<T>(name, castToReference(resource));
    }

    template <typename T, typename Saver, typename Loader>
    T& ResourceManager<T, Saver, Loader>::getResource(const String& name)
    {
        if(!hasResource(name))
        {
            std::unique_ptr<T> resource(getEmptyResource());

            m_resources[name] = std::move(resource);
        }

        return castToReference(m_resources[name]);
    }

    template <typename T, typename Saver, typename Loader>
    bool ResourceManager<T, Saver, Loader>::saveToPath(const T& resource, const Path& path)
    {
        return getSaver()->saveToPath(resource, path);
    }

    template <typename T, typename Saver, typename Loader>
    bool ResourceManager<T, Saver, Loader>::saveToStream(const T& resource, OutStream& stream)
    {
        return getSaver()->saveToStream(resource, stream);
    }

    template <typename T, typename Saver, typename Loader>
    bool ResourceManager<T, Saver, Loader>::saveToMemory(const T& resource, void* data, Index length)
    {
        return getSaver()->saveToMemory(resource, data, length);
    }

    template <typename T, typename Saver, typename Loader>
    T* ResourceManager<T, Saver, Loader>::unregisterResource(const String& name)
    {
        m_resources.erase(name);
    }

    template <typename T, typename Saver, typename Loader>
    void ResourceManager<T, Saver, Loader>::purge()
    {
        m_resources.clear();
    }

    template <typename T, typename Saver, typename Loader>
    T& ResourceManager<T, Saver, Loader>::pushResource(const String& name, std::unique_ptr<T>& resource)
    {
        m_resources[name] = std::move(resource);

        return castToReference(m_resources[name]);
    }
}