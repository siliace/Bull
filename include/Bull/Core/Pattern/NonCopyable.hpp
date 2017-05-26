#ifndef BULL_NONCOPYABLE_HPP
#define BULL_NONCOPYABLE_HPP

#include <Bull/Core/Export.hpp>

namespace Bull
{
    struct BULL_CORE_API NonCopyable
    {
        /*! \brief Default constructor
         *
         */
        NonCopyable() = default;

        /*! \brief Copy constructor
         *
         */
        NonCopyable(const NonCopyable& copy) = delete;

        /*! \brief Basic assignment operator
         *
         */
        NonCopyable& operator=(const NonCopyable& copy) = delete;
    };
}

#endif // BULL_NONCOPYABLE_HPP
