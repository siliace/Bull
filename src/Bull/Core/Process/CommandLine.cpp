#include <Bull/Core/Exception/LogicError.hpp>
#include <Bull/Core/IO/StringStream.hpp>
#include <Bull/Core/Process/CommandLine.hpp>

namespace Bull
{
    CommandLine::CommandLine(const String& program) :
        m_program(program)
    {
        /// Nothing
    }

    CommandLine& CommandLine::withOption(const String& value, const String& prefix)
    {
        m_options.push_back({prefix, value});

        return (*this);
    }

    String CommandLine::toString() const
    {
        StringStream ss;

        if(!m_prefix.isEmpty())
        {
            ss << m_prefix;
        }

        if(m_program.isEmpty())
        {
            throw LogicError("Program not defined");
        }

        ss << m_program;

        for(const Option& option : m_options)
        {
            ss << " " << option.prefix << option.value;
        }

        return ss.toString();
    }

    const String& CommandLine::getProgram() const
    {
        return m_program;
    }

    std::vector<String> CommandLine::getOptions(bool withProgram) const
    {
        std::vector<String> options;

        if(withProgram)
        {
            if(m_program.isEmpty())
            {
                throw LogicError("Program not defined");
            }

            options.emplace_back(m_program);
        }

        for(const Option& option : m_options)
        {
            StringStream ss;

            ss << option.prefix << option.value;

            options.emplace_back(ss.toString());
        }

        return options;
    }
}