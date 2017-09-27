#ifndef BULL_SYSTEM_CLIPBOARD_HPP
#define BULL_SYSTEM_CLIPBOARD_HPP

#include <Bull/Core/Memory/String.hpp>

#include <Bull/System/Export.hpp>

namespace Bull
{
    struct BULL_SYSTEM_API Clipboard
    {
        /*! \brief Flush the content of the Clipboard
         *
         */
        static void flush();

        /*! \brief Set the content of the Clipboard
         *
         * \param content The String inside the clipboard
         *
         */
        static void setContent(const String& content);

        /*! \brief Get the content of the Clipboard
         *
         * \return The String inside the Clipboard
         *
         */
        static String getContent();
    };
}

#endif // BULL_SYSTEM_CLIPBOARD_HPP
