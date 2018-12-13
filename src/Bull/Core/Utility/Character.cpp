#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Utility/Character.hpp>

namespace Bull
{
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

    char Character::intToChar(int number)
    {
        Expect(number >= 0 && number <= 9, Throw(InvalidParameter, "Number parameter should be between 0 and 9"));

        return static_cast<char>(number) + '0';
    }

    int Character::charToInt(char number)
    {
        Expect(number >= '0' && number <= '9', Throw(InvalidParameter, "Number parameter should be between 0 and 9"));

        return number - '0';
    }
}