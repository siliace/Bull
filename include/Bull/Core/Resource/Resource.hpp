#ifndef BULL_CORE_LOADER_RESOURCE_HPP
#define BULL_CORE_LOADER_RESOURCE_HPP

#include <Bull/Core/Export.hpp>
#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/IO/InStream.hpp>
#include <Bull/Core/IO/OutStream.hpp>
#include <Bull/Core/Resource/ParameterBag.hpp>

namespace Bull
{
    template <typename P = ParameterBag>
    struct BULL_CORE_API Resource
    {
        /*! \brief Load a Resource from a Path
         *
         * \param path       The Path of the file to read
         * \param parameters Parameters to load the Resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        virtual bool loadFromPath(const Path& path, const P& parameters) = 0;

        /*! \brief Load a Resource from an InStream
         *
         * \param stream     The stream to read
         * \param parameters Parameters to load the Resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        virtual bool loadFromStream(InStream& stream, const P& parameters) = 0;

        /*! \brief Load a Resource from a memory area
         *
         * \param data       The memory area to read
         * \param length     The length of the memory area
         * \param parameters Parameters to load the Resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        virtual bool loadFromMemory(const void* data, std::size_t length, const P& parameters) = 0;

        /*! \brief Save the Resource to a Path
         *
         * \param path       The path of the
         * \param parameters Parameters to save the Resource
         *
         * \return True if the Resource was saved successfully
         *
         */
        virtual bool saveToPath(const Path& path, const P& parameters) const = 0;

        /*! \brief Save the Resource to a stream
         *
         * \param stream     The stream to write
         * \param parameters Parameters to save the Resource
         *
         * \return True if the Resource was saved successfully
         *
         */
        virtual bool saveToStream(OutStream& stream, const P& parameters) const = 0;

        /*! \brief Save the Resource to a Path
         *
         * \param data       The memory to write
         * \param length     The length of the memory area
         * \param parameters Parameters to save the Resource
         *
         * \return True if the Resource was saved successfully
         *
         */
        virtual bool saveToMemory(void* data, std::size_t length, const P& parameters) const = 0;
    };
}

#endif // BULL_CORE_LOADER_RESOURCE_HPP
