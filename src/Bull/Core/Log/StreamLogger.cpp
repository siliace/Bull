#include <Bull/Core/Log/StreamLogger.hpp>

namespace Bull
{
    StreamLogger::StreamLogger(OutStream& stream) :
        m_writer(stream)
    {
        /// Nothing
    }

    void StreamLogger::write(const String& entry)
    {
        m_writer.writeLine(entry);
    }
}