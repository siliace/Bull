#ifndef BULL_CORE_LOADER_RESOURCESAVER_HPP
#define BULL_CORE_LOADER_RESOURCESAVER_HPP

#include <list>
#include <memory>

#include <Bull/Core/Export.hpp>
#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/IO/OutStream.hpp>
#include <Bull/Core/Pattern/Singleton.hpp>
#include <Bull/Core/Resource/AbstractResourceSaver.hpp>

namespace Bull
{
    template <typename T, typename P>
    class BULL_CORE_API ResourceSaver : public Singleton<ResourceSaver<T, P>>
    {
    public:

        /*! \brief Save a Resource to a Path
         *
         * \param resource      The Resource to save
         * \param path       The Path of the File to write
         * \param parameters Parameters to use to save the Resource
         *
         * \return True if the Resource was saved successfully
         *
         */
        bool saveToPath(const T* resource, const Path& path, const P& parameters) const;

        /*! \brief Save a Resource to stream
         *
         * \param resource      The Resource to save
         * \param stream     The stream to write
         * \param parameters Parameters to use to save the Resource
         *
         * \return
         *
         */
        bool saveToStream(const T* resource, OutStream& stream, const P& parameters) const;

        /*! \brief Save a Resource to a memory area
         *
         * \param resource      The Resource to save
         * \param data       Data to write
         * \param length     The length of data
         * \param parameters Parameters to use to save the Resource
         *
         * \return
         *
         */
        bool saveToMemory(const T* resource, void* data, std::size_t length, const P& parameters) const;

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
        template <typename S>
        void registerSaver();

    private:

        using SaverPtr = std::unique_ptr<AbstractResourceSaver<T, P>>;

        std::list<SaverPtr> m_savers;
    };
}

#include <Bull/Core/Resource/ResourceSaver.inl>

#endif // BULL_CORE_LOADER_RESOURCESAVER_HPP
