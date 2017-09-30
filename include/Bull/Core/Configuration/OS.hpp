#ifndef BULL_CORE_CONFIGURATION_OS_HPP
#define BULL_CORE_CONFIGURATION_OS_HPP

#if defined _WIN32
    #define BULL_OS_WINDOWS

    #define BULL_WINDOWS_8     0x0602
    #define BULL_WINDOWS_7     0x0601
    #define BULL_WINDOWS_VISTA 0x0600
    #define BULL_WINDOWS_XP    0x0501 // Defined but not planed to be used

    #if defined BULL_BUILD_WINDOWS_8
        #define BULL_WINDOWS_VERSION BULL_WINDOWS_8
    #elif defined BULL_BUILD_WINDOWS_7
        #define BULL_WINDOWS_VERSION BULL_WINDOWS_7
    #elif defined BULL_BUILD_WINDOWS_VISTA
        #define BULL_WINDOWS_VERSION BULL_WINDOWS_VISTA
    #else
        #error Windows XP is not supported
    #endif
#elif defined __FreeBSD__
    #define BULL_OS_FREEBSD
    #define BULL_OS_UNIX
#elif defined __gnu_linux__
    #define BULL_OS_UNIX
    #define BULL_OS_GNU_LINUX

    #if defined BULL_BUILD_WAYLAND
        #define BULL_WEYLAND
    #elif defined BULL_BUILD_XLIB
        #define BULL_XLIB
    #elif defined BULL_BUILD_XCB
        #define BULL_XCB
    #else
        #error No Window library defined
    #endif
#elif defined __APPLE__ && __MACH__
    #define BULL_OS_OSX
    #define BULL_OS_UNIX
#else
    #error Your system is not supported by Bull
#endif

#endif // BULL_CORE_CONFIGURATION_OS_HPP
