#include <Bull/Core/IO/TextWriter.hpp>

namespace Bull
{
    TextWriter::TextWriter(OutStream& stream) :
        m_stream(stream)
    {
        /// Nothing
    }

    void TextWriter::write(const String& line)
    {
        m_stream.write(ByteArray::memoryCopy(line.getBuffer(), line.getSize()));
    }

    void TextWriter::writeLine(const String& line)
    {
        write(line + '\n');
    }

    TextWriter& TextWriter::operator<<(const char* string)
    {
        write(string);

        return *this;
    }

    TextWriter& TextWriter::operator<<(const String& string)
    {
        write(string);

        return *this;
    }
}