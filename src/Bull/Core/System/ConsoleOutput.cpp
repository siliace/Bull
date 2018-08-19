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

    std::size_t ConsoleOutput::write(const ByteArray& bytes)
    {
        return m_impl->write(bytes);
    }

    void ConsoleOutput::flush()
    {
        m_impl->flush();
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
}