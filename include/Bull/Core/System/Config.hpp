#ifndef Bull_Os_hpp
#define Bull_Os_hpp

#if defined _WIN32
    #define BULL_OS_WINDOWS

    /// Prevent conflict with other libs with which would redefined _WIN32_WINNT
    #if defined BULL_BUILD
        #ifndef WIN32_LEAN_AND_MEAN
            #define WIN32_LEAN_AND_MEAN 1
        #endif

        #ifndef NOMINMAX
            #define NOMINMAX
        #endif

        #if defined BULL_WINDOWS_8 || defined BULL_WINDOWS_BLUE
            #define BULL_WINNT 0x0602
        #elif defined BULL_WINDOWS_7
            #define BULL_WINNT 0x0601
        #elif defined BULL_WINDOWS_SERVER_2008 || defined BULL_WINDOWS_VISTA
            #define BULL_WINNT 0x0600
        #else
            #define BULL_WINNT 0x0501
        #endif

        #if defined _WIN32_WINNT
            #if _WIN32_WINNT < BULL_WINNT
                #undef _WIN32_WINNT
                #define _WIN32_WINNT BULL_WINNT
            #endif
        #else
            #define _WIN32_WINNT BULL_WINNT
        #endif
    #endif // defined
#elif defined __FreeBSD__
    #define BULL_OS_FREEBSD
    #define BULL_OS_UNIX
#elif defined __gnu_linux__
    #define BULL_OS_GNU_LINUX
    #define BULL_OS_UNIX
#elif defined __APPLE__ && __MACH__
    #define BULL_OS_OSX
    #define BULL_OS_UNIX
#else
    #error Your system is not supported by Bull
#endif

#endif // Bull_Os_hpp
