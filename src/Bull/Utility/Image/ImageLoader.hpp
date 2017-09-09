#ifndef BULL_IMAGELOADER_HPP
#define BULL_IMAGELOADER_HPP

#include <Bull/Core/Pattern/Singleton.hpp>

#include <Bull/Utility/Image/AbstractImageLoader.hpp>

namespace Bull
{
    namespace prv
    {
        class ImageLoader : public AbstractImageLoader, public Singleton<ImageLoader>
        {
        private:

            /*! \brief Read from user stream into data
             *
             * \param user The user data (InStream)
             * \param data Data to fill
             * \param size Size of data to read
             *
             * \return The amount of bytes read
             *
             */
            static int read(void* user, char* data, int size);

            /*! \brief Skip bytes from the stream
             *
             * \param user The user data (InStream)
             * \param size Size of data to skip
             *
             */
            static void skip(void* user, int size);

            /*! \brief Check if the stream is at the end
             *
             * \param user user The user data (InStream)
             *
             * \return 0 if the stream is end
             *
             */
            static int eof(void* user);

            /*! \brief
             *
             * \param context
             * \param data
             * \param size
             *
             */
            static void writeToStream(void* context, void* data, int size);

            /*! \brief
             *
             * \param context
             * \param data
             * \param size
             *
             */
            static void writeToMemory(void* context, void* data, int size);

            struct Buffer
            {
                void* data;
                Index size;
            };

        public:

            /*! \brief Load an image
             *
             * \param path   The path of the image to load
             * \param pixels Pixels of the loaded image
             * \param size   The size of the loaded image
             *
             * \return True if the image was loaded successfully
             *
             */
            bool loadFromPath(const Path& path, ByteArray& pixels, Vector2UI& size) const override;

            /*! \brief Load an image
             *
             * \param stream The stream to read to load the image
             * \param pixels Pixels of the loaded image
             * \param size   The size of the loaded image
             *
             * \return True if the image was loaded successfully
             *
             */
            bool loadFromStream(InStream& stream, ByteArray& pixels, Vector2UI& size) const override;

            /*! \brief Load an image
             *
             * \param data     Data to read to load the image
             * \param dataSize Size of data
             * \param pixels   Pixels of the loaded image
             * \param size     The size of the loaded image
             *
             * \return True if the image was loaded successfully
             *
             */
            bool loadFromMemory(const void* data, Index dataSize, ByteArray& pixels, Vector2UI& size) const override;

            /*! \brief Save an image
             *
             * \param path   The path of the file to create to save the image
             * \param format The format to use to save the image
             * \param pixels Pixels of the image to save
             * \param size   The size of the image to save
             *
             * \return True if the image was saved successfully
             *
             */
            bool saveToPath(const Path& path, ImageFormat format, const ByteArray& pixels, const Vector2UI& size) const override;

            /*! \brief Save an image
             *
             * \param outStream The stream to fill
             * \param format    The format to use to save the image
             * \param pixels    Pixels of the image to save
             * \param size      The size of the image to save
             *
             * \return True if the image was saved successfully
             *
             */
            bool saveToStream(OutStream& outStream, ImageFormat format, const ByteArray& pixels, const Vector2UI& size) const override;

            /*! \brief Save an image
             *
             * \param data     Data to fill
             * \param dataSize The size of data
             * \param format   The format to use to save the image
             * \param pixels   Pixels of the image to save
             * \param size     The size of the image to save
             *
             * \return True if the image was saved successfully
             *
             */
            bool saveToMemory(void* data, Index dataSize, ImageFormat format, const ByteArray& pixels, const Vector2UI& size) const override;

        private:

            /*! \brief Save an image as .bmp file
             *
             * \param path   The path of the file to create to save the image
             * \param pixels Pixels of the image to save
             * \param size   The size of the image to save
             *
             * \return True if the image was saved successfully
             *
             */
            bool saveBmpToPath(const String& path, const ByteArray& pixels, const Vector2UI& size) const;

            /*! \brief Save an image as .bmp stream
             *
             * \param outStream The stream to fill
             * \param format    The format to use to save the image
             * \param pixels    Pixels of the image to save
             * \param size      The size of the image to save
             *
             * \return True if the image was saved successfully
             *
             */
            bool saveBmpToStream(OutStream& stream, const ByteArray& pixels, const Vector2UI& size) const;

            /*! \brief Save an image as .bmp to a memory area
             *
             * \param data     Data to fill
             * \param dataSize The size of data
             * \param format   The format to use to save the image
             * \param pixels   Pixels of the image to save
             * \param size     The size of the image to save
             *
             * \return True if the image was saved successfully
             *
             */
            bool saveBmpToMemory(void* data, Index dataSize, const ByteArray& pixels, const Vector2UI& size) const;

            /*! \brief Save an image as .png file
             *
             * \param path   The path of the file to create to save the image
             * \param pixels Pixels of the image to save
             * \param size   The size of the image to save
             *
             * \return True if the image was saved successfully
             *
             */
            bool savePngToPath(const String& path, const ByteArray& pixels, const Vector2UI& size) const;

            /*! \brief Save an image as .png stream
             *
             * \param outStream The stream to fill
             * \param format    The format to use to save the image
             * \param pixels    Pixels of the image to save
             * \param size      The size of the image to save
             *
             * \return True if the image was saved successfully
             *
             */
            bool savePngToStream(OutStream& stream, const ByteArray& pixels, const Vector2UI& size) const;

            /*! \brief Save an image as .png to a memory area
             *
             * \param data     Data to fill
             * \param dataSize The size of data
             * \param format   The format to use to save the image
             * \param pixels   Pixels of the image to save
             * \param size     The size of the image to save
             *
             * \return True if the image was saved successfully
             *
             */
            bool savePngToMemory(void* data, Index dataSize, const ByteArray& pixels, const Vector2UI& size) const;

            /*! \brief Save an image as .tga file
             *
             * \param path   The path of the file to create to save the image
             * \param pixels Pixels of the image to save
             * \param size   The size of the image to save
             *
             * \return True if the image was saved successfully
             *
             */
            bool saveTgaToPath(const String& path, const ByteArray& pixels, const Vector2UI& size) const;

            /*! \brief Save an image as .tga stream
             *
             * \param outStream The stream to fill
             * \param format    The format to use to save the image
             * \param pixels    Pixels of the image to save
             * \param size      The size of the image to save
             *
             * \return True if the image was saved successfully
             *
             */
            bool saveTgaToStream(OutStream& stream, const ByteArray& pixels, const Vector2UI& size) const;

            /*! \brief Save an image as .tga to a memory area
             *
             * \param data     Data to fill
             * \param dataSize The size of data
             * \param format   The format to use to save the image
             * \param pixels   Pixels of the image to save
             * \param size     The size of the image to save
             *
             * \return True if the image was saved successfully
             *
             */
            bool saveTgaToMemory(void* data, Index dataSize, const ByteArray& pixels, const Vector2UI& size) const;
        };
    }
}

#endif // BULL_IMAGELOADER_HPP
