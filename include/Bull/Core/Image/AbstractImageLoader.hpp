#ifndef BULL_CORE_IMAGE_ABSTRACTIMAGELOADER_HPP
#define BULL_CORE_IMAGE_ABSTRACTIMAGELOADER_HPP

#include <memory>
#include <mutex>

#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/Image/AbstractImage.hpp>
#include <Bull/Core/IO/MemoryStream.hpp>

namespace Bull
{
    class BULL_CORE_API AbstractImageLoader
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
        template <typename T, typename = std::enable_if<std::is_base_of<AbstractImage, T>::value>>
        std::shared_ptr<AbstractImage> loadFromPath(const Path& path, PixelFormat pixelFormat) const
        {
            File file(path, FileOpeningMode_Read);

            return loadFromStream<T>(file, pixelFormat);
        }

        /*! \brief Load an Image from an InStream
         *
         * \param stream      The InStream to read
         * \param pixelFormat The PixelFormat of the Image to create
         *
         * \return The loaded Image
         *
         */
        template <typename T, typename = std::enable_if<std::is_base_of<AbstractImage, T>::value>>
        std::shared_ptr<AbstractImage> loadFromStream(InStream& stream, PixelFormat pixelFormat) const
        {
            std::shared_ptr<AbstractImage> image = std::make_shared<T>(pixelFormat);

            RawImage raw = loadPixelsFromStream(stream, pixelFormat);
            image->create(raw.pixels, raw.size);

            return image;
        }

        /*! \brief Load a Image from a memory area
         *
         * \param path        Data to read
         * \param length      The length of data to read
         * \param pixelFormat The PixelFormat of the Image to create
         *
         * \return The loaded Image
         *
         */
        template <typename T, typename = std::enable_if<std::is_base_of<AbstractImage, T>::value>>
        std::shared_ptr<AbstractImage> loadFromMemory(const void* data, std::size_t length, PixelFormat pixelFormat) const
        {
            MemoryStream memoryStream(data, length);

            return loadFromStream<T>(memoryStream, pixelFormat);
        }

    private:

        struct RawImage
        {
            ByteArray pixels;
            Size size;
            int channels;
        };

        /*! \brief Get the last loading error message
         *
         * \return The error message
         *
         */
        String getErrorMessage() const;

        RawImage loadPixelsFromStream(InStream& stream, PixelFormat pixelFormat) const;

    private:

        mutable std::mutex m_mutex;
    };
}

#endif // BULL_CORE_IMAGE_ABSTRACTIMAGELOADER_HPP
