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
            Rotation rotation;
            int sizesCount;
            VideoMode desktopMode;
            Display& display = Display::getInstance();

            Expect(display.isSupportedExtension("RANDR"), Throw(InternalError, "Missing XRandR extension"));

            XRRScreenConfiguration* config = XRRGetScreenInfo(display.getHandler(), display.getRootWindow());

            Expect(config, Throw(InternalError, "Failed to get screen configurations"));

            int currentMode = XRRConfigCurrentConfiguration(config, &rotation);

            XRRScreenSize* sizes = XRRConfigSizes(config, &sizesCount);

            if(sizes && sizesCount > 0)
            {
                desktopMode.bitsPerPixel = display.getDefaultDepth();

                if(rotation == RR_Rotate_90 || rotation == RR_Rotate_270)
                {
                    desktopMode.size.height = sizes[currentMode].width;
                    desktopMode.size.width = sizes[currentMode].height;
                }
                else
                {
                    desktopMode.size.width = sizes[currentMode].width;
                    desktopMode.size.height = sizes[currentMode].height;
                }
            }

            XFree(config);

            return desktopMode;
        }

        std::vector<VideoMode> VideoModeImpl::getAllAvailable()
        {
            std::vector<VideoMode> modes;
            int sizesCount;
            int depthsCount;
            Display& display = Display::getInstance();

            Expect(display.isSupportedExtension("RANDR"), Throw(InternalError, "Missing XRandR extension"));

            XRRScreenConfiguration* config = XRRGetScreenInfo(display.getHandler(), display.getRootWindow());

            Expect(config, Throw(InternalError, "Failed to get screen configurations"));

            XRRScreenSize* sizes = XRRConfigSizes(config, &sizesCount);
            int* depths = XListDepths(display.getHandler(), display.getDefaultScreen(), &depthsCount);

            if(sizes && sizesCount > 0 && depths && depthsCount > 0)
            {
                for(int j = 0; j < depthsCount; j++)
                {
                    for(int i = 0; i < sizesCount; i++)
                    {
                        VideoMode mode;

                        mode.bitsPerPixel = depths[j];
                        mode.size.width = sizes[i].width;
                        mode.size.height = sizes[i].height;

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
