#include <iostream>

#include <Bull/Core/Log/AbstractLogger.hpp>
#include <Bull/Core/Log/ConsoleLogger.hpp>

namespace Bull
{
    void ConsoleLogger::write(const String& entry, LogLevel level)
    {
        std::cout << parseMessage(entry, level).getBuffer() << std::endl;
    }
}
