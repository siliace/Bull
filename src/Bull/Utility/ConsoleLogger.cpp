#include <iostream>

#include <Bull/Utility/ConsoleLogger.hpp>

namespace Bull
{
    void ConsoleLogger::write(const String& entry)
    {
        std::cout << entry << std::endl;
    }
}
