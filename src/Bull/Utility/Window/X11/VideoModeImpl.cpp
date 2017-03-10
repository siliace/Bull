#include <algorithm>

#include <X11/extensions/Xrandr.h>

#include <Bull/Core/Log.hpp>

#include <Bull/Utility/Window/X11/Display.hpp>
#include <Bull/Utility/Window/X11/VideoModeImpl.hpp>

namespace Bull
{
    namespace prv
    {
        VideoMode VideoModeImpl::getCurrent()
        {
            Display::Instance display = Display::get();
            VideoMode desktopMode;

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

                        if(rotation == RR_Rotate_90 || RR_Rotate_270)
                        {
                            desktopMode.width  = sizes[currentMode].height;
                            desktopMode.height = sizes[currentMode].width;
                        }
                        else
                        {
                            desktopMode.width  = sizes[currentMode].width;
                            desktopMode.height = sizes[currentMode].height;
                        }
                    }
                }
                else
                {
                    Log::get()->write("Your version of Xorg does not support XRandR extension", Log::Level::Error);
                }
            }
            else
            {
                Log::get()->write("Your version of Xorg does not support XRandR extension", Log::Level::Error);
            }

            return desktopMode;
        }

        std::vector<VideoMode> VideoModeImpl::getAllAvailable()
        {
            Display::Instance display = Display::get();
            std::vector<VideoMode> modes;

            if(display->isSupportedExtension("RANDR"))
            {
                XRRScreenConfiguration* config = XRRGetScreenInfo(display->getHandler(), display->getRootWindow());

                if(config)
                {
                    int sizesCount;
                    int depthsCount;

                    XRRScreenSize* sizes = XRRConfigSizes(config, &sizesCount);
                    int* depths          = XListDepths(display->getHandler(), display->getDefaultScreen(), &depthsCount);

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
                }
                else
                {
                    Log::get()->write("Your version of Xorg does not support XRandR extension", Log::Level::Error);
                }
            }
            else
            {
                Log::get()->write("Your version of Xorg does not support XRandR extension", Log::Level::Error);
            }

            return modes;
        }
    }
}
