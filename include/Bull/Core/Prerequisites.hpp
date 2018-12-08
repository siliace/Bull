#ifndef BULL_CORE_PREREQUISITES_HPP
#define BULL_CORE_PREREQUISITES_HPP

#include <cstdint>
#include <cstring>

#define BULL_COMPILER_MSC      1
#define BULL_COMPILER_GCC      2
#define BULL_COMPILER_MINGW_32 5
#define BULL_COMPILER_MINGW_64 6

#if defined _MSC_VER
    #define BULL_COMPILER BULL_COMPILER_MSC
    #define BULL_PRETTY_FUNCTION __FUNCSIG__
#elif defined __GNUC__
    #define BULL_PRETTY_FUNCTION __PRETTY_FUNCTION__
    #if defined __MINGW32__ && defined __MINGW64__
        #define BULL_COMPILER BULL_COMPILER_MINGW_64
		#define BULL_COMPILER_VERSION_MAJOR  __MINGW64_VERSION_MAJOR
		#define BULL_COMPILER_VERSION_MINOR  __MINGW64_VERSION_MINOR
		#define BULL_COMPILER_VERSION_BUGFIX __MINGW64_VERSION_BUGFIX
		#define BULL_COMPILER_VERSION_STRING __MINGW64_VERSION_STR
    #elif defined __MINGW32__
        #define BULL_COMPILER BULL_COMPILER_MINGW_32
		#define BULL_COMPILER_VERSION_MAJOR  __MINGW32_VERSION_MAJOR
		#define BULL_COMPILER_VERSION_MINOR  __MINGW32_VERSION_MINOR
		#define BULL_COMPILER_VERSION_BUGFIX __MINGW32_VERSION_BUGFIX
		#define BULL_COMPILER_VERSION_STRING __MINGW32_VERSION_STR
    #else
        #define BULL_COMPILER BULL_COMPILER_GCC
    #endif
#else
	#warning Unsupported compiler
#endif

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
#elif defined __APPLE__ && __MACH__
    #define BULL_OS_OSX
    #define BULL_OS_UNIX
#else
    #error Your system is not supported by Bull
#endif

#if defined BULL_DYNAMIC
    #if defined BULL_OS_WINDOWS
        #define BULL_API_EXPORT __declspec(dllexport)
        #define BULL_API_IMPORT __declspec(dllimport)
    #else
        #if BULL_COMPLER == BULL_COMPILER_GCC
            #if BULL_COMPILER_VERSION >= 4
                #define BULL_API_EXPORT __attribute__ ((__visibility__ ("default")))
                #define BULL_API_IMPORT __attribute__ ((__visibility__ ("default")))
            #else
                #define BULL_API_EXPORT
                #define BULL_API_IMPORT
            #endif
        #endif
     #endif
#else
    #define BULL_API_EXPORT
    #define BULL_API_IMPORT
#endif

#define BULL_PLUGIN_API extern "C" BULL_API_EXPORT

#ifndef BULL_ZERO_MEMORY
    #define BULL_ZERO_MEMORY(Object) std::memset(&(Object), 0, sizeof(decltype(Object)))
#endif

#ifndef BULL_ZERO_MEMORY_PTR
    #define BULL_ZERO_MEMORY_PTR(Pointer, Length) std::memset(Pointer, 0, Length)
#endif

#ifndef BULL_UNUSED
    #define BULL_UNUSED(Variable) (void)Variable
#endif

namespace Bull
{
    typedef int8_t   Int8;
    typedef int16_t  Int16;
    typedef int32_t  Int32;
    typedef int64_t  Int64;
    typedef uint8_t  Uint8;
    typedef uint16_t Uint16;
    typedef uint32_t Uint32;
    typedef uint64_t Uint64;
}

#endif // BULL_CORE_PREREQUISITES_HPP
