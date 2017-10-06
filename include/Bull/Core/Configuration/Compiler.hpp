#ifndef BULL_CORE_CONFIGURATION_COMPILER_HPP
#define BULL_CORE_CONFIGURATION_COMPILER_HPP

#define BULL_COMPILER_MSC      1
#define BULL_COMPILER_GCC      2
#define BULL_COMPILER_INTEL    3
#define BULL_COMPILER_CLANG    4
#define BULL_COMPILER_MINGW_32 5
#define BULL_COMPILER_MINGW_64 6

#if defined _MSC_VER
	#define BULL_COMPILER BULL_COMPILER_MSC
#elif defined __GNUC__
	#define BULL_COMPILER BULL_COMPILER_GCC
    #define BULL_COMPILER_VERSION __GNUC__
#elif defined __MINGW32__
	#define BULL_COMPILER BULL_COMPILER_MINGW_32
#elif defined __MINGW64__
	#define BULL_COMPILER BULL_COMPILER_MINGW_64
#else
	#error Unsupported compiler
#endif

#endif // BULL_CORE_CONFIGURATION_COMPILER_HPP