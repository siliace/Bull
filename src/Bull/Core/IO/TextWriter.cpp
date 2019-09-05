#include <Bull/Core/IO/TextWriter.hpp>

namespace Bull
{
    TextWriter::TextWriter(OutStream& stream) :
            m_stream(stream)
    {
        /// Nothing
    }

    void TextWriter::write(const std::string& string)
    {
        m_stream.write(ByteArray::fromString(string));
    }

    void TextWriter::writeLine(const std::string& line)
    {
        write(line);
        breakLine();
    }

    void TextWriter::breakLine()
    {
        write("\n");
    }

    TextWriter& TextWriter::operator<<(const char* string)
    {
        write(string);

        return *this;
    }

    TextWriter& TextWriter::operator<<(const std::string& string)
    {
        write(string);

        return *this;
    }
}