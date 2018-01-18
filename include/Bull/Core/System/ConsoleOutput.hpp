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

        /*! \brief Write a String into the ConsoleOutput
         *
         * \param string The String to write
         *
         */
        void write(const String& string);

        /*! \brief Write a String into the ConsoleOutput
         *
         * \param string The String to write
         *
         */
        void writeLine(const String& string);

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

    protected:

        /*! \brief Write data into the ConsoleOutput
         *
         * \param data A pointer to the memory area to write
         * \param size The size of the memory area to write
         *
         * \return The number of bytes written
         *
         */
        std::size_t write(const void* data, std::size_t size) override;

        /*! \brief Get the size of the ConsoleOutput
         *
         * \return Return the size of the ConsoleOutput
         *
         */
        std::size_t getSize() const override;

    private:

        std::size_t                             m_size;
        std::unique_ptr<prv::ConsoleOutputImpl> m_impl;
    };
}

#endif //BULL_CONSOLEOUT_HPP
