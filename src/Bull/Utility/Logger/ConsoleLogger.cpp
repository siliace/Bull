#include <iostream>

#include <Bull/Utility/Logger/ConsoleLogger.hpp>

namespace Bull
{
    void ConsoleLogger::write(const String& entry)
    {
        std::cout << entry << std::endl;
    }
}
