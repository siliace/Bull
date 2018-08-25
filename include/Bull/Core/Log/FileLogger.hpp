#ifndef BULL_CORE_LOG_FILELOGGER_HPP
#define BULL_CORE_LOG_FILELOGGER_HPP

#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/Log/AbstractLogger.hpp>
#include <Bull/Core/IO/TextWriter.hpp>

namespace Bull
{
    class BULL_CORE_API FileLogger : public AbstractLogger
    {
    public:

        /*! \brief Default constructor
         *
         */
        FileLogger();

        /*! \brief Constructor
         *
         * \param path The Path of the log file
         *
         */
        explicit FileLogger(const Path& path);

    protected:

        /*! \brief Write an entry in the FileLogger
         *
         * \param entry The entry to write
         *
         */
        void write(const String& entry) override;

    private:

        File       m_file;
        TextWriter m_writer;
    };
}

#endif // BULL_CORE_LOG_FILELOGGER_HPP
