#include <algorithm>

#include <Bull/Core/Window/VideoMode.hpp>
#include <Bull/Core/Window/VideoModeImpl.hpp>

namespace Bull
{
    VideoMode VideoMode::getCurrent()
    {
        return prv::VideoModeImpl::getCurrent();
    }

    std::vector<VideoMode> VideoMode::getAllAvailable()
    {
        return prv::VideoModeImpl::getAllAvailable();
    }

    VideoMode::VideoMode() :
        width(0),
        height(0),
        bitsPerPixel(0)
    {
        /// Nothing
    }

    VideoMode::VideoMode(unsigned int width, unsigned int height, Uint8 bitsPerPixel)  :
        width(width),
        height(height),
        bitsPerPixel(bitsPerPixel)
    {
        /// Nothing
    }

    bool VideoMode::operator==(const VideoMode& right)
    {
        return (width == right.width) && (height == right.height) && (bitsPerPixel == right.bitsPerPixel);
    }

    bool VideoMode::operator!=(const VideoMode& right)
    {
        return !((*this) == right);
    }

    bool VideoMode::isValid() const
    {
        std::vector<VideoMode> all = VideoMode::getAllAvailable();

        return std::find(all.begin(), all.end(), (*this)) != all.end();
    }
}