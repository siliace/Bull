#ifndef BULL_CORE_IMAGE_PIXELFORMAT_HPP
#define BULL_CORE_IMAGE_PIXELFORMAT_HPP

namespace Bull
{
    enum PixelFormat
    {
        PixelFormat_Luma8,
        PixelFormat_Luma8Alpha8,
        PixelFormat_Rgb8,
        PixelFormat_Rgb8Alpha8,
        PixelFormat_Depth16,
        PixelFormat_Depth24,
        PixelFormat_Depth32,
        PixelFormat_Stencil1,
        PixelFormat_Stencil4,
        PixelFormat_Stencil8,
        PixelFormat_Stencil16,
        PixelFormat_Depth24Stencil8,
    };
}

#endif // BULL_CORE_IMAGE_PIXELFORMAT_HPP
