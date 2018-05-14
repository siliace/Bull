#ifndef BULL_CORE_UTILITY_CHARACTER_HPP
#define BULL_CORE_UTILITY_CHARACTER_HPP

#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    struct BULL_CORE_API Character
    {
        /*! \brief Tell whether a character is alpha numeric
         *
         * A character is alpha numeric if it's a letter (in lowercase or uppercase) or a number
         *
         * \param character The character to test
         *
         * \return True if the character is alpha numeric
         *
         */
        static bool isAlphaNumeric(char character);

        /*! \brief Convert a lowercase character to the uppercase equivalent character
          *
          * \param character the character to convert
          *
          * \return Return the uppercase equivalent of the character
          *
          */
        static char toUpper(char character);

        /*! \brief Convert a uppercase character to the lowercase equivalent character
         *
         * \param character the character to convert
         *
         * \return Return the lowercase equivalent of the character
         *
         */
        static char toLower(char character);

        /*! \brief Convert a single number to its character equivalent
         *
         * \param integer The integer value to convert as a character
         *
         * \return Return the integer as a character
         *
         */
        static char intToChar(int integer);

        /*! \brief Convert a character to its integer equivalent
         *
         * \param character The character value to convert as a integer
         *
         * \return Return the character as a integer
         *
         */
        static int charToInt(char character);
    };
}

#endif // BULL_CORE_UTILITY_CHARACTER_HPP
