#ifndef BULL_CORE_LOADER_ABSTRACTLOADER_HPP
#define BULL_CORE_LOADER_ABSTRACTLOADER_HPP

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/IO/InStream.hpp>

namespace Bull
{
    template <typename T>
    struct BULL_CORE_API AbstractResourceLoader
    {
        /*! \brief Tell whether a file extension is supported
         *
         * \param extension The extension
         *
         * \return True if the extension is supported
         *
         */
        virtual bool isSupportedExtension(const String& extension) const = 0;

        /*! \brief Load a Resource from a Path
         *
         * \param resource The Resource to load
         * \param path     The path
         *
         * \return True if the Resource was loaded successfully
         *
         */
        virtual bool loadFromPath(std::unique_ptr<T>& resource, const Path& path) const = 0;

        /*! \brief Load a Resource from a Path
         *
         * \param resource The Resource to load
         * \param stream   The stream to read to load
         *
         * \return True if the Resource was loaded successfully
         *
         */
        virtual bool loadFromStream(std::unique_ptr<T>& resource, InStream& stream) const = 0;

        /*! \brief Load a Resource from a memory area
         *
         * \param resource The Resource to load
         * \param data     The memory
         * \param length   The length of data
         *
         * \return True if the Resource was loaded successfully
         *
         */
        virtual bool loadFromMemory(std::unique_ptr<T>& resource, const void* data, Index length) const = 0;
    };
}

#endif // BULL_CORE_LOADER_ABSTRACTLOADER_HPP
