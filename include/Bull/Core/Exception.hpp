#ifndef Bull_Exception_hpp
#define Bull_Exception_hpp

#include <Bull/Core/Log.hpp>
#include <Bull/Core/String.hpp>
#include <Bull/Core/System/Export.hpp>
#include <Bull/Core/Time/Date.hpp>

#define DeclareException(ExceptionName, ...)                                                                             \
class ExceptionName : public Bull::Exception                                                                             \
{                                                                                                                        \
public:                                                                                                                  \
                                                                                                                         \
     static ExceptionName createAndLog(const char* function)                                                             \
     {                                                                                                                   \
         ExceptionName e;                                                                                                \
         e.m_function = function;                                                                                        \
         e.log();                                                                                                        \
                                                                                                                         \
         return e;                                                                                                       \
     }                                                                                                                   \
                                                                                                                         \
private:                                                                                                                 \
                                                                                                                         \
     ExceptionName() :                                                                                                   \
         Bull::Exception(__VA_ARGS__)                                                                                    \
     {                                                                                                                   \
                                                                                                                         \
     }                                                                                                                   \
                                                                                                                         \
     Bull::String getName() const override                                                                               \
     {                                                                                                                   \
         return #ExceptionName;                                                                                          \
     }                                                                                                                   \
}

#define DeclarePublicException(ExceptionName, ...)    public:    DeclareException(ExceptionName, __VA_ARGS__);
#define DeclareProtectedException(ExceptionName, ...) protected: DeclareException(ExceptionName, __VA_ARGS__);
#define DeclarePrivateException(ExceptionName, ...)   private:   DeclareException(ExceptionName, __VA_ARGS__);

#define ThrowException(ExceptionName) throw ExceptionName::createAndLog(__func__)

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
    };
}

#endif // Bull_Exception_Hpp
