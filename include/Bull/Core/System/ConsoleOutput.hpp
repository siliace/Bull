#ifndef BULL_CORE_SYSTEM_CONSOLEOUTPUT_HPP
#define BULL_CORE_SYSTEM_CONSOLEOUTPUT_HPP

#include <memory>

#include <Bull/Core/IO/OutStream.hpp>
#include <Bull/Core/System/ConsoleColor.hpp>

namespace Bull
{
    namespace prv
    {
        class ConsoleOutputImpl;
    }

    class BULL_CORE_API ConsoleOutput : public OutStream
    {
    public:

        /*! \brief Default constructor
         *
         */
        ConsoleOutput();

        /*! \brief Destructor
         *
         */
        ~ConsoleOutput();

        /*! \brief Write bytes in the ConsoleOutput
         *
         * \param bytes Bytes to write
         *
         * \return The number of bytes written
         *
         */
        std::size_t write(const ByteArray& bytes) override;

        /*! \brief Flush the ConsoleOutput
         *
         */
        void flush() override;

        /*! \brief Clear the ConsoleOutput
         *
         */
        void clear();

        /*! \brief Set the color of the text in the ConsoleOutput
         *
         * \param color The color
         *
         */
        void setTextColor(ConsoleColor color);

        /*! \brief Set the color of the background in the ConsoleOutput
         *
         * \param color The color
         *
         */
        void setBackgroundColor(ConsoleColor color);

    private:

        std::unique_ptr<prv::ConsoleOutputImpl> m_impl;
    };
}

#endif //BULL_CONSOLEOUT_HPP
