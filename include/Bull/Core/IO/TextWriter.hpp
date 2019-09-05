#ifndef BULL_CORE_IO_TEXTWRITTER_HPP
#define BULL_CORE_IO_TEXTWRITTER_HPP

#include <string>

#include <Bull/Core/IO/OutStream.hpp>

namespace Bull
{
    class BULL_CORE_API TextWriter
    {
    public:

        /** \brief Constructor
         *
         * \param stream The OutStream to write in
         *
         */
        explicit TextWriter(OutStream& stream);

        /** \brief Write a std::string in the OutStream
         *
         * \param string The std::string to write
         *
         */
        void write(const std::string& string);

        /** \brief Write a line in the OutStream
         *
         * \param line The line to write
         *
         */
        void writeLine(const std::string& line);

        void breakLine();

        /** \brief Write a std::string in the OutStream
         *
         * \param string The std::string to write
         *
         * \return This
         *
         */
        TextWriter& operator<<(const char* string);

        /** \brief Write a std::string in the OutStream
         *
         * \param string The std::string to write
         *
         * \return This
         *
         */
        TextWriter& operator<<(const std::string& string);

    private:

        OutStream& m_stream;
    };
}

#endif // BULL_CORE_IO_TEXTWRITTER_HPP
