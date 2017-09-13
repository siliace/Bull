#ifndef BULL_CORE_LOADER_ABSTRACTRESOURCESAVER_HPP
#define BULL_CORE_LOADER_ABSTRACTRESOURCESAVER_HPP

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/IO/OutStream.hpp>
#include <Bull/Core/Loader/ParameterBag.hpp>

namespace Bull
{
    template <typename T, typename P = ParameterBag>
    struct BULL_CORE_API AbstractResourceSaver
    {
        /*! \brief Tell whether a file extension is supported
         *
         * \param extension The extension
         *
         * \return True if the extension is supported
         *
         */
        virtual bool isSupportedExtension(const String& extension) const = 0;

        /*! \brief Save a Resource to a file
         *
         * \param resource The Resource to save
         * \param path     The Path to save the Resource
         *
         * \return True if the Resource was saved successfully
         *
         */
        virtual bool saveToPath(const T& resource, const Path& path, const P& parameters) const = 0;

        /*! \brief Save a Resource to a stream
         *
         * \param resource The Resource to save
         * \param stream
         *
         * \return True if the Resource was saved successfully
         *
         */
        virtual bool saveToStream(const T& resource, OutStream& stream, const P& parameters) const = 0;

        /*! \brief Save a Resource to a memory area
         *
         * \param resource The Resource to save
         * \param data
         *
         * \return True if the Resource was saved successfully
         *
         */
        virtual bool saveToMemory(const T& resource, void* data, Index length, const P& parameters) const = 0;
    };
}

#endif // BULL_CORE_LOADER_ABSTRACTRESOURCESAVER_HPP
