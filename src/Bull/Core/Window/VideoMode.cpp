#include <Bull/Core/Window/VideoMode.hpp>
#include <Bull/Core/Window/VideoModeImpl.hpp>

namespace Bull
{
    VideoMode VideoMode::getCurrent()
    {
        return prv::VideoModeImpl::getCurrent();
    }

    std::unordered_set<VideoMode> VideoMode::getAllAvailable()
    {
        return prv::VideoModeImpl::getAllAvailable();
    }

    VideoMode::VideoMode() :
            m_bitsPerPixel(0)
    {
        /// Nothing
    }

    VideoMode::VideoMode(const Size<unsigned int>& size, unsigned int bitsPerPixel) :
            m_size(size),
            m_bitsPerPixel(bitsPerPixel)
    {
        /// Nothing
    }

    bool VideoMode::isValid() const
    {
        std::unordered_set<VideoMode> all = VideoMode::getAllAvailable();
        return all.find(*this) != all.end();
    }

    const Size<unsigned int>& VideoMode::getSize() const
    {
        return m_size;
    }

    void VideoMode::setSize(const Size<unsigned int>& size)
    {
        m_size = size;
    }

    unsigned int VideoMode::getBitsPerPixel() const
    {
        return m_bitsPerPixel;
    }

    void VideoMode::setBitsPerPixel(unsigned int bitsPerPixel)
    {
        m_bitsPerPixel = bitsPerPixel;
    }

    bool VideoMode::operator==(const VideoMode& right) const
    {
        return std::tie(m_size, m_bitsPerPixel) == std::tie(right.m_size, right.m_bitsPerPixel);
    }

    bool VideoMode::operator!=(const VideoMode& right) const
    {
        return std::tie(m_size, m_bitsPerPixel) != std::tie(right.m_size, right.m_bitsPerPixel);
    }
}
