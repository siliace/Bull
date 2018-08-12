#ifndef BULL_CORE_EXCEPTION_EXCEPTION_HPP
#define BULL_CORE_EXCEPTION_EXCEPTION_HPP

#include <exception>

#include <Bull/Core/Log/Log.hpp>

#define DeclareExceptionFrom(ExceptionName, ParentException)                                          \
struct ExceptionName : public ParentException                                                         \
{                                                                                                     \
    ExceptionName(const String& file, Uint64 line, const String& source, const String& description) : \
        ParentException(file, line, #ExceptionName, source, description)                              \
    {                                                                                                 \
                                                                                                      \
    }                                                                                                 \
};

#define Expect(BooleanExpression, ThrowStatement) \
if(!(BooleanExpression))                          \
{                                                 \
    ThrowStatement;                               \
}                                                 \


#define Throw(Exception, Source, Description) Bull::prv::__throw<Exception>(__FILE__, __LINE__, Source, Description)

#define DeclareException(ExceptionName) DeclareExceptionFrom(ExceptionName, Bull::Exception)

namespace Bull
{
    class BULL_CORE_API Exception : public std::exception
    {
    public:

        /*! \brief Throw an Exception
         *
         * \param file
         * \param line
         * \param source
         * \param description
         *
         */
        template <typename T>
        static void throwException(const String& file, Uint64 line, const String& source, const String& description)
        {
            throw T(file, line, source, description);
        }

    public:

        /*! \brief Get the name file where the Exception was thrown
         *
         * \return The name of the file
         *
         */
        const String& getFile() const;

        /*! \brief Get the line where the Exception was thrown
         *
         * \return The line
         *
         */
        Uint64 getLine() const;

        /*! \brief Get the type of Exception thrown
         *
         * \return The type of Exception
         *
         */
        const String& getType() const;

        /*! \brief Get the method where the Exception was thrown
         *
         * \return The method
         *
         */
        const String& getSource() const;

        /*!! \brief Get the message describing the Exception
         *
         * \return The description
         *
         */
        const String& getDescription() const;

    protected:

        /*! \brief Constructor
         *
         * \param file        The name file where the Exception was thrown
         * \param line        The line where the Exception was thrown
         * \param type        The type of Exception thrown
         * \param source      The method where the Exception was thrown
         * \param description The message describing the Exception
         *
         */
        Exception(const String& file, Uint64 line, const String& type, const String& source, const String& description);

    private:

        /*! \brief Get the exception's description as a C-Style string
         *
         * \return The description
         *
         */
        const char* what() const noexcept override;

    private:

        Log::Instance m_log;
        String        m_file;
        Uint64        m_line;
        String        m_type;
        String        m_source;
        String        m_description;
    };

    namespace prv
    {
        template <typename T, typename = std::enable_if<std::is_base_of<Exception, T>::value>>
        void __throw(const String& file, Uint64 line, const String& source, const String& description)
        {
            Exception::throwException<T>(file, line, source, description);
        }
    }
}

#endif // BULL_CORE_EXCEPTION_EXCEPTION_HPP
