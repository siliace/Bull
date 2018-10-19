#ifndef BULL_CORE_ASSET_ASSETLOADER_HPP
#define BULL_CORE_ASSET_ASSETLOADER_HPP

#include <memory>

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/IO/InStream.hpp>

namespace Bull
{
    template <typename T, typename... Args>
    struct BULL_CORE_API AssetLoader
    {
        /*! \brief Load an Asset from its Path on the file system
         *
         * \param path The Path of the Asset
         * \param args Arguments to use to load the Asset
         *
         * \return The loaded Asset
         *
         */
        virtual std::shared_ptr<T> loadFromPath(const Path& path, Args... args) const = 0;

        /*! \brief Load an Asset from an InStream
         *
         * \param stream The InStream to read
         * \param args   Arguments to use to load the Asset
         *
         * \return The loaded Asset
         *
         */
        virtual std::shared_ptr<T> loadFromStream(InStream& stream, Args... args) const = 0;

        /*! \brief Load an Asset from a memory area
         *
         * \param data   The memory area
         * \param length The length of the memory area
         * \param args   Arguments to use to load the Asset
         *
         * \return The loaded Asset
         *
         */
        virtual std::shared_ptr<T> loadFromMemory(const void* data, std::size_t length, Args... args) const = 0;
    };
}

#endif // BULL_CORE_ASSET_ASSETLOADER_HPP
