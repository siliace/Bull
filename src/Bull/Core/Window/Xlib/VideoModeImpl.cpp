#include <algorithm>

#include <X11/extensions/Xrandr.h>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Support/Xlib/Display.hpp>
#include <Bull/Core/Window/Xlib/VideoModeImpl.hpp>

namespace Bull
{
    namespace prv
    {
        VideoMode VideoModeImpl::getCurrent()
        {
            Rotation  rotation;
            int       sizesCount;
            VideoMode desktopMode;
            Display&  display = Display::getInstance();

            Expect(display.isSupportedExtension("RANDR"), Throw(InternalError, "VideoModeImpl::getCurrent", "Missing XRandR extension"));

            XRRScreenConfiguration* config = XRRGetScreenInfo(display.getHandler(), display.getRootWindow());

            Expect(config, Throw(InternalError, "VideoModeImpl::getAllAvailable", "Failed to get screen configurations"));

            int currentMode = XRRConfigCurrentConfiguration(config, &rotation);

            XRRScreenSize* sizes = XRRConfigSizes(config, &sizesCount);

            if(sizes && sizesCount > 0)
            {
                desktopMode.bitsPerPixel = display.getDefaultDepth();

                if(rotation == RR_Rotate_90 || rotation == RR_Rotate_270)
                {
                    desktopMode.height = sizes[currentMode].width;
                    desktopMode.width  = sizes[currentMode].height;
                }
                else
                {
                    desktopMode.width  = sizes[currentMode].width;
                    desktopMode.height = sizes[currentMode].height;
                }
            }

            XFree(config);

            return desktopMode;
        }

        std::vector<VideoMode> VideoModeImpl::getAllAvailable()
        {
            std::vector<VideoMode> modes;
            int                    sizesCount;
            int                    depthsCount;
            Display& display = Display::getInstance();

            Expect(display.isSupportedExtension("RANDR"), Throw(InternalError, "VideoModeImpl::getAllAvailable", "Missing XRandR extension"));

            XRRScreenConfiguration* config = XRRGetScreenInfo(display.getHandler(), display.getRootWindow());

            Expect(config, Throw(InternalError, "VideoModeImpl::getAllAvailable", "Failed to get screen configurations"));

            XRRScreenSize* sizes  = XRRConfigSizes(config, &sizesCount);
            int*           depths = XListDepths(display.getHandler(), display.getDefaultScreen(), &depthsCount);

            if(sizes && sizesCount > 0 && depths && depthsCount > 0)
            {
                for(int j = 0; j < depthsCount; j++)
                {
                    for(int i = 0; i < sizesCount; i++)
                    {
                        VideoMode mode;

                        mode.bitsPerPixel = depths[j];
                        mode.width        = sizes[i].width;
                        mode.height       = sizes[i].height;

                        if(std::find(modes.begin(), modes.end(), mode) == modes.end())
                        {
                            modes.push_back(mode);
                        }
                    }
                }
            }

            XFree(config);

            return modes;
        }
    }
}
