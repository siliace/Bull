#ifndef BULL_CORE_LOG_FILELOGGER_HPP
#define BULL_CORE_LOG_FILELOGGER_HPP

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/Log/AbstractLogger.hpp>

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

        File m_file;
    };
}

#endif // BULL_CORE_LOG_FILELOGGER_HPP
