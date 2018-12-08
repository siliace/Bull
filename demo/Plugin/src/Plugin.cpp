#include <map>

#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Log/Log.hpp>

BULL_PLUGIN_API void entryPoint(Bull::RunTime& runtime)
{
    Bull::Log::import(runtime);

    Bull::Log::getInstance().info("Entry point from plugin");
}

BULL_PLUGIN_API int add(int a, int b)
{
    return a + b;
}

BULL_PLUGIN_API int subtract(int a, int b)
{
    return a - b;
}

BULL_PLUGIN_API int multiply(int a, int b)
{
    return a * b;
}

BULL_PLUGIN_API int divide(int a, int b)
{
    Expect(b != 0, Throw(Bull::InvalidParameter, "Cannot divide by zero"));

    return a / b;
}