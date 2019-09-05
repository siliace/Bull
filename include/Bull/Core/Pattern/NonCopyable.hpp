#ifndef BULL_CORE_PATTERN_NONCOPYABLE_HPP
#define BULL_CORE_PATTERN_NONCOPYABLE_HPP

#include <Bull/Core/Export.hpp>

namespace Bull
{
    class BULL_CORE_API NonCopyable
    {
    public:

        /** \brief Default constructor
         *
         */
        NonCopyable() = default;

        /** \brief Copy constructor
         *
         */
        NonCopyable(const NonCopyable&) = delete;

        /** \brief Constructor by movement
         *
         */
        NonCopyable(NonCopyable&&) noexcept = default;

        /** \brief Basic assignment operator
         *
         */
        NonCopyable& operator=(const NonCopyable&) = delete;

        /** \brief Basic assignment operator by movement
         *
         * \return This
         *
         */
        NonCopyable& operator=(NonCopyable&&) noexcept = default;
    };
}

#endif // BULL_CORE_PATTERN_NONCOPYABLE_HPP
