#include <Bull/Core/Log/ConsoleLogger.hpp>
#include <Bull/Core/Log/Log.hpp>
#include <Bull/Core/Plugin/Plugin.hpp>
#include <Bull/Core/Utility/StringUtils.hpp>

int main(int argc, char* argv[])
{
    Bull::Log::getInstance().createLogger<Bull::ConsoleLogger>();

    Bull::Plugin plugin(Bull::Path("plugin.dll"), "entryPoint");

    int sum = plugin.call<int>("", 1, 3);

    Bull::Log::getInstance().info("1 + 3 = " + Bull::StringUtils::number(sum));

    return 0;
}
