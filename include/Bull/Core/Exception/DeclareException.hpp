#ifndef BULL_CORE_EXCEPTION_DECLAREEXCEPTION_HPP
#define BULL_CORE_EXCEPTION_DECLAREEXCEPTION_HPP

#include <Bull/Core/Exception/Exception.hpp>

#define DeclareExceptionFrom(ExceptionName, ParentException)                                          \
struct ExceptionName : public ParentException                                                         \
{                                                                                                     \
    ExceptionName(const String& file, Uint64 line, const String& source, const String& description) : \
        ParentException(file, line, #ExceptionName, source, description)                              \
    {                                                                                                 \
                                                                                                      \
    }                                                                                                 \
};

#define DeclareException(ExceptionName) DeclareExceptionFrom(ExceptionName, Bull::Exception)

#endif // BULL_CORE_EXCEPTION_DECLAREEXCEPTION_HPP
