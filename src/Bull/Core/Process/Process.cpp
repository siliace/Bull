#include <Bull/Core/Process/Process.hpp>

namespace Bull
{
    Process::Process(const CommandLine& commandLine)
    {
        start(commandLine);
    }

    void Process::start(const CommandLine& commandLine)
    {

    }

    Id Process::getId() const
    {
        if(m_impl)
        {
            return m_impl->getId();
        }

        return 0;
    }
}