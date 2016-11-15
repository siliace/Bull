#ifndef Bull_Exception_hpp
#define Bull_Exception_hpp

#include <Bull/Core/String.hpp>
#include <Bull/Core/System/Export.hpp>
#include <Bull/Core/Time/Date.hpp>

#include <Bull/Utility/Log.hpp>

#define DeclareException(ExceptionName, message, level)                                                                  \
class ExceptionName : public Bull::Exception                                                                             \
{                                                                                                                        \
public:                                                                                                                  \
                                                                                                                         \
     static ExceptionName createAndLog(const char* function, const char* file, unsigned int line)                        \
     {                                                                                                                   \
         ExceptionName e;                                                                                                \
         e.m_function = function;                                                                                        \
         e.m_file     = file;                                                                                            \
         e.m_line     = line;                                                                                            \
         e.log();                                                                                                        \
                                                                                                                         \
         return e;                                                                                                       \
     }                                                                                                                   \
                                                                                                                         \
private:                                                                                                                 \
                                                                                                                         \
     ExceptionName() :                                                                                                   \
         Bull::Exception(message, level)                                                                                    \
     {                                                                                                                   \
                                                                                                                         \
     }                                                                                                                   \
                                                                                                                         \
     Bull::String getName() const override                                                                               \
     {                                                                                                                   \
         return #ExceptionName;                                                                                          \
     }                                                                                                                   \
}

#define DeclarePublicException(ExceptionName, message, level)    public:    DeclareException(ExceptionName, message, level);
#define DeclareProtectedException(ExceptionName, message, level) protected: DeclareException(ExceptionName, message, level);
#define DeclarePrivateException(ExceptionName, message, level)   private:   DeclareException(ExceptionName, message, level);

#define ThrowException(ExceptionName) throw ExceptionName::createAndLog(__func__, __FILE__, __LINE__)

namespace Bull
{
    class BULL_API Exception
    {
    public:

        /*! \brief Default constructor
         *
         */
        Exception() = delete;

        /*! \brief Get the name of the exception
         *
         * \return Return the name of the exception
         *
         */
        virtual String getName() const = 0;

    protected:

        /*! \brief Constructor
         *
         * \param message The message of the exception
         * \param level The log error level
         *
         */
        Exception(const String& message, Log::Level level = Log::Level::Critical);

        /*! \brief Save the exception into the log
         *
         */
        void log();

        String m_message;

        Log::Level m_level;

        String m_function;

        Date m_when;

        unsigned int m_line;

        String m_file;
    };
}

#endif // Bull_Exception_Hpp
