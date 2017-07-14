#ifndef BULL_CORE_EXCEPTION_RUNTIMEERROR_HPP
#define BULL_CORE_EXCEPTION_RUNTIMEERROR_HPP

#include <Bull/Core/Exception/Exception.hpp>

namespace Bull
{
    class BULL_CORE_API RuntimeError : public Exception
    {
    public:

        /*! \brief Default constructor
         *
         */
        RuntimeError() = default;

        /*! \brief Constructor
         *
         * \param message The Exception's message
         *
         */
        RuntimeError(const String& message);
    };
}

#endif // BULL_CORE_EXCEPTION_RUNTIMEERROR_HPP
