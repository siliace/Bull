#include <numeric>

#include <Bull/Core/IO/TextReader.hpp>
#include <Bull/Core/Utility/Character.hpp>

namespace Bull
{
    TextReader::TextReader(InStream& stream) :
        m_stream(stream)
    {
        /// Nothing
    }

    String TextReader::readAll()
    {
        String content;

        while(!m_stream.isAtEnd())
        {
            content += readLine() + '\n';
        }

        return content;
    }

    String TextReader::readLine(char separator)
    {
        String line;
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