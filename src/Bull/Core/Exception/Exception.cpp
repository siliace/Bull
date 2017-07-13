#include <Bull/Core/Exception/Exception.hpp>
#include <Bull/Core/IO/StringStream.hpp>
#include <Bull/Core/Log/Log.hpp>

namespace Bull
{
    Exception::Exception(const String& message) :
        m_message(message)
    {
        StringStream ss;

        ss << "[" << getExceptionType() << "] : " << getLogMessage();

        Log::get()->write(ss.toString(), Log::Level::Error);
    }

    const String& Exception::getMessage() const
    {
        return m_message;
    }

    String Exception::getLogMessage() const
    {
        return m_message;
    }

    String Exception::getExceptionType() const
    {
        return "Exception";
    }
}