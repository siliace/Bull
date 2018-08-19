#ifndef BULL_CONSOLEOUTPUTIMPL_HPP
#define BULL_CONSOLEOUTPUTIMPL_HPP

#include <memory>

#include <Bull/Core/Memory/ByteArray.hpp>
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

            virtual std::size_t write(const ByteArray& bytes) = 0;

            /*! \brief Flush the ConsoleOutput
             *
             * Flushing the ConsoleOutput will wait that every write instruction has been executed
             *
             */
            virtual void flush() = 0;

            /*! \brief Clear the console output
             *
             * Clearing the ConsoleOutput will clear every character written in the screen
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
