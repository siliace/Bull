#include <Bull/Core/Support/Win32/Windows.hpp>
#include <Bull/Core/Time/Win32/DateImpl.hpp>

namespace Bull
{
    namespace prv
    {
        Date DateImpl::now()
        {
            SYSTEMTIME lt = {0};
            GetLocalTime(&lt);

            return Date::make(lt.wYear, DateMonth(lt.wMonth), lt.wDay);
        }
    }
}
