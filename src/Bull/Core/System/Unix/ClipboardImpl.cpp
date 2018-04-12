#include <Bull/Core/Exception/Throw.hpp>
#include <Bull/Core/Exception/UnsupportedOperation.hpp>
#include <Bull/Core/System/Win32/ClipboardImpl.hpp>

namespace Bull
{
    namespace prv
    {
        void ClipboardImpl::flush()
        {
            Throw(UnsupportedOperation, "ClipboardImpl::flush", "Operation not implemented yet");
        }

        void ClipboardImpl::setContent(const String& content)
        {
            Throw(UnsupportedOperation, "ClipboardImpl::setContent", "Operation not implemented yet");
        }

        String ClipboardImpl::getContent()
        {
            Throw(UnsupportedOperation, "ClipboardImpl::getContent", "Operation not implemented yet");
        }
    }
}
