#ifndef BULL_CORE_LOG_STREAMLOGGER_HPP
#define BULL_CORE_LOG_STREAMLOGGER_HPP

#include <Bull/Core/IO/TextWriter.hpp>
#include <Bull/Core/Log/AbstractLogger.hpp>

namespace Bull
{
    class BULL_CORE_API StreamLogger : public AbstractLogger
    {
    public:

        /** \brief Constructor
         *
         * \param stream The OutStream to write in
         *
         */
        explicit StreamLogger(OutStream& stream);

    protected:

        /** \brief Write a log entry into the OutStream
         *
         * \param entry The entry to write
         *
         */
        void write(const std::string& entry) override;

    private:

        TextWriter m_writer;
    };
}

#endif // BULL_CORE_LOG_STREAMLOGGER_HPP
