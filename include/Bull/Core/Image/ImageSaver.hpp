#ifndef BULL_CORE_IMAGE_IMAGESAVER_HPP
#define BULL_CORE_IMAGE_IMAGESAVER_HPP

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/Image/ImageFormat.hpp>
#include <Bull/Core/Image/Image.hpp>
#include <Bull/Core/IO/OutStream.hpp>

namespace Bull
{
    struct BULL_CORE_API ImageSavingParameters
    {
        int stride         = 0;
        int quality        = 100;
        ImageFormat format = ImageFormat_Png;
    };

    class BULL_CORE_API ImageSaver
    {
    private:

        /*! \brief Write data from stb to an OutStream
         *
         * \param context The stream
         * \param data    Data to write
         * \param size    Length of data
         *
         */
        static void writeToStream(void* context, void* data, int size);

        /*! \brief Write data from stb to a memory area
         *
         * \param context The memory area
         * \param data    Data to write
         * \param size    Length of data
         *
         */
        static void writeToMemory(void* context, void* data, int size);

        struct Buffer
        {
            void*       target;
            std::size_t length;
        };

    public:

        /*! \brief Tell whether an ImageFormat is supported
         *
         * \param format The ImageFormat to test
         *
         * \return True if the ImageFormat is supported
         *
         */
        bool isSupportedFormat(ImageFormat format);

        /*! \brief Save an Image to a File
         *
         * \param image      The Image to save
         * \param path       The Path of the File to write
         * \param parameters Parameters to use to save the Image
         *
         */
        void saveToPath(const Image& image, const Path& path, const ImageSavingParameters& parameters = ImageSavingParameters());

        /*! \brief Save an Image to a stream
         *
         * \param image      The Image to save
         * \param stream     The stream to write
         * \param parameters Parameters to use to save the Image
         *
         */
        void saveToStream(const Image& image, OutStream& stream, const ImageSavingParameters& parameters = ImageSavingParameters());

        /*! \brief Save an Image to a memory area
         *
         * \param image      The Image to save
         * \param data       Data to write
         * \param length     The length of data
         * \param parameters Parameters to use to save the Image
         *
         */
        void saveToMemory(const Image& image, void* data, std::size_t length, const ImageSavingParameters& parameters = ImageSavingParameters());
    };
}

#endif // BULL_CORE_IMAGE_IMAGESAVER_HPP
