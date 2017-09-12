#include <Bull/Core/IO/StringStream.hpp>
#include <Bull/Core/Loader/ParameterNotFound.hpp>

namespace Bull
{
    ParameterNotFound::ParameterNotFound(const String& name) :
        m_name(name)
    {
        /// Nothing
    }

    const String& ParameterNotFound::getName() const
    {
        return m_name;
    }

    String ParameterNotFound::getLogMessage() const
    {
        StringStream ss;

        ss << "Parameter " << getName() << " not found";

        return ss.toString();
    }
}