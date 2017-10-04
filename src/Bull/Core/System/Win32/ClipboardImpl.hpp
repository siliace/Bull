#ifndef BULL_CORE_SYSTEM_WIN32_CLIPBORARDIMPL_HPP
#define BULL_CORE_SYSTEM_WIN32_CLIPBORARDIMPL_HPP

#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    namespace prv
    {
        struct ClipboardImpl
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
}

#endif //BULL_CORE_SYSTEM_WIN32_CLIPBORARDIMPL_HPP
