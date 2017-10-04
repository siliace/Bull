#include <cstring>

#include <Bull/Core/Log/Log.hpp>
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

        void ClipboardImpl::setContent(const String& content)
        {
            flush();

            if(!OpenClipboard(nullptr))
            {
                Log::get()->write("Failed to open clipboard", Log::Level::Error);
            }

            Index size = (content.getSize() + 1) * sizeof(char);
            HANDLE handler = GlobalAlloc(CF_UNICODETEXT, size);

            if(handler)
            {
                std::memcpy(GlobalLock(handler), content.getBuffer(), size);
                GlobalUnlock(handler);
                SetClipboardData(CF_UNICODETEXT, handler);
            }

            CloseClipboard();
        }

        String ClipboardImpl::getContent()
        {
            String text;
            HANDLE clipboard;

            if(!OpenClipboard(nullptr))
            {
                Log::get()->write("Failed to open clipboard", Log::Level::Error);

                return text;
            }

            clipboard = GetClipboardData(CF_UNICODETEXT);

            if(clipboard)
            {
                Log::get()->write("Failed to open clipboard", Log::Level::Error);

                CloseClipboard();

                return text;
            }

            text = String(static_cast<const char*>(GlobalLock(clipboard)));
            GlobalUnlock(clipboard);

            CloseClipboard();

            return text;
        }
    }
}
