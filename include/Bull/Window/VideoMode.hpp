#ifndef Bull_VideoMode_hpp
#define Bull_VideoMode_hpp

#include <vector>

#include <Bull/Core/System/Export.hpp>
#include <Bull/Core/System/Integer.hpp>

namespace Bull
{
    struct BULL_API VideoMode
    {
        /*! \brief Get the current VideoMode of the main screen
         *
         * \return Return a VideoMode with the current width, height and the deepness of the main screen
         *
         */
        static VideoMode getCurrent();

        /*! \brief Get all available video modes
         *
         * \return Return all available video modes
         *
         */
        static std::vector<VideoMode> getAllAvailable();

        /*! \brief Default constructor
         *
         */
        VideoMode();

        /*! \brief Constructor
         *
         * \param width The width of the window to open with this VideoMode
         * \param height The height of the window to open with this VideoMode
         * \param bitsPerPixel The number of bits per pixel (8, 16, 24 or 32)
         *
         */
        VideoMode(unsigned int width, unsigned int height, Uint8 bitsPerPixel = getCurrent().bitsPerPixel);

        /*! \brief == operator override
         *
         * \param right The VideoMode to compare
         *
         * \return Return true if this and compare are equal, else return false
         *
         */
        bool operator==(const VideoMode& right);

        /*! \brief != operator override
         *
         * \param right The VideoMode to compare
         *
         * \return Return true if this and compare are not equal, else return false
         *
         */
        bool operator!=(const VideoMode& right);

        /*! \brief Check if a VideoMode is valid
         *
         * \return Return true if the mode is valid, else return false
         *
         */
        bool isValid() const;

        unsigned int width;  /*!< The width of the window */
        unsigned int height; /*!< The height of the window */
        Uint8        bitsPerPixel;  /*!< The the number of bits per pixel to create colors */
    };
}

#endif // Bull_VideoMode_hpp
