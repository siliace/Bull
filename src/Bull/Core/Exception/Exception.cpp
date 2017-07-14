#include <Bull/Core/Exception/Exception.hpp>
#include <Bull/Core/Log/Log.hpp>

namespace Bull
{
    Exception::Exception(const String& message) :
        m_message(message)
    {
        Log::get()->write(getLogMessage(), Log::Level::Error);
    }

    const String& Exception::getMessage() const
    {
        return m_message;
    }

    String Exception::getLogMessage() const
    {
        return m_message;
    }
}