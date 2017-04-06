#ifndef Bull_VideoModeImpl_hpp
#define Bull_VideoModeImpl_hpp

#include <vector>

#include <Bull/Utility/Window/VideoMode.hpp>

namespace Bull
{
    namespace prv
    {
        struct VideoModeImpl
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
        };
    }
}

#endif // Bull_VideoModeImpl_hpp
