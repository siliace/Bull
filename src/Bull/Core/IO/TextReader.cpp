#include <Bull/Core/IO/TextReader.hpp>

namespace Bull
{
    TextReader::TextReader(InStream& stream) :
            m_stream(stream)
    {
        /// Nothing
    }

    std::string TextReader::readAll()
    {
        std::string content;

        while(!m_stream.isAtEnd())
        {
            content += readLine() + '\n';
        }

        return content;
    }

    std::string TextReader::readLine(char separator)
    {
        std::string line;
        bool found = false;

        while(!m_stream.isAtEnd() && !found)
        {
            char character = readCharacter();

            if(character == separator)
            {
                found = true;
            }
            else
            {
                line += character;
            }
        }

        return line;
    }

    char TextReader::readCharacter()
    {
        if(!m_stream.isAtEnd())
        {
            return m_stream.read(1).toString().at(0);
        }

        return 0;
    }
}