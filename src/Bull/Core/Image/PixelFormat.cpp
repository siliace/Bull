#include <Bull/Core/Image/PixelFormat.hpp>

namespace Bull
{
    std::size_t PixelFormatUtils::getPixelFormatSize(Bull::PixelFormat pixelFormat)
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
    }
}

