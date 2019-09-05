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

        void ClipboardImpl::setContent(const std::string& content)
        {
            Throw(UnsupportedOperation, "Operation not implemented yet");
        }

        std::string ClipboardImpl::getContent()
        {
            Throw(UnsupportedOperation, "Operation not implemented yet");
        }
    }
}
