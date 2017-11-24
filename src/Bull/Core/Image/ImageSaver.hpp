#ifndef BULL_CORE_IMAGE_IMAGESAVER_HPP
#define BULL_CORE_IMAGE_IMAGESAVER_HPP

#include <Bull/Core/Image/Image.hpp>
#include <Bull/Core/Image/ImageParameters.hpp>
#include <Bull/Core/Resource/AbstractResourceSaver.hpp>

namespace Bull
{
    namespace prv
    {
        struct ImageSaver : public AbstractResourceSaver<Image, ImageParameters>
        {
        private:

            struct PixelBuffer
            {
                void* data;
                std::size_t length;
            };

            static void writeToStream(void* context, void* data, int size);

            static void writeToMemory(void* context, void* data, int size);

        public:

            /*! \brief Save an Image to Path
             *
             * \param image      The Image to save
             * \param path       The Path of the File to write
             * \param parameters Parameters to use to save the Image
             *
             * \return True if the Image was saved successfully
             *
             */
            bool saveToPath(const Image* image, const Path& path, const ImageParameters& parameters) const override;

            /*! \brief Save an Image to stream
             *
             * \param image      The Image to save
             * \param stream     The stream to write
             * \param parameters Parameters to use to save the Image
             *
             * \return True if the Image was saved successfully
             *
             */
            bool saveToStream(const Image* image, OutStream& stream, const ImageParameters& parameters) const override;

            /*! \brief Save an Image to a memory area
             *
             * \param image      The Image to save
             * \param data       Data to write
             * \param length     The length of data
             * \param parameters Parameters to use to save the Image
             *
             * \return True if the Image was saved successfully
             *
             */
            bool saveToMemory(const Image* image, void* data, std::size_t length, const ImageParameters& parameters) const override;

            /*! \brief Tell whether the extension is supported
             *
             * \param extension The extension to check
             *
             * \return True if the extension is supported
             *
             */
            bool isFormatSupported(const String& extension) const override;

            /*! \brief Tell whether parameters are supported
             *
             * \param parameters Parameters to check
             *
             * \return True if the parameters are supported
             *
             */
            bool isParametersSupported(const ImageParameters& parameters) const override;
        };
    }
}

#endif // BULL_CORE_IMAGE_IMAGESAVER_HPP
