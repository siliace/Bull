#include <Bull/Core/System/ConsoleOutput.hpp>
#include <Bull/Core/System/ConsoleOutputImpl.hpp>

namespace Bull
{
    ConsoleOutput::ConsoleOutput() :
        m_size(0),
        m_impl(prv::ConsoleOutputImpl::createInstance())
    {
        /// Nothing
    }

    ConsoleOutput::~ConsoleOutput() = default;

    void ConsoleOutput::write(const String& string)
    {
        write(string.getBuffer(), string.getCapacity());
    }

    void ConsoleOutput::writeLine(const String& string)
    {
        write(string + '\n');
    }

    void ConsoleOutput::clear()
    {
        m_size = 0;
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
        std::size_t written = m_impl->write(data, size);

        m_size += written;

        return written;
    }

    std::size_t ConsoleOutput::getSize() const
    {
        return m_size;
    }
}