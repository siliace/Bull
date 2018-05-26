#include <Bull/Core/Exception/Expect.hpp>
#include <Bull/Core/Exception/Throw.hpp>
#include <Bull/Core/Support/Win32/Win32Error.hpp>
#include <Bull/Core/System/Win32/ConsoleOutputImplWin32.hpp>

namespace Bull
{
    namespace prv
    {
        WORD ConsoleOutputImplWin32::colorToTextAttribute(ConsoleColor color)
        {
            switch(color)
            {
                case ConsoleColor_Black:       return 0;
                case ConsoleColor_DarkRed:     return FOREGROUND_RED;
                case ConsoleColor_DarkBlue:    return FOREGROUND_BLUE;
                case ConsoleColor_DarkGreen:   return FOREGROUND_GREEN;
                case ConsoleColor_Gray:        return FOREGROUND_INTENSITY;
                case ConsoleColor_Red:         return FOREGROUND_INTENSITY | FOREGROUND_RED;
                case ConsoleColor_Blue:        return FOREGROUND_INTENSITY | FOREGROUND_BLUE;
                case ConsoleColor_DarkCyan:    return FOREGROUND_GREEN     | FOREGROUND_BLUE;
                case ConsoleColor_DarkMagenta: return FOREGROUND_RED       | FOREGROUND_BLUE;
                case ConsoleColor_Green:       return FOREGROUND_INTENSITY | FOREGROUND_GREEN;
                case ConsoleColor_DarkYellow:  return FOREGROUND_RED       | FOREGROUND_GREEN;
                case ConsoleColor_Magenta:     return FOREGROUND_INTENSITY | FOREGROUND_RED   | FOREGROUND_BLUE;
                case ConsoleColor_Cyan:        return FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE;
                case ConsoleColor_DarkGray:    return FOREGROUND_RED       | FOREGROUND_GREEN | FOREGROUND_BLUE;
                case ConsoleColor_Yellow:      return FOREGROUND_INTENSITY | FOREGROUND_RED   | FOREGROUND_GREEN;
                case ConsoleColor_White:       return FOREGROUND_INTENSITY | FOREGROUND_RED   | FOREGROUND_GREEN | FOREGROUND_BLUE;
            }
        }

        WORD ConsoleOutputImplWin32::colorToBackgroundAttribute(ConsoleColor color)
        {
            switch(color)
            {
                case ConsoleColor_Black:       return 0;
                case ConsoleColor_DarkRed:     return BACKGROUND_RED;
                case ConsoleColor_DarkBlue:    return BACKGROUND_BLUE;
                case ConsoleColor_DarkGreen:   return BACKGROUND_GREEN;
                case ConsoleColor_Red:         return BACKGROUND_INTENSITY | BACKGROUND_RED;
                case ConsoleColor_Blue:        return BACKGROUND_INTENSITY | BACKGROUND_BLUE;
                case ConsoleColor_DarkCyan:    return BACKGROUND_GREEN     | BACKGROUND_BLUE;
                case ConsoleColor_DarkMagenta: return BACKGROUND_RED       | BACKGROUND_BLUE;
                case ConsoleColor_Green:       return BACKGROUND_INTENSITY | BACKGROUND_GREEN;
                case ConsoleColor_DarkYellow:  return BACKGROUND_RED       | BACKGROUND_GREEN;
                case ConsoleColor_Magenta:     return BACKGROUND_INTENSITY | BACKGROUND_RED   | BACKGROUND_BLUE;
                case ConsoleColor_Cyan:        return BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE;
                case ConsoleColor_DarkGray:    return BACKGROUND_RED       | BACKGROUND_GREEN | BACKGROUND_BLUE;
                case ConsoleColor_Yellow:      return BACKGROUND_INTENSITY | BACKGROUND_RED   | BACKGROUND_GREEN;
                case ConsoleColor_White:       return BACKGROUND_INTENSITY | BACKGROUND_RED   | BACKGROUND_GREEN | BACKGROUND_BLUE;
            }
        }

        ConsoleOutputImplWin32::ConsoleOutputImplWin32() :
            m_handler(GetStdHandle(STD_OUTPUT_HANDLE)),
            m_currentTextColor(ConsoleColor_White),
            m_currentBackgroundColor(ConsoleColor_Black)
        {
            CONSOLE_SCREEN_BUFFER_INFO info;

            if(GetConsoleScreenBufferInfo(m_handler, &info))
            {
                m_initialAttributes = info.wAttributes;
            }
            else
            {
                Log::getInstance()->warning("Failed to get initial console configuration");

                m_initialAttributes = colorToTextAttribute(ConsoleColor_White) | colorToBackgroundAttribute(ConsoleColor_Black);
            }
        }

        ConsoleOutputImplWin32::~ConsoleOutputImplWin32()
        {
            SetConsoleTextAttribute(m_handler, m_initialAttributes);
            CloseHandle(m_handler);
        }

        size_t ConsoleOutputImplWin32::write(const void* data, std::size_t length)
        {
            std::size_t written;

            if(WriteConsole(m_handler, data, length, reinterpret_cast<LPDWORD>(&written), nullptr))
            {
                return written;
            }

            return 0;
        }

        void ConsoleOutputImplWin32::flush()
        {
            FlushConsoleInputBuffer(m_handler);
        }

        void ConsoleOutputImplWin32::clear()
        {
            CONSOLE_SCREEN_BUFFER_INFO info;
            COORD                      screen = {0, 0};

            Expect(GetConsoleScreenBufferInfo(m_handler, &info), Throw(Win32Error, "ConsoleOutputImplWin32::clear", "Failed to get console info"));

            DWORD consoleSize = info.dwSize.X * info.dwSize.Y;

            Expect(FillConsoleOutputCharacter(m_handler, ' ', consoleSize, screen, nullptr), Throw(Win32Error, "ConsoleOutputImplWin32::clear", "Failed to fill console with blanks"));

            Expect(GetConsoleScreenBufferInfo(m_handler, &info), Throw(Win32Error, "ConsoleOutputImplWin32::clear", "Failed to get console info"));

            Expect(FillConsoleOutputAttribute(m_handler, info.wAttributes, consoleSize, screen, nullptr), Throw(Win32Error, "ConsoleOutputImplWin32::clear", "Failed to set console attributes"));

            SetConsoleCursorPosition(m_handler, screen);
        }

        void ConsoleOutputImplWin32::setTextColor(ConsoleColor color)
        {
            m_currentTextColor = color;

            applyColor();
        }

        void ConsoleOutputImplWin32::setBackgroundColor(ConsoleColor color)
        {
            m_currentBackgroundColor = color;

            applyColor();
        }

        void ConsoleOutputImplWin32::applyColor()
        {
            SetConsoleTextAttribute(m_handler, colorToTextAttribute(m_currentTextColor)| colorToBackgroundAttribute(m_currentBackgroundColor));
        }
    }
}