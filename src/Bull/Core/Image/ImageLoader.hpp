#ifndef BULL_CORE_IMAGE_IMAGELOADER_HPP
#define BULL_CORE_IMAGE_IMAGELOADER_HPP

#include <Bull/Core/Image/Image.hpp>
#include <Bull/Core/Image/ImageParameters.hpp>
#include <Bull/Core/Resource/AbstractResourceLoader.hpp>

namespace Bull
{
    namespace prv
    {
        struct ImageLoader : public AbstractResourceLoader<Image, ImageParameters>
        {
            /*! \brief Load an Image from a Path
             *
             * \param image      The Image to load
             * \param path       The Path of the File to read
             * \param parameters Parameters to use to load the Image
             *
             * \return True if the Image was loaded successfully
             *
             */
            bool loadFromPath(Image* image, const Path& path, const ImageParameters& parameters) const override;

            /*! \brief Load an Image from a stream
             *
             * \param image      The Image to load
             * \param stream     The stream to read
             * \param parameters Parameters to use to load the Image
             *
             * \return True if the Image was loaded successfully
             *
             */
            bool loadFromStream(Image* image, InStream& stream, const ImageParameters& parameters) const override;

            /*! \brief Load an Image from a memory area
             *
             * \param image      The Image to load
             * \param data       Data to read
             * \param length     The length of data
             * \param parameters Parameters to use to load the Image
             *
             * \return True if the Image was loaded successfully
             *
             */
            bool loadFromMemory(Image* image, const void* data, Index length, const ImageParameters& parameters) const override;

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

#endif // BULL_CORE_IMAGE_IMAGELOADER_HPP
