#include <Bull/Core/Exception/RuntimeError.hpp>

namespace Bull
{
    RuntimeError::RuntimeError(const String& message) :
        Exception(message)
    {
        /// Nothing
    }

    String RuntimeError::getExceptionType() const
    {
        return "Runtime Error";
    }
}