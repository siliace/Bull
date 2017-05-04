#ifndef BULL_NONCOPYABLE_HPP
#define BULL_NONCOPYABLE_HPP

#include <Bull/Core/Export.hpp>

namespace Bull
{
    class BULL_CORE_API NonCopyable
    {
    protected:

        /*! \brief Default constructor
         *
         */
        NonCopyable() = default;

    private:

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
