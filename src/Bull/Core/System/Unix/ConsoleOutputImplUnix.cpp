#include <Bull/Core/System/Unix/ConsoleOutputImplUnix.hpp>

namespace Bull
{
    namespace prv
    {
        std::size_t ConsoleOutputImplUnix::write(const void *data, std::size_t length)
        {
            return 0;
        }

        void ConsoleOutputImplUnix::clear()
        {

        }

        void ConsoleOutputImplUnix::setTextColor(ConsoleColor color)
        {

        }

        void ConsoleOutputImplUnix::setBackgroundColor(ConsoleColor color)
        {

        }
    }
}