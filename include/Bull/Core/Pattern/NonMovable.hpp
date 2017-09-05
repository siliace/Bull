#ifndef BULL_CORE_PATTERN_NONMOVABLE_HPP
#define BULL_CORE_PATTERN_NONMOVABLE_HPP

#include <Bull/Core/Export.hpp>

namespace Bull
{
    struct BULL_CORE_API NonMovable
    {
        /*! \brief Default constructor
         *
         */
        NonMovable() = default;

        /*! \brief Move constructor
         *
         */
        NonMovable(NonMovable&& right) = delete;

        /*! \brief Basic move assignment operator
         *
         */
        NonMovable& operator=(NonMovable&& right) = delete;
    };
}

#endif // BULL_CORE_PATTERN_NONMOVABLE_HPP
