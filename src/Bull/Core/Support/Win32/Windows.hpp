#ifndef BULL_CORE_SUPPORT_WINDOWS_HPP
#define BULL_CORE_SUPPORT_WINDOWS_HPP

#include <Bull/Core/Configuration/OS.hpp>

#ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN 1
#endif

#ifndef NOMINMAX
    #define NOMINMAX
#endif

#if defined _WIN32_WINNT
    #if _WIN32_WINNT < BULL_WINDOWS_VERSION
        #undef _WIN32_WINNT
        #define _WIN32_WINNT BULL_WINDOWS_VERSION
    #endif
#else
    #define _WIN32_WINNT BULL_WINDOWS_VERSION
#endif

#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>
#include <psapi.h>
#include <tlhelp32.h>

#endif // BULL_CORE_SUPPORT_WINDOWS_HPP
