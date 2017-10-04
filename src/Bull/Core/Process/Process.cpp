#include <Bull/Core/Process/Process.hpp>
#include <Bull/Core/Process/ProcessImpl.hpp>

namespace Bull
{
    Process::Id Process::getCurrentPid()
    {
        return prv::ProcessImpl::getCurrentPid();
    }

    Process::Id Process::getCurrentParentPid()
    {
        return prv::ProcessImpl::getCurrentParentPid();
    }

    Process::Process(const String& commandLine, const Path& workingDirectory) :
        m_workingDirectory(workingDirectory)
    {
        std::vector<String> tokens = commandLine.explode(' ');

        m_arguments   = tokens;
        m_commandLine = m_arguments.front();
    }

    Process::~Process()
    {
        stop();
    }

    bool Process::start()
    {
        if(!isRunning())
        {
            if(m_arguments.front() != m_commandLine)
            {
                m_arguments.insert(m_arguments.begin(), m_commandLine);
            }

            m_impl.reset(prv::ProcessImpl::createInstance(m_commandLine, m_workingDirectory, m_arguments));

            return true;
        }

        return false;
    }

    bool Process::isRunning() const
    {
        return getStatus() == Running;
    }

    void Process::stop()
    {
        m_impl.reset();
    }

    const String& Process::getCommandLine() const
    {
        return m_commandLine;
    }

    const Path& Process::getWorkingDirectory() const
    {
        return m_workingDirectory;
    }

    Process::Id Process::getPid() const
    {
        if(m_impl)
        {
            return m_impl->getPid();
        }

        return 0;
    }

    Process::Status Process::getStatus() const
    {
        if(m_impl)
        {
            return m_impl->getStatus();
        }

        return Ready;
    }

    Process::ExitCode Process::getExitCode(bool block) const
    {
        if(m_impl)
        {
            return m_impl->getExitCode(block);
        }

        return None;
    }
}
