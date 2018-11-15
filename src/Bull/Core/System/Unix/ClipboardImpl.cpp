#include <Bull/Core/Exception/UnsupportedOperation.hpp>
#include <Bull/Core/System/Win32/ClipboardImpl.hpp>

namespace Bull
{
    namespace prv
    {
        void ClipboardImpl::flush()
        {
            Throw(UnsupportedOperation, "Operation not implemented yet");
        }

        void ClipboardImpl::setContent(const String& content)
        {
            Throw(UnsupportedOperation, "Operation not implemented yet");
        }

        String ClipboardImpl::getContent()
        {
            Throw(UnsupportedOperation, "Operation not implemented yet");
        }
    }
}
