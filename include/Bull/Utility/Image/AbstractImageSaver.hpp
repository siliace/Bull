#ifndef BULL_UTILITY_IMAGE_ABSTRACTIMAGESAVER_HPP
#define BULL_UTILITY_IMAGE_ABSTRACTIMAGESAVER_HPP

#include <Bull/Core/Loader/AbstractResourceSaver.hpp>

#include <Bull/Utility/Export.hpp>
#include <Bull/Utility/Image/ImageFormat.hpp>
#include <Bull/Utility/Image/ImageParameterBag.hpp>

namespace Bull
{
    class Image;

    struct BULL_UTILITY_API AbstractImageSaver : public AbstractResourceSaver<Image, ImageParameterBag>
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

#endif // BULL_UTILITY_IMAGE_ABSTRACTIMAGESAVER_HPP
