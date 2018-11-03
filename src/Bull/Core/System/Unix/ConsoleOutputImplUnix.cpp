#include <unistd.h>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/System/Unix/ConsoleOutputImplUnix.hpp>
#include <Bull/Core/Utility/StringUtils.hpp>

namespace Bull
{
    namespace prv
    {
        int ConsoleOutputImplUnix::colorToTextAttribute(ConsoleColor color)
        {
            switch(color)
            {
                case ConsoleColor_Red: return 0;
                case ConsoleColor_Blue: return 91;
                case ConsoleColor_Cyan: return 96;
                case ConsoleColor_Gray: return 37;
                case ConsoleColor_Black: return 30;
                case ConsoleColor_Green: return 92;
                case ConsoleColor_White: return 39;
                case ConsoleColor_Yellow: return 93;
                case ConsoleColor_DarkRed: return 31;
                case ConsoleColor_Magenta: return 95;
                case ConsoleColor_DarkBlue: return 34;
                case ConsoleColor_DarkCyan: return 36;
                case ConsoleColor_DarkGray: return 90;
                case ConsoleColor_DarkGreen: return 32;
                case ConsoleColor_DarkYellow: return 33;
                case ConsoleColor_DarkMagenta: return 35;
            }
        }

        int ConsoleOutputImplUnix::colorToBackgroundAttribute(ConsoleColor color)
        {
            switch(color)
            {
                case ConsoleColor_Red: return 101;
                case ConsoleColor_Blue: return 104;
                case ConsoleColor_Cyan: return 106;
                case ConsoleColor_Gray: return 47;
                case ConsoleColor_Black: return 49;
                case ConsoleColor_Green: return 102;
                case ConsoleColor_White: return 107;
                case ConsoleColor_Yellow: return 103;
                case ConsoleColor_DarkRed: return 41;
                case ConsoleColor_Magenta: return 105;
                case ConsoleColor_DarkBlue: return 44;
                case ConsoleColor_DarkCyan: return 46;
                case ConsoleColor_DarkGray: return 100;
                case ConsoleColor_DarkGreen: return 42;
                case ConsoleColor_DarkYellow: return 43;
                case ConsoleColor_DarkMagenta: return 45;
            }
        }

        std::size_t ConsoleOutputImplUnix::write(const ByteArray& bytes)
        {
            ssize_t written = ::write(STDOUT_FILENO, bytes.getBuffer(), bytes.getCapacity());

            Expect(written != -1, Throw(InternalError, "ConsoleOutputImplUnix::write", "Failed to write buffer in stdout"));

            return written;
        }

        void ConsoleOutputImplUnix::flush()
        {
            Expect(fflush(stdout) != -1, Throw(InternalError, "ConsoleOutputImplUnix::flush", "Failed to flush stdout"));
        }

        void ConsoleOutputImplUnix::clear()
        {
            write(ByteArray::fromString("\e[1;1H\e[2J"));
        }

        void ConsoleOutputImplUnix::setTextColor(ConsoleColor color)
        {
            write(ByteArray::fromString("\033[" + StringUtils::number(colorToTextAttribute(color)) + "m"));
        }

        void ConsoleOutputImplUnix::setBackgroundColor(ConsoleColor color)
        {
            write(ByteArray::fromString("\033[" + StringUtils::number(colorToBackgroundAttribute(color)) + "m"));
        }
    }
}