#ifndef BULL_CORE_IMAGE_PIXELFORMAT_HPP
#define BULL_CORE_IMAGE_PIXELFORMAT_HPP

#include <Bull/Core/Utility/Size.hpp>

namespace Bull
{
    enum PixelFormat
    {
        PixelFormat_Luma8,
        PixelFormat_Luma8Alpha8,
        PixelFormat_Rgb8,
        PixelFormat_Rgb8Alpha8,
    };

    struct BULL_CORE_API PixelFormatUtils
    {
        /*! \brief Get the number of bytes needed by a PixelFormat to encode one pixel
         *
         * \param pixelFormat The PixelFormat
         *
         * \return The number of bytes
         *
         */
        static std::size_t getPixelFormatSize(PixelFormat pixelFormat);
    };
}

#endif // BULL_CORE_IMAGE_PIXELFORMAT_HPP
