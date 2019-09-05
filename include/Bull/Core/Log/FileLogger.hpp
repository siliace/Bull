#ifndef BULL_CORE_LOG_FILELOGGER_HPP
#define BULL_CORE_LOG_FILELOGGER_HPP

#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/Log/StreamLogger.hpp>

namespace Bull
{
    class BULL_CORE_API FileLogger : public StreamLogger
    {
    public:

        /** \brief Default constructor
         *
         */
        FileLogger();

        /** \brief Constructor
         *
         * \param path The Path of the log file
         *
         */
        explicit FileLogger(const Path& path);

    private:

        File m_file;
    };
}

#endif // BULL_CORE_LOG_FILELOGGER_HPP
