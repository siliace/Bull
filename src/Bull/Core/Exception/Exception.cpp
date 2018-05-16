#include <Bull/Core/Exception/Exception.hpp>
#include <Bull/Core/IO/OutStringStream.hpp>
#include <Bull/Core/Utility/StringUtils.hpp>

namespace Bull
{
    Exception Exception::s_lastThrown("", 0, "", "", "");

    const Exception& Exception::getLastThrown()
    {
        return s_lastThrown;
    }

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

    Exception::Exception(const String& file, Uint64 line, const String& type, const String& source, const String& description) noexcept :
        m_file(file),
        m_line(line),
        m_type(type),
        m_source(source),
        m_description(description)
    {
        OutStringStream oss;

        oss << "Exception " << m_type << " from file " << m_file << " at line " << StringUtils::number(m_line)
            << " in method " << m_source << " : " << m_description;

        m_log->error(oss.toString());
    }

    const char* Exception::what() const noexcept
    {
        return m_description.getBuffer();
    }
}