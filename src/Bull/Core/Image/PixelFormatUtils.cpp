#include <Bull/Core/Image/PixelFormatUtils.hpp>

namespace Bull
{
    std::size_t PixelFormatUtils::getPixelFormatSize(PixelFormat pixelFormat)
    {
        switch(pixelFormat)
        {
            case PixelFormat_Luma8:
                return 1;

            case PixelFormat_Luma8Alpha8:
                return 2;

            case PixelFormat_Rgb8:
                return 3;

            case PixelFormat_Rgb8Alpha8:
                return 4;
        }

        return 0;
    }

    std::size_t PixelFormatUtils::getImageByteCount(const Size<std::size_t>& size, PixelFormat pixelFormat)
    {
        return size.width * size.height * getPixelFormatSize(pixelFormat);
    }
}

