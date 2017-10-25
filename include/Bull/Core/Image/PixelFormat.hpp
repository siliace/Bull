#ifndef BULL_CORE_IMAGE_PIXELFORMAT_HPP
#define BULL_CORE_IMAGE_PIXELFORMAT_HPP

#include <Bull/Core/Image/PixelFormatType.hpp>
#include <Bull/Core/Image/PixelDataType.hpp>
#include <Bull/Core/Memory/String.hpp>

namespace Bull
{

    struct BULL_CORE_API PixelFormat
    {
        struct BULL_CORE_API Info
        {
            String        name;
            PixelDataType dataType;
            Uint8         bitsPerPixel;
        };

        /*! \brief Get an Info structure describing a PixelFormatType
         *
         * \param type The PixelFormatType
         *
         * \return The Info
         *
         */
        static Info getPixelFormatTypeInfo(PixelFormatType type);
    };
}

#endif // BULL_CORE_IMAGE_PIXELFORMAT_HPP
