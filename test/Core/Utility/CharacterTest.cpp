#include <Catch/catch.hpp>

#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Utility/Character.hpp>

using namespace Bull;

SCENARIO("Character::toUpper")
{
    GIVEN("A letter")
    {
        WHEN("Uppercase")
        {
            const char c = 'A';

            THEN("The letter should say the same")
            {
                REQUIRE(Character::toUpper(c) == c);
            }
        }

        WHEN("Lowercase")
        {
            const char c = 'a';

            THEN("The letter should be in uppercase")
            {
                REQUIRE(Character::toUpper(c) == 'A');
            }
        }
    }

    GIVEN("A number")
    {
        const char c = '0';

        THEN("The number should be the same")
        {
            REQUIRE(Character::toUpper(c) == c);
        }
    }

    GIVEN("A special character")
    {
        const char c = '$';

        THEN("The character should be the same")
        {
            REQUIRE(Character::toUpper(c) == c);
        }
    }
}

SCENARIO("Character::toLower")
{
    GIVEN("A letter")
    {
        WHEN("Lowercase")
        {
            const char c = 'a';

            THEN("The letter should say the same")
            {
                REQUIRE(Character::toLower(c) == c);
            }
        }

        WHEN("Uppercase")
        {
            const char c = 'A';

            THEN("The letter should be in lowercase")
            {
                REQUIRE(Character::toLower(c) == 'a');
            }
        }
    }

    GIVEN("A number")
    {
        const char c = '0';

        THEN("The number should be the same")
        {
            REQUIRE(Character::toLower(c) == c);
        }
    }

    GIVEN("A special character")
    {
        const char c = '$';

        THEN("The character should be the same")
        {
            REQUIRE(Character::toLower(c) == c);
        }
    }
}

SCENARIO("Character::intToChar")
{
    GIVEN("An integer corresponding to a number in the ascii table")
    {
        const int n = 3;

        THEN("The character should be the equivalent one in the ascii table")
        {
            REQUIRE(Character::intToChar(n) == '3');
        }
    }

    GIVEN("An integer that don't correspond to a number in the ascii table")
    {
        const int n = 42;

        THEN("Throw an InvalidParameter exception")
        {
            REQUIRE_THROWS_AS(Character::intToChar(n), InvalidParameter);
        }
    }

    GIVEN("A negative integer")
    {
        const int n = -1;

        THEN("Throw an InvalidParameter exception")
        {
            REQUIRE_THROWS_AS(Character::intToChar(n), InvalidParameter);
        }
    }
}

SCENARIO("Character::charToInt")
{
    GIVEN("An character corresponding to a number")
    {
        const char c = '3';

        THEN("The character should be converted to a number")
        {
            REQUIRE(Character::charToInt(c) == 3);
        }
    }

    GIVEN("An character that doesn't correspond to a number")
    {
        const char n = 'z';

        THEN("Throw an InvalidParameter exception")
        {
            REQUIRE_THROWS_AS(Character::charToInt(n), InvalidParameter);
        }
    }
}