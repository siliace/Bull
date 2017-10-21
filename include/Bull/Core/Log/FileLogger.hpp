#ifndef BULL_CORE_LOG_FILELOGGER_HPP
#define BULL_CORE_LOG_FILELOGGER_HPP

#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/Log/AbstractLogger.hpp>

namespace Bull
{
    class FileLogger : public AbstractLogger
    {
    public:

        /*! \brief Default constructor
         *
         */
        FileLogger();

        /*! \brief Constructor
         *
         * \param filename The name of the log file
         *
         */
        explicit FileLogger(const String& filename);

    protected:

        /*! \brief Add a new entry in the log
         *
         * \param message The log message
         * \param level   The error level of the message
         *
         */
        void write(const String& message, LogLevel level) override;

    private:

        File m_logFile;
    };
}

#endif // BULL_CORE_LOGGER_FILELOGGER_HPP
