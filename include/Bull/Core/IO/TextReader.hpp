#ifndef BULL_CORE_IO_TEXTINSTREAM_HPP
#define BULL_CORE_IO_TEXTINSTREAM_HPP

#include <Bull/Core/IO/InStream.hpp>

namespace Bull
{
    class BULL_CORE_API TextReader
    {
    public:

        /** \brief Constructor
         *
         * \param stream The InStream to read
         *
         */
        explicit TextReader(InStream& stream);

        /** \brief Read all the content of the OutStream
         *
         * \return The content
         *
         */
        std::string readAll();

        /** \brief Read the next line of the stream
         *
         * \param separator The separator character between two lines
         *
         * \return The next line
         *
         */
        std::string readLine(char separator = '\n');

        /** \brief Read the next character of the stream
         *
         * \return The character read
         *
         */
        char readCharacter();

    private:

        InStream& m_stream;
    };
}

#endif // BULL_CORE_IO_TEXTINSTREAM_HPP
