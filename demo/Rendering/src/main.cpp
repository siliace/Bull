#include <Bull/Core/System/ConsoleOutput.hpp>

int main()
{
    Bull::ConsoleOutput cout;

    cout.setTextColor(Bull::ConsoleColor_Red);
    cout.setBackgroundColor(Bull::ConsoleColor_White);
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.clear();

    cout.setTextColor(Bull::ConsoleColor_Blue);
    cout.setBackgroundColor(Bull::ConsoleColor_Gray);
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.writeLine("Hello world");
    cout.clear();

    return 0;
}