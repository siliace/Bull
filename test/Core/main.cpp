#include <Bull/Core/Log/FileLogger.hpp>
#include <Bull/Core/Log/Log.hpp>

#define CATCH_CONFIG_RUNNER

#include <Catch/catch.hpp>

int main(int argc, char* argv[])
{
    auto& fileLogger = Bull::Log::getInstance().createLogger<Bull::FileLogger>();
    fileLogger.setMinimalSeverity(Bull::LogLevel_Debug);

    return Catch::Session().run(argc, argv);
}