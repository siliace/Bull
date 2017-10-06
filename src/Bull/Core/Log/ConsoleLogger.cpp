#include <iostream>

#include <Bull/Core/Log/ConsoleLogger.hpp>

namespace Bull
{
    void ConsoleLogger::write(const String& entry)
    {
        std::cout << entry.getBuffer() << std::endl;
    }
}
