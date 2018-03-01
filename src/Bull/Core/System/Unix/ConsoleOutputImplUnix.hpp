#ifndef BULL_CORE_SYSTEM_UNIX_CONSOLEOUTPUTIMPLUNIX_HPP
#define BULL_CORE_SYSTEM_UNIX_CONSOLEOUTPUTIMPLUNIX_HPP

#include <Bull/Core/System/ConsoleOutputImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class ConsoleOutputImplUnix : public ConsoleOutputImpl
        {
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
        };
    }
}

#endif // BULL_CORE_SYSTEM_UNIX_CONSOLEOUTPUTIMPLUNIX_HPP
