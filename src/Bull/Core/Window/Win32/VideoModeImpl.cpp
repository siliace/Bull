#include <algorithm>

#include <Bull/Core/Support/Win32/Windows.hpp>

#include <Bull/Core/Window/Win32/VideoModeImpl.hpp>

namespace Bull
{
    namespace prv
    {
        VideoMode VideoModeImpl::getCurrent()
        {
            DEVMODE mode;

            EnumDisplaySettings(nullptr, ENUM_CURRENT_SETTINGS, &mode);

            return VideoMode(SizeUI(mode.dmPelsWidth, mode.dmPelsHeight), mode.dmBitsPerPel);
        }

        std::vector<VideoMode> VideoModeImpl::getAllAvailable()
        {
            std::vector<VideoMode> modes;
            DEVMODE devMode;

            for(unsigned int i = 0; EnumDisplaySettings(nullptr, i, &devMode); i++)
            {
                VideoMode mode(SizeUI(devMode.dmPelsWidth, devMode.dmPelsHeight), devMode.dmBitsPerPel);

                if(std::find(modes.begin(), modes.end(), mode) == modes.end())
                {
                    modes.push_back(mode);
                }
            }

            return modes;
        }
    }
}
