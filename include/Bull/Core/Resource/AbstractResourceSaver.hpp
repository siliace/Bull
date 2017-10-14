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
        /*! \brief Save a Resource to path
         *
         * \param resource
         * \param path
         * \param parameters
         *
         * \return
         *
         */
        virtual bool saveToPath(const T* resource, const Path& path, const P& parameters) const = 0;

        /*! \brief Save a Resource to stream
         *
         * \param resource
         * \param stream
         * \param parameters
         *
         * \return
         *
         */
        virtual bool saveToStream(const T* resource, OutStream& stream, const P& parameters) const = 0;

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
