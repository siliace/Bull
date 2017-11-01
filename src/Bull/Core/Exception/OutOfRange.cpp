#include <Bull/Core/Exception/OutOfRange.hpp>
#include <Bull/Core/IO/StringStream.hpp>

namespace Bull
{
    OutOfRange::OutOfRange() :
        min(0),
        max(0),
        index(0),
        m_hasIndex(false)
    {
        /// Nothing
    }

    OutOfRange::OutOfRange(const String& message) :
        RuntimeError(message),
        min(0),
        max(0),
        index(0),
        m_hasIndex(false)
    {
        /// Nothing
    }

    OutOfRange::OutOfRange(const String& message, Index min, Index max, Index index) :
        RuntimeError(message),
        min(min),
        max(max),
        index(index),
        m_hasIndex(true)
    {
        /// Nothing
    }

    String OutOfRange::getLogMessage() const
    {
        StringStream ss;

        ss << what();

        if(m_hasIndex)
        {
            ss << "(Index between " << String::number(min) << "and " << String::number(max) << ", has " << String::number(index) << ")";
        }

        return ss.toString();
    }
}