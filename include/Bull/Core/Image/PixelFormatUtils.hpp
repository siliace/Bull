#ifndef BULL_CORE_IMAGE_PIXELFORMATUTILS_HPP
#define BULL_CORE_IMAGE_PIXELFORMATUTILS_HPP

#include <Bull/Core/Image/AbstractImage.hpp>

namespace Bull
{
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

        /*! \brief Compute the number of bytes to allocate to store an image of a given Size and a PixelFormat
         *
         * \param size        The Size
         * \param pixelFormat The PixelFormat
         *
         * \return The byte count
         *
         */
        static std::size_t getImageByteCount(const AbstractImage::Size& size, PixelFormat pixelFormat);
    };
}

#endif // BULL_CORE_IMAGE_PIXELFORMATUTILS_HPP
