#include <Bull/Core/Window/Xlib/MessageWindowImpl.hpp>

namespace Bull
{
    namespace prv
    {
        MessageWindowResponse MessageWindowImpl::open(const String& message, const String& title, MessageWindowIcon icon, MessageWindowButtons buttons, MessageWindowDefaultButton defaultButton, WindowHandler parent)
        {
            return MessageWindowResponse_Ok;
        }
    }
}