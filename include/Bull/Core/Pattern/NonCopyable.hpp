#ifndef Bull_NonCopyable_hpp
#define Bull_NonCopyable_hpp

#include <Bull/Core/System/Export.hpp>

namespace Bull
{
    class BULL_API NonCopyable
    {
    protected:

        /*! @brief Default constructor
         *
         */
        NonCopyable() = default;

    private:

        /*! @brief Copy constructor
         *
         */
        NonCopyable(const NonCopyable& copy) = delete;

        /*! @brief Basic assignment operator
         *
         */
        NonCopyable& operator=(const NonCopyable& copy) = delete;
    };
}

#endif // Bull_NonCopyable_hpp
