#ifndef BULL_CORE_LOADER_RESOURCESAVER_HPP
#define BULL_CORE_LOADER_RESOURCESAVER_HPP

#include <list>
#include <memory>

#include <Bull/Core/Export.hpp>
#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/IO/OutStream.hpp>
#include <Bull/Core/Resource/AbstractResourceSaver.hpp>
#include <Bull/Core/Resource/Resource.hpp>
#include <Bull/Core/Pattern/Singleton.hpp>

namespace Bull
{
    template <typename T, typename P>
    class BULL_CORE_API ResourceSaver : public Singleton<ResourceSaver<T, P>>
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
        bool saveToPath(const T* resource, const Path& path, const P& parameters) const;

        /*! \brief Save a Resource to stream
         *
         * \param resource
         * \param stream
         * \param parameters
         *
         * \return
         *
         */
        bool saveToStream(const T* resource, OutStream& stream, const P& parameters) const;

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
        bool saveToMemory(const T* resource, void* data, Index length, const P& parameters) const;

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
        template <typename S, typename... Args>
        S& registerSaver(Args&&... args);

    private:

        using SaverPtr = std::unique_ptr<AbstractResourceSaver<T, P>>;

        std::list<SaverPtr> m_savers;
    };
}

#include <Bull/Core/Resource/ResourceSaver.inl>

#endif // BULL_CORE_LOADER_RESOURCESAVER_HPP
