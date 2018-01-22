#ifndef BULL_CORE_EXCEPTION_DECLAREEXCEPTION_HPP
#define BULL_CORE_EXCEPTION_DECLAREEXCEPTION_HPP

#include <Bull/Core/Exception/Exception.hpp>

#define DeclareException(ExceptionName)                                                               \
struct ExceptionName : public Exception                                                               \
{                                                                                                     \
    ExceptionName(const String& file, Uint64 line, const String& source, const String& description) : \
        Exception(file, line, #ExceptionName, source, description)                                    \
    {                                                                                                 \
                                                                                                      \
    }                                                                                                 \
};

#endif // BULL_CORE_EXCEPTION_DECLAREEXCEPTION_HPP
