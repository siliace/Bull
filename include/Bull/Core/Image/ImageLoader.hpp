#ifndef BULL_CORE_IMAGE_IMAGELOADER_HPP
#define BULL_CORE_IMAGE_IMAGELOADER_HPP

#include <mutex>

#include <Bull/Core/Assets/AsyncAssetLoader.hpp>
#include <Bull/Core/Image/Image.hpp>

namespace Bull
{
    class BULL_CORE_API ImageLoader : public AsyncAssetLoader<Image, PixelFormat>
    {
    public:

        /*! \brief Load an Image from a File
         *
         * \param path        The Path of the File to read
         * \param pixelFormat The PixelFormat of the Image to create
         *
         * \return The loaded Image
         *
         */
        std::shared_ptr<Image> loadFromPath(const Path& path, PixelFormat pixelFormat = PixelFormat_Rgb8Alpha8) const override;

        /*! \brief Load an Image from an InStream
         *
         * \param stream      The InStream to read
         * \param pixelFormat The PixelFormat of the Image to create
         *
         * \return The loaded Image
         *
         */
        std::shared_ptr<Image> loadFromStream(InStream& stream, PixelFormat pixelFormat = PixelFormat_Rgb8Alpha8) const override;

        /*! \brief Load a Image from a memory area
         *
         * \param path        Data to read
         * \param length      The length of data to read
         * \param pixelFormat The PixelFormat of the Image to create
         *
         * \return The loaded Image
         *
         */
        std::shared_ptr<Image> loadFromMemory(const void* data, std::size_t length, PixelFormat pixelFormat = PixelFormat_Rgb8Alpha8) const override;

    private:

        /*! \brief Get the last loading error message
         *
         * \return The error message
         *
         */
        String getErrorMessage() const;

    private:

        mutable std::mutex m_mutex;
    };
}

#endif // BULL_CORE_IMAGE_IMAGELOADER_HPP
