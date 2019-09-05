#ifndef BULL_CORE_SYSTEM_CLIPBOARD_HPP
#define BULL_CORE_SYSTEM_CLIPBOARD_HPP

#include <string>

#include <Bull/Core/Export.hpp>

namespace Bull
{
    class BULL_CORE_API Clipboard
    {
    public:

        /**
         * \brief Flush the content of the Clipboard
         */
        static void flush();

        /**
         * \brief Set the content of the Clipboard
         * \param content The std::string inside the clipboard
         */
        static void setContent(const std::string& content);

        /**
         * \brief Get the content of the Clipboard
         * \return The std::string inside the Clipboard
         */
        static std::string getContent();
    };
}

#endif // BULL_CORE_SYSTEM_CLIPBOARD_HPP
