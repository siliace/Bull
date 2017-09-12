#ifndef BULL_ABSTRACTIMAGESAVER_HPP
#define BULL_ABSTRACTIMAGESAVER_HPP

#include <Bull/Core/Loader/AbstractResourceSaver.hpp>

#include <Bull/Utility/Image/Image.hpp>
#include <Bull/Utility/Image/ImageFormat.hpp>

namespace Bull
{
    struct BULL_UTILITY_API AbstractImageSaver : public AbstractResourceSaver<Image>
    {
        /*! \brief Tell whether an ImageFormat is supported
         *
         * \param format The format to test
         *
         * \return True if the format is supported
         *
         */
        virtual bool isSupportedFormat(ImageFormat format) const = 0;
    };
}

#endif //BULL_ABSTRACTIMAGESAVER_HPP
