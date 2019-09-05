#ifndef BULL_CORE_SYSTEM_UNIX_CONSOLEOUTPUTIMPLUNIX_HPP
#define BULL_CORE_SYSTEM_UNIX_CONSOLEOUTPUTIMPLUNIX_HPP

#include <string>
#include <Bull/Core/System/ConsoleOutputImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class ConsoleOutputImplUnix : public ConsoleOutputImpl
        {
        private:

            /** \brief Convert a ConsoleColor to a win32 text attribute
             *
             * \param color The color
             *
             * \return The text attribute
             *
             */
            static int colorToTextAttribute(ConsoleColor color);

            /** \brief Convert a ConsoleColor to a win32 background attribute
             *
             * \param color The color
             *
             * \return The text attribute
             *
             */
            static int colorToBackgroundAttribute(ConsoleColor color);

        public:

            /** \brief Write bytes in console
             *
             * \param bytes Bytes to write
             *
             * \return The number of bytes written
             *
             */
            std::size_t write(const ByteArray& bytes) override;

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
        };
    }
}

#endif // BULL_CORE_SYSTEM_UNIX_CONSOLEOUTPUTIMPLUNIX_HPP
