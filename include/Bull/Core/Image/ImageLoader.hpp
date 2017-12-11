#ifndef BULL_CORE_IMAGE_IMAGELOADER_HPP
#define BULL_CORE_IMAGE_IMAGELOADER_HPP

#include <vector>

#include <Bull/Core/Assets/AssetIOScheduler.hpp>
#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/IO/InStream.hpp>
#include <Bull/Core/Image/AbstractImage.hpp>
#include <Bull/Core/Pattern/Singleton.hpp>
#include <Bull/Core/Thread/Mutex.hpp>

namespace Bull
{
    class BULL_CORE_API ImageLoader : public Singleton<ImageLoader>, public AssetIOScheduler<AbstractImage>
    {
    public:

        struct ImageInfo
        {
            Vector2UI size;
            Uint8     channels;
        };

    private:

        /*! \brief Read data from a stream
         *
         * \param user The stream to read
         * \param data The buffer to fill
         * \param size The numfer of bytes to read
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

        bool getInfo(ImageInfo& info, const Path& path);
        bool getInfo(ImageInfo& info, InStream& stream);
        bool getInfo(ImageInfo& info, const void* data, std::size_t length);

        /*! \brief Load an AbstractImage from a File
         *
         * \param image The AbstractImage to load
         * \param path  The Path of the File to read
         *
         * \return True if the Image started to be loaded
         *
         */
        bool loadFromPath(AbstractImage& image, const Path& path);

        /*! \brief Load an AbstractImage from an InStream
         *
         * \param image  The AbstractImage to load
         * \param stream The InStream to read
         *
         * \return True if the Image started to be loaded
         *
         */
        bool loadFromStream(AbstractImage& image, InStream& stream);

        /*! \brief Load a AbstractImage from a memory area
         *
         * \param image  The AbstractImage to load
         * \param path   Data to read
         * \param length The length of data to read
         *
         * \return True if the Image started to be loaded
         *
         */
        bool loadFromMemory(AbstractImage& image, const void* data, std::size_t length);

    private:

        /*! \brief Get the last loading error message
         *
         * \return The error message
         *
         */
        String getErrorMessage() const;

        /*! \brief Create an AbstractImage from a buffer of pixels
         *
         * \param image    The AbstractImage to load
         * \param buffer   The buffer that contains the pixels of the image
         * \param width    The width in pixel of the image
         * \param height   The height in pixel of the image
         * \param channels The number of channels per pixel
         *
         * \return True if the AbstractImage was created successfully
         *
         */
        bool createImage(AbstractImage& image, const void* buffer, int width, int height, int channels);

        mutable Mutex m_mutex;
    };
}

#endif // BULL_CORE_IMAGE_IMAGELOADER_HPP
