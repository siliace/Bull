#ifndef BULL_CORE_LOADER_ABSTRACTRESOURCELOADER_HPP
#define BULL_CORE_LOADER_ABSTRACTRESOURCELOADER_HPP

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/IO/InStream.hpp>
#include <Bull/Core/Resource/ParameterBag.hpp>

namespace Bull
{
    template <typename T, typename P = ParameterBag>
    struct BULL_CORE_API AbstractResourceLoader
    {
        /*! \brief Load a Resource from a Path
         *
         * \param resource   The Resource to load
         * \param path       The Path of the File to read
         * \param parameters Parameters to use to load the Resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        virtual bool loadFromPath(T* resource, const Path& path, const P& parameters) const = 0;

        /*! \brief Load a Resource from a stream
         *
         * \param resource   The Resource to load
         * \param stream     The stream to read
         * \param parameters Parameters to use to load the Resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        virtual bool loadFromStream(T* resource, InStream& stream, const P& parameters) const = 0;

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
        virtual bool loadFromMemory(T* resource, const void* data, std::size_t length, const P& parameters) const = 0;

        /*! \brief Tell whether the extension is supported
         *
         * \param extension The extension to check
         *
         * \return True if the extension is supported
         *
         */
        virtual bool isFormatSupported(const String& extension) const = 0;

        /*! \brief Tell whether parameters are supported
         *
         * \param parameters Parameters to check
         *
         * \return True if the parameters are supported
         *
         */
        virtual bool isParametersSupported(const P& parameters) const = 0;
    };
}

#endif // BULL_CORE_LOADER_ABSTRACTRESOURCELOADER_HPP
