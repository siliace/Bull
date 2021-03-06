#ifndef BULL_CLIPBOARDIMPL_HPP
#define BULL_CLIPBOARDIMPL_HPP

#include <string>

namespace Bull
{
    namespace prv
    {
        class ClipboardImpl
        {
        public:

            /** \brief Flush the content of the Clipboard
             *
             */
            static void flush();

            /** \brief Set the content of the Clipboard
             *
             * \param content The std::string inside the clipboard
             *
             */
            static void setContent(const std::string& content);

            /** \brief Get the content of the Clipboard
             *
             * \return The std::string inside the Clipboard
             *
             */
            static std::string getContent();
        };
    }
}

#endif //BULL_CLIPBOARDIMPL_HPP
