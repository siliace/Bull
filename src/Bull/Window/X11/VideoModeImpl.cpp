#include <X11/extensions/Xrandr.h>

#include <Bull/Window/X11/Display.hpp>
#include <Bull/Window/X11/VideoModeImpl.hpp>

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
                            desktopMode.width = sizes[currentMode].height;
                            desktopMode.height = sizes[currentMode].width;
                        }
                        else
                        {
                            desktopMode.width = sizes[currentMode].width;
                            desktopMode.height = sizes[currentMode].height;
                        }
                    }

                }
                else
                {
                    Log::get()->error("Your version of Xorg does not support XRandR extension");
                }
            }
            else
            {
                Log::get()->error("Your version of Xorg does not support XRandR extension");
            }

            return desktopMode;
        }

        /*! \brief Get all available video modes
         *
         * \return Return all available video modes
         *
         */
        std::vector<VideoMode> VideoModeImpl::getAllAvailable()
        {

        }
    }
}
