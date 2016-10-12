#include <algorithm>

#include <Bull/Window/VideoMode.hpp>
#include <Bull/Window/VideoModeImpl.hpp>

namespace Bull
{
    /*! \brief Get the current VideoMode of the main screen
     *
     * \return Return a VideoMode with the current width, height and the deepness of the main screen
     *
     */
    VideoMode VideoMode::getCurrent()
    {
        return prv::VideoModeImpl::getCurrent();
    }

    /*! \brief Get all available video modes
     *
     * \return Return all available video modes
     *
     */
    std::vector<VideoMode> VideoMode::getAllAvailable()
    {
        return prv::VideoModeImpl::getAllAvailable();
    }

    /*! \brief Default constructor
     *
     */
    VideoMode::VideoMode() :
        width(0),
        height(0),
        bitsPerPixel(0)
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param width The width of the window to open with this VideoMode
     * \param height The height of the window to open with this VideoMode
     * \param bitsPerPixel The number of bits per pixel (8, 16, 24 or 32)
     *
     */
    VideoMode::VideoMode(unsigned int width, unsigned int height, Uint8 bitsPerPixel)  :
        width(width),
        height(height),
        bitsPerPixel(bitsPerPixel)
    {
        /// Nothing
    }

    /*! \brief == operator override
     *
     * \param right The VideoMode to compare
     *
     * \return Return true if this and compare are equal, else return false
     *
     */
    bool VideoMode::operator==(const VideoMode& right)
    {
        return (width == right.width) && (height == right.height) && (bitsPerPixel == right.bitsPerPixel);
    }

    /*! \brief == operator override
     *
     * \param right The VideoMode to compare
     *
     * \return Return true if this and compare are equal, else return false
     *
     */
    bool VideoMode::operator!=(const VideoMode& right)
    {
        return !((*this) == right);
    }

    /*! \brief Check if a VideoMode is valid
     *
     * \return Return true if the mode is valid, else return false
     *
     */
    bool VideoMode::isValid() const
    {
        std::vector<VideoMode> all = VideoMode::getAllAvailable();

        return std::find(all.begin(), all.end(), (*this)) != all.end();
    }
}
