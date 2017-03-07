#include <algorithm>

#include <windows.h>

#include <Bull/Utility/Window/Win32/VideoModeImpl.hpp>

namespace Bull
{
    namespace prv
    {
        /*! \brief Get the current VideoMode of the main screen
         *
         * \return Return a VideoMode with the current width, height and the deepness of the main screen
         *
         */
        VideoMode VideoModeImpl::getCurrent()
        {
            DEVMODE mode;

            EnumDisplaySettings(nullptr, ENUM_CURRENT_SETTINGS, &mode);

            return VideoMode(mode.dmPelsWidth, mode.dmPelsHeight, mode.dmBitsPerPel);
        }

        /*! \brief Get all available video modes
         *
         * \return Return all available video modes
         *
         */
        std::vector<VideoMode> VideoModeImpl::getAllAvailable()
        {
            std::vector<VideoMode> modes;
            DEVMODE devMode;

            for(unsigned int i = 0; EnumDisplaySettings(nullptr, i, &devMode); i++)
            {
                VideoMode mode(devMode.dmPelsWidth, devMode.dmPelsHeight, devMode.dmBitsPerPel);

                if(std::find(modes.begin(), modes.end(), mode) == modes.end())
                {
                    modes.push_back(mode);
                }
            }

            return modes;
        }
    }
}
