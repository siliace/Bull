#ifndef BULL_CONSOLEOUTPUTIMPL_HPP
#define BULL_CONSOLEOUTPUTIMPL_HPP

#include <memory>

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/System/ConsoleColor.hpp>

namespace Bull
{
    namespace prv
    {
        class ConsoleOutputImpl : public NonCopyable
        {
        public:

            /*! \brief Create an OS specific instance of ConsoleOutputImpl
             *
             * \return The instance
             *
             */
            static std::unique_ptr<ConsoleOutputImpl> createInstance();

        public:

            /*! \brief Destructor
             *
             */
            virtual ~ConsoleOutputImpl();

            /*! \brief Write bytes in console
             *
             * \param data   Data to write
             * \param length The length of data
             *
             * \return The number of bytes written
             *
             */
            virtual std::size_t write(const void* data, std::size_t length) = 0;

            /*! \brief Flush the ConsoleOutput
             *
             */
            virtual void flush() = 0;

            /*! \brief Clear the console output
             *
             */
            virtual void clear() = 0;

            /*! \brief Set the color of the text in the console
             *
             * \param color The color
             *
             */
            virtual void setTextColor(ConsoleColor color) = 0;

            /*! \brief Set the color of the background in the console
             *
             * \param color The color
             *
             */
            virtual void setBackgroundColor(ConsoleColor color) = 0;

        protected:

            /*! \brief Default constructor
             *
             */
            ConsoleOutputImpl() = default;
        };
    }
}

#endif //BULL_CONSOLEOUTPUTIMPL_HPP
