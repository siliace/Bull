#include <Bull/Core/System/Clipboard.hpp>
#include <Bull/Core/System/ClipboardImpl.hpp>

namespace Bull
{
    void Clipboard::flush()
    {
        prv::ClipboardImpl::flush();
    }

    void Clipboard::setContent(const std::string& content)
    {
        prv::ClipboardImpl::setContent(content);
    }

    std::string Clipboard::getContent()
    {
        return prv::ClipboardImpl::getContent();
    }
}