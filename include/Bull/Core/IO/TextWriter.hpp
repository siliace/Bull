#ifndef BULL_CORE_IO_TEXTWRITTER_HPP
#define BULL_CORE_IO_TEXTWRITTER_HPP

#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/IO/OutStream.hpp>

namespace Bull
{
    class BULL_CORE_API TextWriter
    {
    public:

        /*! \brief Constructor
         *
         * \param stream The OutStream to write in
         *
         */
        explicit TextWriter(OutStream& stream);

        /*! \brief Write a String in the OutStream
         *
         * \param string The String to write
         *
         */
        void write(const String& string);

        /*! \brief Write a line in the OutStream
         *
         * \param line The line to write
         *
         */
        void writeLine(const String& line);

        /*! \brief Write a String in the OutStream
         *
         * \param string The String to write
         *
         * \return This
         *
         */
        TextWriter& operator<<(const char* string);

        /*! \brief Write a String in the OutStream
         *
         * \param string The String to write
         *
         * \return This
         *
         */
        TextWriter& operator<<(const String& string);

    private:

        OutStream& m_stream;
    };
}

#endif // BULL_CORE_IO_TEXTWRITTER_HPP
