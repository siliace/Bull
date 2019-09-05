#ifndef BULL_CONSOLEOUTPUTIMPLWIN32_HPP
#define BULL_CONSOLEOUTPUTIMPLWIN32_HPP

#include <Bull/Core/Support/Win32/Windows.hpp>
#include <Bull/Core/System/ConsoleOutputImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class ConsoleOutputImplWin32 : public ConsoleOutputImpl
        {
        private:

            /** \brief Convert a ConsoleColor to a win32 text attribute
             *
             * \param color The color
             *
             * \return The text attribute
             *
             */
            static WORD colorToTextAttribute(ConsoleColor color);

            /** \brief Convert a ConsoleColor to a win32 background attribute
             *
             * \param color The color
             *
             * \return The text attribute
             *
             */
            static WORD colorToBackgroundAttribute(ConsoleColor color);

        public:

            /** \brief Default constructor
             *
             */
            ConsoleOutputImplWin32();

            /** \brief Destructor
             *
             */
            ~ConsoleOutputImplWin32();

            size_t write(const ByteArray& bytes) override;

            /** \brief Flush the ConsoleOutput
             *
             */
            void flush() override;

            /** \brief Clear the console output
             *
             */
            void clear() override;

            /** \brief Set the color of the text in the console
             *
             * \param color The color
             *
             */
            void setTextColor(ConsoleColor color) override;

            /** \brief Set the color of the background in the console
             *
             * \param color The color
             *
             */
            void setBackgroundColor(ConsoleColor color) override;

        private:

            /** \brief Apply both foreground and background colors
             *
             */
            void applyColor();

        private:

            HANDLE m_handler;
            ConsoleColor m_currentTextColor;
            WORD m_initialAttributes;
            ConsoleColor m_currentBackgroundColor;
        };
    }
}

#endif //BULL_CONSOLEOUTPUTIMPLWIN32_HPP
