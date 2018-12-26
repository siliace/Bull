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
        bitsPerPixel(0)
    {
        /// Nothing
    }

    VideoMode::VideoMode(const SizeUI& size, unsigned int bitsPerPixel) :
        size(size),
        bitsPerPixel(bitsPerPixel)
    {
        /// Nothing
    }

    bool VideoMode::isValid() const
    {
        std::vector<VideoMode> all = VideoMode::getAllAvailable();

        return std::find(all.begin(), all.end(), *this) != all.end();
    }


    bool VideoMode::operator==(const VideoMode& right)
    {
        return size == right.size &&
               bitsPerPixel == right.bitsPerPixel;
    }

    bool VideoMode::operator!=(const VideoMode& right)
    {
        return !(*this == right);
    }
}
