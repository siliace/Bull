#ifndef BULL_CORE_UTILITY_STRINGUTILS_HPP
#define BULL_CORE_UTILITY_STRINGUTILS_HPP

#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Utility/ArrayList.hpp>

namespace Bull
{
    struct BULL_CORE_API StringUtils
    {
        /*! \brief
         *
         * \param strings
         * \param glue
         *
         * \return
         *
         */
        static String join(const ArrayList<String>& strings, const String glue);
    };
}

#endif // BULL_CORE_UTILITY_STRINGUTILS_HPP
