#include <Bull/Core/System/ConsoleOutput.hpp>
#include <Bull/Core/Utility/StringUtils.hpp>
#include <Bull/Core/Time/Duration.hpp>
#include <Bull/Core/Concurrency/Thread.hpp>

int main()
{
    Bull::ConsoleOutput cout;

    for(std::size_t i = 0; i < 10; i++)
    {
        cout.writeLine(Bull::StringUtils::random(10));
        Bull::Thread::sleep(Bull::Duration::seconds(0.5f));
    }
}