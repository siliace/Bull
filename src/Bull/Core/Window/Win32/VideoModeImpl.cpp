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

            return VideoMode(Size<unsigned int>(mode.dmPelsWidth, mode.dmPelsHeight), mode.dmBitsPerPel);
        }

        std::unordered_set<VideoMode> VideoModeImpl::getAllAvailable()
        {
            DEVMODE devMode;
            std::unordered_set<VideoMode> modes;

            for(unsigned int i = 0; EnumDisplaySettings(nullptr, i, &devMode); i++)
                modes.insert(VideoMode({devMode.dmPelsWidth, devMode.dmPelsHeight}, devMode.dmBitsPerPel));

            return modes;
        }
    }
}
