#ifndef BULL_CORE_LOADER_ABSTRACTRESOURCESAVER_HPP
#define BULL_CORE_LOADER_ABSTRACTRESOURCESAVER_HPP

#include <Bull/Core/Export.hpp>
#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/IO/OutStream.hpp>
#include <Bull/Core/Resource/ParameterBag.hpp>

namespace Bull
{
    template <typename T, typename P = ParameterBag>
    struct BULL_CORE_API AbstractResourceSaver
    {
        /*! \brief Save a Resource to a Path
         *
         * \param resource      The Resource to save
         * \param path       The Path of the File to write
         * \param parameters Parameters to use to save the Resource
         *
         * \return True if the Resource was saved successfully
         *
         */
        virtual bool saveToPath(const T* resource, const Path& path, const P& parameters) const = 0;

        /*! \brief Save a Resource to stream
         *
         * \param resource      The Resource to save
         * \param stream     The stream to write
         * \param parameters Parameters to use to save the Resource
         *
         * \return True if the Resource was saved successfully
         *
         */
        virtual bool saveToStream(const T* resource, OutStream& stream, const P& parameters) const = 0;

        /*! \brief Save a Resource to a memory area
         *
         * \param resource      The Resource to save
         * \param data       Data to write
         * \param length     The length of data
         * \param parameters Parameters to use to save the Resource
         *
         * \return True if the Resource was saved successfully
         *
         */
        virtual bool saveToMemory(const T* resource, void* data, Index length, const P& parameters) const = 0;

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

#endif // BULL_CORE_LOADER_ABSTRACTRESOURCESAVER_HPP
