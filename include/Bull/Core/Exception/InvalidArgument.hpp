#ifndef BULL_CORE_EXCEPTION_INVALIDARGUMENT_HPP
#define BULL_CORE_EXCEPTION_INVALIDARGUMENT_HPP

#include <Bull/Core/Exception/LogicError.hpp>

namespace Bull
{
    class BULL_CORE_API InvalidArgument : public LogicError
    {
    public:

        /*! \brief Default constructor
         *
         */
        InvalidArgument() = default;

        /*! \brief Constructor
         *
         * \param message The Exception's message
         *
         */
        InvalidArgument(const String& message);

        /*! \brief Constructor
         *
         * \param message  The Exception's message
         * \param expected The expected value
         *
         */
        InvalidArgument(const String& message, const String& expected);
    };
}

#endif // BULL_CORE_EXCEPTION_INVALIDARGUMENT_HPP
