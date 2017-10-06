#ifndef BULL_CORE_IMAGE_ABSTRACTIMAGELOADER_HPP
#define BULL_CORE_IMAGE_ABSTRACTIMAGELOADER_HPP

#include <Bull/Core/Export.hpp>
#include <Bull/Core/Image/ImageFormat.hpp>
#include <Bull/Core/Image/ImageParameterBag.hpp>
#include <Bull/Core/Loader/AbstractResourceLoader.hpp>

namespace Bull
{
    class Image;

    class BULL_CORE_API AbstractImageLoader : public AbstractResourceLoader<Image, ImageParameterBag>
    {
        /*! \brief Tell whether an ImageFormat is supported
         *
         * \param format The ImageFormat to test
         *
         * \return True if the ImageFormat is supported
         *
         */
        virtual bool isSupportedFormat(ImageFormat format) const = 0;
    };
}

#endif // BULL_CORE_IMAGE_ABSTRACTIMAGELOADER_HPP
