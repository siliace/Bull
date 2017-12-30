#include <algorithm>

#include <Bull/Core/Exception/Exception.hpp>
#include <Bull/Core/Log/Log.hpp>

namespace Bull
{
    Exception::Exception(const String& message) :
        m_message(message)
    {
        Log::getInstance()->write(getLogMessage(), LogLevel::LogLevel_Error);
    }

    const char* Exception::what() const noexcept
    {
        return m_message.getBuffer();
    }

    String Exception::getLogMessage() const
    {
        return m_message;
    }
}