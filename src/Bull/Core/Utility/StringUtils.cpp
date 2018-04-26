#include <Bull/Core/Utility/StringUtils.hpp>

namespace Bull
{
    bool StringUtils::isAlphaNumeric(char character)
    {
        return std::isalnum(character);
    }

    char StringUtils::toUpper(char character)
    {
        if(character >= 'a' && character <= 'z')
        {
            return character - ('a' - 'A');
        }

        return character;
    }

    char StringUtils::toLower(char character)
    {
        if(character >= 'A' && character <= 'Z')
        {
            return character + ('a' - 'A');
        }

        return character;
    }

    char StringUtils::intToChar(int integer)
    {
        return static_cast<char>(integer) + '0';
    }

    int StringUtils::charToInt(char character)
    {
        return character - '0';
    }

}