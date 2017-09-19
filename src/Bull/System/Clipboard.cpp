#include <Bull/System/Clipboard.hpp>
#include <Bull/System/ClipboardImpl.hpp>

namespace Bull
{
    void Clipboard::flush()
    {
        prv::ClipboardImpl::flush();
    }

    void Clipboard::setContent(const String& content)
    {
        prv::ClipboardImpl::setContent(content);
    }

    String Clipboard::getContent()
    {
        return prv::ClipboardImpl::getContent();
    }
}