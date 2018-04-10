#ifndef BULL_CORE_EXCEPTION_THROW_HPP
#define BULL_CORE_EXCEPTION_THROW_HPP

#include <functional>

#include <Bull/Core/Exception/Exception.hpp>

#define Throw(Exception, Source, Description) Bull::prv::__throw<Exception>(__FILE__, __LINE__, Source, Description)

namespace Bull
{
    namespace prv
    {
        template <typename T, typename = std::enable_if<std::is_base_of<Exception, T>::value>>
        void __throw(const String& file, Uint64 line, const String& source, const String& description)
        {
            throw T(file, line, source, description);
        }
    }
}

#endif // BULL_CORE_EXCEPTION_THROW_HPP
