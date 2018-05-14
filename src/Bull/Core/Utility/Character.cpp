#include <Bull/Core/Utility/Character.hpp>

namespace Bull
{
    bool Character::isAlphaNumeric(char character)
    {
        return std::isalnum(character);
    }

    char Character::toUpper(char character)
    {
        if(character >= 'a' && character <= 'z')
        {
            return character - ('a' - 'A');
        }

        return character;
    }

    char Character::toLower(char character)
    {
        if(character >= 'A' && character <= 'Z')
        {
            return character + ('a' - 'A');
        }

        return character;
    }

    char Character::intToChar(int integer)
    {
        return static_cast<char>(integer) + '0';
    }

    int Character::charToInt(char character)
    {
        return character - '0';
    }

}