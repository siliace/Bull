#include <Bull/Core/Exception/LogicError.hpp>
#include <Bull/Core/IO/OutStringStream.hpp>

namespace Bull
{
    LogicError::LogicError(const String& message) :
        Exception(message)
    {
        /// Nothing
    }

    LogicError::LogicError(const String& message, const String& expected) :
        Exception(message),
        m_expected(expected)
    {
        /// Nothing
    }

    const String& LogicError::getExpected() const
    {
        return m_expected;
    }

    String LogicError::getLogMessage() const
    {
        OutStringStream ss;

        ss << what();

        if(!m_expected.isEmpty())
        {
            ss << "(Expected " << m_expected << ")";
        }

        return ss.toString();
    }
}
