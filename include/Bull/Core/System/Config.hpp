#ifndef Bull_Os_hpp
#define Bull_Os_hpp

#if defined _WIN32
    #define BULL_OS_WINDOWS

    /// Prevent conflict with other libs which would redefined _WIN32_WINNT
    #if defined BULL_BUILD
        #ifndef WIN32_LEAN_AND_MEAN
            #define WIN32_LEAN_AND_MEAN 1
        #endif

        #ifndef NOMINMAX
            #define NOMINMAX
        #endif

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

        #if defined _WIN32_WINNT
            #if _WIN32_WINNT < BULL_WINDOWS_VERSION
                #undef _WIN32_WINNT
                #define _WIN32_WINNT BULL_WINNT
            #endif
        #else
            #define _WIN32_WINNT BULL_WINDOWS_VERSION
        #endif
    #endif // defined
#elif defined __FreeBSD__
    #define BULL_OS_FREEBSD
    #define BULL_OS_UNIX
#elif defined __gnu_linux__
    #define BULL_OS_GNU_LINUX
    #define BULL_OS_UNIX

    #if defined BULL_BUILD_WAYLAND
        #define BULL_WEYLAND
    #else
        #define BULL_X11
    #endif
#elif defined __APPLE__ && __MACH__
    #define BULL_OS_OSX
    #define BULL_OS_UNIX
#else
    #error Your system is not supported by Bull
#endif

#ifdef BULL_OS_UNIX
    #undef None
#endif

#endif // Bull_Os_hpp