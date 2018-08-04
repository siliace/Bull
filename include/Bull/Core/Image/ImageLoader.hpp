#ifndef BULL_CORE_IMAGE_IMAGELOADER_HPP
#define BULL_CORE_IMAGE_IMAGELOADER_HPP

#include <mutex>

#include <Bull/Core/Assets/AsyncAssetLoader.hpp>
#include <Bull/Core/Image/Image.hpp>

namespace Bull
{
    class BULL_CORE_API ImageLoader : public AsyncAssetLoader<Image>
    {
    public:

        struct ImageInfo
        {
            Size  size;
            Uint8 channels;
        };

    private:

        /*! \brief Read data from a stream
         *
         * \param user The stream to read
         * \param data The buffer to fill
         * \param size The number of bytes to read
         *
         * \return The number of bytes read
         *
         */
        static int read(void* user, char* data, int size);

        /*! \brief Skip bytes
         *
         * \param user The stream
         * \param n    The number of bytes to skip
         *
         */
        static void skip(void* user, int n);

        /*! \brief Tell whether the stream is at its end
         *
         * \param user The stream
         *
         * \return 1 if the stream is at its end, 0 otherwise
         *
         */
        static int eof(void* user);

    public:

        /*! \brief Read the width, the height and the number of channels of and Image on disk
         *
         * \param path The Path of the Image
         *
         * \return The ImageInfo
         *
         */
        ImageInfo getInfo(const Path& path) const;

        /*! \brief Read the width, the height and the number of channels of and Image from a stream
         *
         * \param stream The stream to read
         *
         * \return The ImageInfo
         *
         */
        ImageInfo getInfo(InStream& stream) const;

        /*! \brief Read the width, the height and the number of channels of and Image from a memory area
         *
         * \param data   Data to read
         * \param length The length of the data
         *
         * \return The ImageInfo
         *
         */
        ImageInfo getInfo(const void* data, std::size_t length) const;

        /*! \brief Load an Image from a File
         *
         * \param image The Image to load
         * \param path  The Path of the File to read
         *
         * \return The loaded Image
         *
         */
        Image loadFromPath(const Path& path) const override;

        /*! \brief Load an Image from an InStream
         *
         * \param image  The Image to load
         * \param stream The InStream to read
         *
         * \return The loaded Image
         *
         */
        Image loadFromStream(InStream& stream) const override;

        /*! \brief Load a Image from a memory area
         *
         * \param image  The Image to load
         * \param path   Data to read
         * \param length The length of data to read
         *
         * \return The loaded Image
         *
         */
        Image loadFromMemory(const void* data, std::size_t length) const override;

    private:

        /*! \brief Get the last loading error message
         *
         * \return The error message
         *
         */
        String getErrorMessage() const;

        /*! \brief Create an Image from a buffer of pixels
         *
         * \param buffer   The buffer that contains the pixels of the image
         * \param width    The width in pixel of the image
         * \param height   The height in pixel of the image
         * \param channels The number of channels per pixel
         *
         * \return The created Image
         *
         */
        Image createImage(const unsigned char* buffer, int width, int height, int channels) const;

    private:

        mutable std::mutex m_mutex;
    };
}

#endif // BULL_CORE_IMAGE_IMAGELOADER_HPP
