#include <Bull/Core/Log/ConsoleLogger.hpp>
#include <Bull/Core/Log/Log.hpp>
#include <Bull/Core/Plugin/Plugin.hpp>

int main(int argc, char* argv[])
{
    Bull::Log::getInstance().createLogger<Bull::ConsoleLogger>();

    Bull::Plugin plugin(Bull::Path("plugin.dll"), "entryPoint");

    int sum = plugin.call<int>("add", 1, 3);

    Bull::Log::getInstance().info("1 + 3 = " + std::to_string(1 + 3));

    return 0;
}
