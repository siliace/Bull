#ifndef Bull_Log_hpp
#define Bull_Log_hpp

#include <memory>

#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/Pattern/Singleton.hpp>
#include <Bull/Core/String.hpp>

namespace Bull
{
    class BULL_API Log : public Singleton<Log>
    {
    public:

        enum Level
        {
            Info,
            Notice,
            Warning,
            Error,
            Critical,
            Alert,
            Emergency
        };

    public:

        /*! \brief Constructor
         *
         */
        Log();

        /*! \brief Destructor
         *
         */
        ~Log();

        /*! \brief Add a info entry in the log
         *
         * \param message The message to add in the log
         *
         */
        virtual void info(const String& message);

        /*! \brief Add a notice entry in the log
         *
         * \param message The message to add in the log
         *
         */
        virtual void notice(const String& message);

        /*! \brief Add a warning entry in the log
         *
         * \param message The message to add in the log
         *
         */
        virtual void warning(const String& message);

        /*! \brief Add an error entry in the log
         *
         * \param message The message to add in the log
         *
         */
        virtual void error(const String& message);

        /*! \brief Add a critical entry in the log
         *
         * \param message The message to add in the log
         *
         */
        virtual void critical(const String& message);

        /*! \brief Add an alert entry in the log
         *
         * \param message The message to add in the log
         *
         */
        virtual void alert(const String& message);

        /*! \brief Add an emergency entry in the log
         *
         * \param message The message to add in the log
         *
         */
        virtual void emergency(const String& message);

        /*! \brief Add a new entry in the log
         *
         * \param message The message to add in the log
         * \param level The level of the message
         *
         */
        void log(const String& message, Log::Level level);

    protected:

        /*! \brief Constructor
         *
         * \param fileName The name of the log file
         *
         */
        Log(const String& fileName);

        File m_log;

        String m_fileName;
    };
}

#endif // Bull_Log_hpp
