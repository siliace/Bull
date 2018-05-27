#include <Bull/Core/Support/Win32/Windows.hpp>
#include <Bull/Core/Time/Win32/TimeImpl.hpp>

namespace Bull
{
    namespace prv
    {
        Time TimeImpl::now()
        {
            SYSTEMTIME lt = {0};
            GetLocalTime(&lt);

            return Time::make(lt.wHour, lt.wMinute, lt.wSecond, lt.wMilliseconds);
        }
    }
}