#include <Bull/Core/Window/Xlib/MessageWindowImpl.hpp>

namespace Bull
{
    namespace prv
    {
        MessageWindowResponse MessageWindowImpl::open(const std::string& message, const std::string& title, MessageWindowIcon icon, MessageWindowButtons buttons, MessageWindowDefaultButton defaultButton, WindowHandler parent)
        {
            return MessageWindowResponse_Ok;
        }
    }
}