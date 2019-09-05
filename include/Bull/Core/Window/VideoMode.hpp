#ifndef BULL_CORE_WINDOW_VIDEOMODE_HPP
#define BULL_CORE_WINDOW_VIDEOMODE_HPP

#include <unordered_set>

#include <Bull/Core/Export.hpp>
#include <Bull/Core/Utility/Size.hpp>

namespace Bull
{
    class BULL_CORE_API VideoMode
    {
    public:

        /** \brief Get the current VideoMode of the main screen
         *
         * \return Return a VideoMode with the current width, height and the deepness of the main screen
         *
         */
        static VideoMode getCurrent();

        /** \brief Get all available video modes
         *
         * \return Return all available video modes
         *
         */
        static std::unordered_set<VideoMode> getAllAvailable();

    public:

        /** \brief Default constructor
         *
         */
        VideoMode();

        /** \brief Constructor
         *
         * \param size         The Size
         * \param bitsPerPixel The number of bits per pixel (8, 16, 24 or 32)
         *
         */
        explicit VideoMode(const Size<unsigned int>& size, unsigned int bitsPerPixel = getCurrent().getBitsPerPixel());

        /** \brief Check if a VideoMode is valid
         *
         * \return Return true if the mode is valid, else return false
         *
         */
        bool isValid() const;

        /** \brief
         *
         * \return
         *
         */
        const Size<unsigned int>& getSize() const;

        /** \brief
         *
         * \param size
         *
         */
        void setSize(const Size<unsigned int>& size);

        /** \brief
         *
         * \return
         *
         */
        unsigned int getBitsPerPixel() const;

        /** \brief
         *
         * \param bitsPerPixel
         *
         */
        void setBitsPerPixel(unsigned int bitsPerPixel);

        /** \brief == operator override
         *
         * \param right The VideoMode to compare
         *
         * \return Return true if this and compare are equal, else return false
         *
         */
        bool operator==(const VideoMode& right) const;

        /** \brief != operator override
         *
         * \param right The VideoMode to compare
         *
         * \return Return true if this and compare are not equal, else return false
         *
         */
        bool operator!=(const VideoMode& right) const;

    private:

        Size<unsigned int> m_size;
        unsigned int m_bitsPerPixel; /**< The the number of bits per pixel to create colors */
    };
}

namespace std
{
    template <>
    struct hash<Bull::VideoMode>
    {
        size_t operator()(const Bull::VideoMode& videoMode) const noexcept
        {
            return videoMode.getSize().getWidth() ^ videoMode.getSize().getHeight() ^ videoMode.getBitsPerPixel();
        }
    };
}

#endif // BULL_CORE_WINDOW_VIDEOMODE_HPP
