#ifndef BULL_CORE_LOADER_ABSTRACTLOADER_HPP
#define BULL_CORE_LOADER_ABSTRACTLOADER_HPP

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/IO/InStream.hpp>
#include <Bull/Core/Loader/ParameterBag.hpp>

namespace Bull
{
    template <typename T, typename Parameters = ParameterBag>
    struct BULL_CORE_API AbstractResourceLoader
    {
        /*! \brief Load a Resource from a Path
         *
         * \param resource   The Resource to load
         * \param path       The path
         * \param parameters Parameters to create the resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        virtual bool loadFromPath(T* resource, const Path& path, const Parameters& parameters) const = 0;

        /*! \brief Load a Resource from a Path
         *
         * \param resource   The Resource to load
         * \param stream     The stream to read to load
         * \param parameters Parameters to create the resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        virtual bool loadFromStream(T* resource, InStream& stream, const Parameters& parameters) const = 0;

        /*! \brief Load a Resource from a memory area
         *
         * \param resource   The Resource to load
         * \param data       The memory
         * \param length     The length of data
         * \param parameters Parameters to create the resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        virtual bool loadFromMemory(T* resource, const void* data, Index length, const Parameters& parameters) const = 0;
    };
}

#endif // BULL_CORE_LOADER_ABSTRACTLOADER_HPP
