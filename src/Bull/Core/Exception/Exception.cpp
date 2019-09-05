#include <sstream>

#include <Bull/Core/Exception/Exception.hpp>
#include <Bull/Core/Log/Log.hpp>

namespace Bull
{
    const std::string& Exception::getFile() const
    {
        return m_file;
    }

    Uint64 Exception::getLine() const
    {
        return m_line;
    }

    const std::string& Exception::getType() const
    {
        return m_type;
    }

    const std::string& Exception::getSource() const
    {
        return m_source;
    }

    const std::string& Exception::getDescription() const
    {
        return m_description;
    }

    Exception::Exception(const std::string& file, Uint64 line, const std::string& type, const std::string& source, const std::string& description) :
            m_file(file),
            m_line(line),
            m_type(type),
            m_source(source),
            m_description(description)
    {
        std::ostringstream oss;

        oss << "Exception " << m_type << " from file " << m_file << " at line " << std::to_string(m_line)
            << " in method " << m_source << " : " << m_description;

        Log::getInstance().error(oss.str());
    }

    const char* Exception::what() const noexcept
    {
        return m_description.c_str();
    }
}