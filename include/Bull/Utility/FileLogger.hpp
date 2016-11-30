#ifndef Bull_FileLogger_hpp
#define Bull_FileLogger_hpp

#include <Bull/Core/AbstractLogger.hpp>
#include <Bull/Core/Exception.hpp>
#include <Bull/Core/FileSystem/File.hpp>

namespace Bull
{
    class FileLogger : public AbstractLogger
    {
    public:

        /*! \brief Constructor
         *
         * \param filename The name of the log file
         *
         */
        FileLogger(const String& filename);

        DeclarePublicException(FailToOpenLog, "The log file could not be created or opened", Log::Level::Critical);

    protected:

        /*! \brief Add a new entry in the log
         *
         * \param message The entry to add in the log
         *
         */
        void write(const String& entry) override;

    private:

        File m_logFile;
    };
}

#endif // Bull_FileLogger_hpp
