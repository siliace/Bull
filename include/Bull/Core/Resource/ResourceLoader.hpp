#ifndef BULL_CORE_LOADER_RESOURCELOADER_HPP
#define BULL_CORE_LOADER_RESOURCELOADER_HPP

#include <list>
#include <memory>

#include <Bull/Core/Resource/AbstractResourceLoader.hpp>
#include <Bull/Core/Pattern/Singleton.hpp>

namespace Bull
{
    template <typename T, typename P>
    class BULL_CORE_API ResourceLoader : public Singleton<ResourceLoader<T, P>>
    {
    public:

        /*! \brief Load a Resource from a Path
         *
         * \param resource   The Resource to load
         * \param path       The Path of the File to read
         * \param parameters Parameters to use to load the Resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        bool loadFromPath(T* resource, const Path& path, const P& parameters) const;

        /*! \brief Load a Resource from a stream
         *
         * \param resource   The Resource to load
         * \param stream     The stream to read
         * \param parameters Parameters to use to load the Resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        bool loadFromStream(T* resource, InStream& stream, const P& parameters) const;

        /*! \brief Load a Resource from a memory area
         *
         * \param resource   The Resource to load
         * \param data       Data to read
         * \param length     The length of data
         * \param parameters Parameters to use to load the Resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        bool loadFromMemory(T* resource, const void* data, std::size_t length, const P& parameters) const;

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
         */
        template <typename L>
        void registerLoader();

    private:

        using LoaderPtr = std::unique_ptr<AbstractResourceLoader<T, P>>;

        std::list<LoaderPtr> m_loaders;
    };
}

#include <Bull/Core/Resource/ResourceLoader.inl>

#endif // BULL_CORE_LOADER_RESOURCELOADER_HPP
