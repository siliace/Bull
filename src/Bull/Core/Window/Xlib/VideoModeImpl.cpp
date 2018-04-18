#include <algorithm>

#include <X11/extensions/Xrandr.h>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/Throw.hpp>
#include <Bull/Core/Support/Xlib/Display.hpp>
#include <Bull/Core/Window/Xlib/VideoModeImpl.hpp>

namespace Bull
{
    namespace prv
    {
        VideoMode VideoModeImpl::getCurrent()
        {
            VideoMode desktopMode;
            Display::Instance display = Display::getInstance();

            if(display->isSupportedExtension("RANDR"))
            {
                XRRScreenConfiguration* config = XRRGetScreenInfo(display->getHandler(), display->getRootWindow());

                if(config)
                {
                    Rotation rotation;
                    int      sizesCount;
                    int      currentMode = XRRConfigCurrentConfiguration(config, &rotation);

                    XRRScreenSize* sizes = XRRConfigSizes(config, &sizesCount);

                    if(sizes && sizesCount > 0)
                    {
                        desktopMode.bitsPerPixel = display->getDefaultDepth();

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
            }

            Throw(InternalError, "VideoModeImpl::getCurrent", "Missing XRandR extension");
        }

        std::vector<VideoMode> VideoModeImpl::getAllAvailable()
        {
            Display display;
            std::vector<VideoMode> modes;

            if(display.isSupportedExtension("RANDR"))
            {
                XRRScreenConfiguration* config = XRRGetScreenInfo(display.getHandler(), display.getRootWindow());

                if(config)
                {
                    int sizesCount;
                    int depthsCount;

                    XRRScreenSize* sizes = XRRConfigSizes(config, &sizesCount);
                    int* depths          = XListDepths(display.getHandler(), display.getDefaultScreen(), &depthsCount);

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

            Throw(InternalError, "VideoModeImpl::getAllAvailable", "Missing XRandR extension");
        }
    }
}
