#ifndef BULL_CORE_IMAGE_ABSTRACTIMAGESAVER_HPP
#define BULL_CORE_IMAGE_ABSTRACTIMAGESAVER_HPP

#include <future>

#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/Image/AbstractImage.hpp>
#include <Bull/Core/Image/ImageFormat.hpp>
#include <Bull/Core/IO/OutStream.hpp>

namespace Bull
{
    class BULL_CORE_API AbstractImageSaver
    {
    public:

        struct Parameters
        {
            Parameters() = default;

            explicit Parameters(ImageFormat format) :
                format(format)
            {
                /// Nothing
            }

            std::size_t stride  = 0;
            std::size_t quality = 100;
            ImageFormat format  = ImageFormat::Png;
        };

    private:

        /*! \brief
         *
         * \param context
         * \param data
         * \param size
         *
         */
        static void write(void* context, void* data, int size);

    public:

        /*! \brief
         *
         * \param path
         * \param image
         * \param parameters
         *
         * \return
         *
         */
        File saveToPath(const Path& path, const AbstractImage& image, const Parameters& parameters) const;

        /*! \brief
         *
         * \param stream
         * \param image
         * \param parameters
         *
         * \return
         *
         */
        OutStream& saveToStream(OutStream& stream, const AbstractImage& image, const Parameters& parameters) const;

        /*! \brief
         *
         * \param image
         * \param parameters
         *
         * \return
         *
         */
        ByteArray saveToMemory(const AbstractImage& image, const Parameters& parameters) const;

    private:

        void saveToBmp(OutStream& stream, const Size<std::size_t>& size, int channels, const ByteArray& pixels) const;

        void saveToTga(OutStream& stream, const Size<std::size_t>& size, int channels, const ByteArray& pixels) const;

        void saveToPng(OutStream& stream, const Size<std::size_t>& size, int channels, const ByteArray& pixels, int stride) const;

        void saveToJpg(OutStream& stream, const Size<std::size_t>& size, int channels, const ByteArray& pixels, int quality) const;
    };
}

#endif // BULL_CORE_IMAGE_ABSTRACTIMAGESAVER_HPP
