#include <Bull/Core/Exception/Exception.hpp>
#include <Bull/Core/IO/OutStringStream.hpp>

namespace Bull
{
    const String& Exception::getFile() const
    {
        return m_file;
    }

    Uint64 Exception::getLine() const
    {
        return m_line;
    }

    const String& Exception::getType() const
    {
        return m_type;
    }

    const String& Exception::getSource() const
    {
        return m_source;
    }

    const String& Exception::getDescription() const
    {
        return m_description;
    }

    Exception::Exception(const String& file, Uint64 line, const String& type, const String& source, const String& description) :
        m_file(file),
        m_line(line),
        m_type(type),
        m_source(source),
        m_description(description)
    {
        OutStringStream oss;

        oss << "Exception " << m_type << " from file " << m_file << " at line " << String::number(m_line)
            << " in method " << m_source << " : " << m_description;

        m_log->write(oss.toString(), LogLevel_Error);
    }

    const char* Exception::what() const noexcept
    {
        return m_description.getBuffer();
    }
}