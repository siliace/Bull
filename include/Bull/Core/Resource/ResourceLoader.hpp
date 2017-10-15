#ifndef BULL_CORE_LOADER_RESOURCELOADER_HPP
#define BULL_CORE_LOADER_RESOURCELOADER_HPP

#include <list>
#include <memory>

#include <Bull/Core/Export.hpp>
#include <Bull/Core/Resource/AbstractResourceLoader.hpp>
#include <Bull/Core/Pattern/Singleton.hpp>

namespace Bull
{
    template <typename T, typename P>
    class BULL_CORE_API ResourceLoader : public Singleton<ResourceLoader<T, P>>
    {
    public:

        /*! \brief Save a Resource to path
         *
         * \param resource
         * \param path
         * \param parameters
         *
         * \return
         *
         */
        bool loadFromPath(T* resource, const Path& path, const P& parameters) const;

        /*! \brief Save a Resource to stream
         *
         * \param resource
         * \param stream
         * \param parameters
         *
         * \return
         *
         */
        bool loadFromStream(T* resource, InStream& stream, const P& parameters) const;

        /*! \brief Save a Resource to a memory area
         *
         * \param resource
         * \param data
         * \param length
         * \param parameters
         *
         * \return
         *
         */
        bool loadFromMemory(T* resource, const void* data, Index length, const P& parameters) const;

        /*! \brief Tell whether the extension is supported
         *
         * \param extension The extension to check
         *
         * \return True if the extension is supported
         *
         */
        bool isFormatSupported(const String& extension) const;

        /*! \brief Register a saver
         *
         * \param args Arguments to use to create the saver
         *
         */
        template <typename L, typename... Args>
        L& registerLoader(Args&&... args);

    private:

        using LoaderPtr = std::unique_ptr<AbstractResourceLoader<T, P>>;

        std::list<LoaderPtr> m_loaders;
    };
}

#include <Bull/Core/Resource/ResourceLoader.inl>

#endif // BULL_CORE_LOADER_RESOURCELOADER_HPP
