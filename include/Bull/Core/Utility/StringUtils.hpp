#ifndef BULL_CORE_UTILITY_STRINGUTILS_HPP
#define BULL_CORE_UTILITY_STRINGUTILS_HPP

#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Utility/ArrayList.hpp>

namespace Bull
{
    struct BULL_CORE_API StringUtils
    {
        /*! \brief Create a String from a List of Strings
         *
         * \param strings Strings to join
         * \param glue    The String to use to join two String
         *
         * \return The created String
         *
         */
        static String join(const ArrayList<String>& strings, const String& glue = String());

        /*! \brief Generate a random String
         *
         * \param length The length of the String to generate
         *
         * \return The random String
         *
         */
        static String random(std::size_t length);
    };
}

#endif // BULL_CORE_UTILITY_STRINGUTILS_HPP
