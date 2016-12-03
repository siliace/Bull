#include <iostream>

#include <Bull/Utility/ConsoleLogger.hpp>

namespace Bull
{
    /*! \brief Add a new entry in the log
     *
     * \param message The entry to add in the log
     *
     */
    void ConsoleLogger::write(const String& entry)
    {
        std::cout << entry << std::endl;
    }
}
