#include <Bull/Core/Exception/InvalidArgument.hpp>

namespace Bull
{
    InvalidArgument::InvalidArgument(const String& message) :
        LogicError(message)
    {
        /// Nothing
    }

    InvalidArgument::InvalidArgument(const String& message, const String& expected) :
        LogicError(message, expected)
    {
        /// Nothing
    }

    String InvalidArgument::getExceptionType() const
    {
        return "Invalid Argument";
    }
}