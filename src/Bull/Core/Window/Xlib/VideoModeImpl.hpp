#ifndef BULL_CORE_WINDOW_VIDEOMODEIMPL_HPP
#define BULL_CORE_WINDOW_VIDEOMODEIMPL_HPP

#include <vector>

#include <Bull/Core/Window/VideoMode.hpp>

namespace Bull
{
    namespace prv
    {
        class VideoModeImpl
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
            static std::vector<VideoMode> getAllAvailable();
        };
    }
}

#endif // BULL_CORE_WINDOW_VIDEOMODEIMPL_HPP
