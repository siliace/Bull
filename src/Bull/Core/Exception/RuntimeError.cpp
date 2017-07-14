#include <Bull/Core/Exception/RuntimeError.hpp>

namespace Bull
{
    RuntimeError::RuntimeError(const String& message) :
        Exception(message)
    {
        /// Nothing
    }
}