#include <algorithm>

#include <Bull/Core/Exception/Exception.hpp>
#include <Bull/Core/Log/Log.hpp>

namespace Bull
{
    Exception::ExceptionQueue Exception::s_queue;

    const Exception::ExceptionQueue& Exception::getExceptionQueue()
    {
        return s_queue;
    }

    Exception::Exception()
    {
        s_queue.emplace_back(this);
    }

    Exception::Exception(const String& message) :
        m_message(message)
    {
        Log::get()->write(getLogMessage(), Log::Level::Error);
    }

    Exception::~Exception()
    {
        s_queue.erase(std::find(s_queue.begin(), s_queue.end(), this));
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