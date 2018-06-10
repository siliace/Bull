#ifndef BULL_CORE_UTILITY_STRINGUTILS_HPP
#define BULL_CORE_UTILITY_STRINGUTILS_HPP

#include <algorithm>

#include <Bull/Core/Exception/Expect.hpp>
#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Exception/Throw.hpp>
#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    struct BULL_CORE_API StringUtils
    {
        /*! \brief Convert a number to a String
         *
         * \param number The number to convert
         *
         * \return The number converted as a String
         *
         */
        template <typename T, typename = std::enable_if<std::is_arithmetic<T>::value>>
        static String number(T number)
        {
            return std::to_string(number).c_str();
        }

        /*! \brief Convert a boolean to a String
         *
         * The boolean with be converted to "true" or "false"
         *
         * \param boolean The boolean
         *
         * \return The String
         *
         */
        static String boolean(bool boolean);

        /*! \brief Create a String by repeating another one
         *
         * \param string The String to repeat
         * \param count  How many times the String shall be repeated
         *
         * \return The repeated String
         *
         */
        static String repeat(const String& string, std::size_t count);

        /*! \brief Create a String of a given size
         *
         * \param size The size
         * \return The created String
         */
        static String ofSize(std::size_t size);
    };
}

#endif // BULL_CORE_UTILITY_STRINGUTILS_HPP
