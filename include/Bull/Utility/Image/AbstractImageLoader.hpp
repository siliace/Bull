#ifndef BULL_UTILITY_IMAGE_ABSTRACTIMAGELOADER_HPP
#define BULL_UTILITY_IMAGE_ABSTRACTIMAGELOADER_HPP

#include <Bull/Core/Loader/AbstractResourceLoader.hpp>

#include <Bull/Utility/Image/Image.hpp>
#include <Bull/Utility/Image/ImageFormat.hpp>

namespace Bull
{
    struct BULL_UTILITY_API AbstractImageLoader : public AbstractResourceLoader<Image>
    {
        /*! \brief Tell whether an ImageFormat is support
         *
         * \param format The format to test
         *
         * \return True if the format is supported by the loader
         *
         */
        virtual bool isSupportedFormat(ImageFormat format) const = 0;

        /*! \brief Load an Image from pixels
         *
         * \param resource The Resource to load
         * \param pixels   Pixels of the Image
         * \param size     The size of the Image
         *
         * \return True if the Resource was loaded successfully
         *
         */
        virtual bool loadFromPixels(std::unique_ptr<Image>& resource, const ByteArray& pixels, const Vector2UI& size) const = 0;
    };
}

#endif // BULL_UTILITY_IMAGE_ABSTRACTIMAGELOADER_HPP
