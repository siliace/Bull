#ifndef BULL_CORE_IMAGE_IMAGELOADER_HPP
#define BULL_CORE_IMAGE_IMAGELOADER_HPP

#include <mutex>

#include <Bull/Core/Assets/AssetLoader.hpp>
#include <Bull/Core/Image/AbstractImageLoader.hpp>
#include <Bull/Core/Image/Image.hpp>

namespace Bull
{
    template <typename T>
    class BULL_CORE_API ImageLoader : public AbstractImageLoader, public AssetLoader<T, PixelFormat>
    {
    public:

        /** \brief Load an Image from a File
         *
         * \param path        The Path of the File to read
         * \param pixelFormat The PixelFormat of the Image to create
         *
         * \return The loaded Image
         *
         */
        std::shared_ptr<T> loadFromPath(const Path& path, PixelFormat pixelFormat = PixelFormat_Rgb8Alpha8) const override
        {
            return std::static_pointer_cast<T>(AbstractImageLoader::loadFromPath<T>(path, pixelFormat));
        }

        /** \brief Load an Image from an InStream
         *
         * \param stream      The InStream to read
         * \param pixelFormat The PixelFormat of the Image to create
         *
         * \return The loaded Image
         *
         */
        std::shared_ptr<T> loadFromStream(InStream& stream, PixelFormat pixelFormat = PixelFormat_Rgb8Alpha8) const override
        {
            return std::static_pointer_cast<T>(AbstractImageLoader::loadFromStream<T>(stream, pixelFormat));
        }

        /** \brief Load a Image from a memory area
         *
         * \param path        Data to read
         * \param length      The length of data to read
         * \param pixelFormat The PixelFormat of the Image to create
         *
         * \return The loaded Image
         *
         */
        std::shared_ptr<T> loadFromMemory(const void* data, std::size_t length, PixelFormat pixelFormat = PixelFormat_Rgb8Alpha8) const override
        {
            return std::static_pointer_cast<T>(AbstractImageLoader::loadFromMemory<T>(data, length, pixelFormat));
        }

    };
}

#endif // BULL_CORE_IMAGE_IMAGELOADER_HPP
