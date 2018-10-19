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
        virtual std::future<std::shared_ptr<T>> loadFromPathAsync(const Path& path, Args... args) const
        {
            return std::async([this, &path, &args...]() -> std::shared_ptr<T> {
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
        virtual std::future<std::shared_ptr<T>> loadFromStreamAsync(InStream& stream, Args... args) const
        {
            return std::async([this, &stream, &args...]() -> std::shared_ptr<T> {
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
        virtual std::future<std::shared_ptr<T>> loadFromMemoryAsync(const void* data, std::size_t length, Args... args) const
        {
            return std::async([this, data, length, &args...]() -> std::shared_ptr<T> {
                return this->loadFromMemory(data, length, args...);
            });
        }
    };
}

#endif // BULL_CORE_ASSET_ASYNCASSETLOADER_HPP
