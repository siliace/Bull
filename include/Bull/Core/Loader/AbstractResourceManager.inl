#include <Bull/Core/Loader/FailedToLoad.hpp>

namespace Bull
{
    template <typename T, typename S, typename L, typename P>
    T& AbstractResourceManager<T, S, L, P>::castToReference(std::unique_ptr<T>& resource)
    {
        return static_cast<T&>(*resource.get());
    }

    template <typename T, typename S, typename L, typename P>
    bool AbstractResourceManager<T, S, L, P>::registerResource(T* resource, const String& name)
    {
        if(!hasResource(name))
        {
            std::unique_ptr<T> handler(resource);

            m_resources[name] = std::move(handler);

            return true;
        }

        return false;
    }

    template <typename T, typename S, typename L, typename P>
    bool AbstractResourceManager<T, S, L, P>::hasResource(const String& name) const
    {
        return m_resources.find(name) != m_resources.end();
    }

    template <typename T, typename S, typename L, typename P>
    bool AbstractResourceManager<T, S, L, P>::isLoaded(const Path& path) const
    {
        for(const auto& resource : m_resources)
        {
            if(resource.second->getPath().toString() == path.toString())
            {
                return true;
            }
        }

        return false;
    }

    template <typename T, typename S, typename L, typename P>
    Index AbstractResourceManager<T, S, L, P>::loadFromDirectory(Directory& directory, bool recursively, const P& parameters)
    {
        if(directory.isOpen())
        {
            Index oldSize = m_resources.size();

            for(const Path& path : directory.getContent())
            {
                if(path.isFile() && getLoader()->isSupportedExtension(path.getExtension()))
                {
                    String name = path.getFileName();
                    name.replace('.', '_');

                    loadFromPath(path, name, parameters);
                }
                else if(recursively && path.getCurrentDirectory() != "." && path.getCurrentDirectory() != "..")
                {
                    Directory subdir(path);

                    if(subdir.isOpen())
                    {
                        loadFromDirectory(subdir);
                    }
                }
            }

            return m_resources.size() - oldSize;
        }

        return 0;
    }

    template <typename T, typename S, typename L, typename P>
    T& AbstractResourceManager<T, S, L, P>::loadFromPath(const Path& path, const String& name, const P& parameters)
    {
        std::unique_ptr<T> resource = std::make_unique<T>();

        if(path.isFile() && getLoader()->isSupportedExtension(path.getExtension()))
        {
            if(hasResource(name) || isLoaded(path))
            {
                return getResource(name);
            }

            P resolvedParameters = parameters;

            if(resolveParameters(&resolvedParameters, path))
            {
                if(getLoader()->loadFromPath(resource, path, resolvedParameters))
                {
                    return pushResource(name, resource);
                }
            }
        }

        throw FailedToLoad<T>(name, castToReference(resource));
    }

    template <typename T, typename S, typename L, typename P>
    T& AbstractResourceManager<T, S, L, P>::loadFromStream(InStream& stream, const String& name, const P& parameters)
    {
        std::unique_ptr<T> resource = std::make_unique<T>();

        if(hasResource(name))
        {
            return getResource(name);
        }

        P resolvedParameters = parameters;

        Uint64 oldCursor = stream.getCursor();

        if(resolveParameters(&resolvedParameters, stream))
        {
            stream.setCursor(oldCursor); /// The resolver could read from the stream without reset the cursor

            if(getLoader()->loadFromStream(resource, stream, resolvedParameters))
            {
                return pushResource(name, resource);
            }
        }

        throw FailedToLoad<T>(name, castToReference(resource));
    }

    template <typename T, typename S, typename L, typename P>
    T& AbstractResourceManager<T, S, L, P>::loadFromMemory(const void* data, Index length, const String& name, const P& parameters)
    {
        std::unique_ptr<T> resource = std::make_unique<T>();

        if(data && length)
        {
            if(hasResource(name))
            {
                return getResource(name);
            }

            P resolvedParameters = parameters;

            if(resolveParameters(&resolvedParameters, data, length))
            {
                if(getLoader()->loadFromMemory(resource, data, length, resolvedParameters))
                {
                    return pushResource(name, resource);
                }
            }
        }

        throw FailedToLoad<T>(name, castToReference(resource));
    }

    template <typename T, typename S, typename L, typename P>
    std::vector<String> AbstractResourceManager<T, S, L, P>::getResourceList() const
    {
        std::vector<String> keys;

        for(auto& resource : m_resources)
        {
            keys.emplace_back(resource.first);
        }

        return keys;
    }

    template <typename T, typename S, typename L, typename P>
    T& AbstractResourceManager<T, S, L, P>::getResource(const String& name)
    {
        if(!hasResource(name))
        {
            std::unique_ptr<T> resource(getEmptyResource());

            m_resources[name] = std::move(resource);
        }

        return castToReference(m_resources[name]);
    }

    template <typename T, typename S, typename L, typename P>
    bool AbstractResourceManager<T, S, L, P>::saveToPath(const T& resource, const P& parameters)
    {
        return saveToPath(resource, resource.getPath(), parameters);
    };

    template <typename T, typename S, typename L, typename P>
    bool AbstractResourceManager<T, S, L, P>::saveToPath(const T& resource, const Path& path, const P& parameters)
    {
        if(getSaver()->isSupportedExtension(path.getExtension()))
        {
            return getSaver()->saveToPath(resource, path, parameters);
        }

        return false;
    }

    template <typename T, typename S, typename L, typename P>
    bool AbstractResourceManager<T, S, L, P>::saveToStream(const T& resource, OutStream& stream, const P& parameters)
    {
        return getSaver()->saveToStream(resource, stream, parameters);
    }

    template <typename T, typename S, typename L, typename P>
    bool AbstractResourceManager<T, S, L, P>::saveToMemory(const T& resource, void* data, Index length, const P& parameters)
    {
        return getSaver()->saveToMemory(resource, data, length, parameters);
    }

    template <typename T, typename S, typename L, typename P>
    T* AbstractResourceManager<T, S, L, P>::unregisterResource(const String& name)
    {
        m_resources.erase(name);
    }

    template <typename T, typename S, typename L, typename P>
    void AbstractResourceManager<T, S, L, P>::purge()
    {
        m_resources.clear();
    }

    template <typename T, typename S, typename L, typename P>
    bool AbstractResourceManager<T, S, L, P>::resolveParameters(P* parameters, const Path& path) const
    {
        return true;
    }

    template <typename T, typename S, typename L, typename P>
    bool AbstractResourceManager<T, S, L, P>::resolveParameters(P* parameters, InStream& stream) const
    {
        return true;
    }

    template <typename T, typename S, typename L, typename P>
    bool AbstractResourceManager<T, S, L, P>::resolveParameters(P* parameters, const void* data, Index length) const
    {
        return true;
    }

    template <typename T, typename S, typename L, typename P>
    T& AbstractResourceManager<T, S, L, P>::pushResource(const String& name, std::unique_ptr<T>& resource)
    {
        m_resources[name] = std::move(resource);

        return castToReference(m_resources[name]);
    }
}