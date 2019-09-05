#include <cstring>

#include <Bull/Core/Support/Win32/Win32Error.hpp>
#include <Bull/Core/Support/Win32/Windows.hpp>
#include <Bull/Core/System/Win32/ClipboardImpl.hpp>

namespace Bull
{
    namespace prv
    {
        void ClipboardImpl::flush()
        {
            if(OpenClipboard(nullptr))
            {
                EmptyClipboard();
            }
        }

        void ClipboardImpl::setContent(const std::string& content)
        {
            flush();

            Expect(OpenClipboard(nullptr), Throw(Win32Error, "Failed to open clipboard"));

            std::size_t size = (content.length() + 1) * sizeof(char);
            HANDLE handler = GlobalAlloc(CF_UNICODETEXT, size);

            if(handler)
            {
                std::memcpy(GlobalLock(handler), content.c_str(), size);
                GlobalUnlock(handler);
                SetClipboardData(CF_UNICODETEXT, handler);
            }

            CloseClipboard();
        }

        std::string ClipboardImpl::getContent()
        {
            std::string text;
            HANDLE clipboard;

            Expect(OpenClipboard(nullptr), Throw(Win32Error, "Failed to open clipboard"));

            clipboard = GetClipboardData(CF_UNICODETEXT);

            Expect(clipboard, Throw(Win32Error, "Failed to get clipboard content"));

            text = std::string(static_cast<const char*>(GlobalLock(clipboard)));
            GlobalUnlock(clipboard);

            CloseClipboard();

            return text;
        }
    }
}
