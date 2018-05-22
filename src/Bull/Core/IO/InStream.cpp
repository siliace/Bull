#include <Bull/Core/IO/InStream.hpp>
#include <Bull/Core/Utility/StringUtils.hpp>

namespace Bull
{
    InStream::~InStream() = default;

    String InStream::readAll()
    {
        String content = StringUtils::ofSize(getSize());

        read(&content[0], content.getSize());

        return content;
    }

    bool InStream::readLine(String& line, char separator)
    {
        line.clear();

        while(!isAtEnd())
        {
            char character;

            if(read(&character, 1) == 1)
            {
                if(character == separator)
                {
                    return true;
                }

                line += character;
            }
        }

        return false;
    }

    InStream::operator bool() const
    {
        return !isAtEnd();
    }
}
