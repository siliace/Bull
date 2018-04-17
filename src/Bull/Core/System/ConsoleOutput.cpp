#include <Bull/Core/System/ConsoleOutput.hpp>
#include <Bull/Core/System/ConsoleOutputImpl.hpp>

namespace Bull
{
    ConsoleOutput::ConsoleOutput() :
        m_impl(prv::ConsoleOutputImpl::createInstance())
    {
        /// Nothing
    }

    ConsoleOutput::~ConsoleOutput()
    {
        flush();
    }

    void ConsoleOutput::write(const String& string)
    {
        write(string.getBuffer(), string.getSize());
    }

    void ConsoleOutput::writeLine(const String& string)
    {
        write(string + '\n');
    }

    void ConsoleOutput::clear()
    {
        m_impl->clear();
    }

    void ConsoleOutput::setTextColor(ConsoleColor color)
    {
        m_impl->setTextColor(color);
    }

    void ConsoleOutput::setBackgroundColor(ConsoleColor color)
    {
        m_impl->setBackgroundColor(color);
    }

    std::size_t ConsoleOutput::write(const void* data, std::size_t size)
    {
        return m_impl->write(data, size);
    }

    void ConsoleOutput::flush()
    {
        m_impl->flush();
    }
}