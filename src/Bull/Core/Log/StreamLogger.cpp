#include <Bull/Core/Log/StreamLogger.hpp>

namespace Bull
{
    StreamLogger::StreamLogger(OutStream& stream) :
            m_writer(stream)
    {
        /// Nothing
    }

    void StreamLogger::write(const std::string& entry)
    {
        m_writer.writeLine(entry);
    }
}