#ifndef BULL_CORE_ASSET_ASYNCASSETLOADER_HPP
#define BULL_CORE_ASSET_ASYNCASSETLOADER_HPP

#include <future>

#include <Bull/Core/Assets/AssetLoader.hpp>

namespace Bull
{
    template <typename T, typename... Args>
    struct BULL_CORE_API AsyncAssetLoader : public AssetLoader<T, Args...>
    {
        /*! \brief Load an Asset asynchronously from its Path on the file system
         *
         * \param path The Path of the Asset
         * \param args Arguments to use to load the Asset
         *
         * \return A future to the loaded Asset
         *
         */
        virtual std::future<Asset<T>> loadFromPathAsync(const Path& path, Args... args) const
        {
            return std::async([this, &path, &args...]() -> Asset<T> {
                return this->loadFromPath(path, args...);
            });
        }

        /*! \brief Load an Asset asynchronously from an InStream
         *
         * \param stream The InStream to read
         * \param args   Arguments to use to load the Asset
         *
         * \return A future to the loaded Asset
         *
         */
        virtual std::future<Asset<T>> loadFromStreamAsync(InStream& stream, Args... args) const
        {
            return std::async([this, &stream, &args...]() -> Asset<T> {
                return this->loadFromStream(stream, args...);
            });
        }

        /*! \brief Load an Asset asynchronously from a memory area
         *
         * \param data   The memory area
         * \param length The length of the memory area
         * \param args   Arguments to use to load the Asset
         *
         * \return A future to the loaded Asset
         *
         */
        virtual std::future<Asset<T>> loadFromMemoryAsync(const void* data, std::size_t length, Args... args) const
        {
            return std::async([this, data, length, &args...]() -> Asset<T> {
                return this->loadFromMemory(data, length, args...);
            });
        }
    };
}

#endif // BULL_CORE_ASSET_ASYNCASSETLOADER_HPP
