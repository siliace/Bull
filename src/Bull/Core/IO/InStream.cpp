#include <Bull/Core/IO/InStream.hpp>

namespace Bull
{
    InStream::~InStream() = default;

    String InStream::readAll()
    {
        String content;
        if(content.create(getSize()))
        {
            read(&content[0], content.getSize());

            return content;
        }

        return "";
    }

    bool InStream::readLine(String& line, char separator)
    {
        line.clear();

        while(!isAtEnd())
        {
            char character;

            if(read(&character, 1) == 1 && character != separator)
            {
                line += character;
            }
            else
            {
                return true;
            }
        }

        return false;
    }

    InStream::operator bool() const
    {
        return isAtEnd();
    }
}
