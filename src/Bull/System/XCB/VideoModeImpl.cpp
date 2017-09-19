#include <Bull/System/XCB/VideoModeImpl.hpp>

namespace Bull
{
    namespace prv
    {
        VideoMode VideoModeImpl::getCurrent()
        {
            return VideoMode();
        }

        std::vector<VideoMode> VideoModeImpl::getAllAvailable()
        {
            return std::vector<VideoMode>();
        }
    }
}