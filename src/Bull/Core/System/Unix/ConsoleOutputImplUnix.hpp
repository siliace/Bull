#ifndef BULL_CORE_SYSTEM_UNIX_CONSOLEOUTPUTIMPLUNIX_HPP
#define BULL_CORE_SYSTEM_UNIX_CONSOLEOUTPUTIMPLUNIX_HPP

#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/System/ConsoleOutputImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class ConsoleOutputImplUnix : public ConsoleOutputImpl
        {
        private:

            /*! \brief Convert a ConsoleColor to a win32 text attribute
             *
             * \param color The color
             *
             * \return The text attribute
             *
             */
            static int colorToTextAttribute(ConsoleColor color);

            /*! \brief Convert a ConsoleColor to a win32 background attribute
             *
             * \param color The color
             *
             * \return The text attribute
             *
             */
            static int colorToBackgroundAttribute(ConsoleColor color);

        public:

            /*! \brief Write bytes in console
             *
             * \param data   Data to write
             * \param length The length of data
             *
             * \return The number of bytes written
             *
             */
            std::size_t write(const void* data, std::size_t length) override;

            /*! \brief Flush the ConsoleOutput
             *
             */
            void flush() override;

            /*! \brief Clear the console output
             *
             */
            void clear() override;

            /*! \brief Set the color of the text in the console
             *
             * \param color The color
             *
             */
            void setTextColor(ConsoleColor color) override;

            /*! \brief Set the color of the background in the console
             *
             * \param color The color
             *
             */
            void setBackgroundColor(ConsoleColor color) override;

        private:

            /*! \brief Write a String in the console
             *
             * \param string The String to write
             *
             * \return The number of bytes written
             *
             */
            std::size_t write(const String& string);
        };
    }
}

#endif // BULL_CORE_SYSTEM_UNIX_CONSOLEOUTPUTIMPLUNIX_HPP
