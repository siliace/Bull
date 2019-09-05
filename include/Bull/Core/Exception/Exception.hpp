#ifndef BULL_CORE_EXCEPTION_EXCEPTION_HPP
#define BULL_CORE_EXCEPTION_EXCEPTION_HPP

#include <exception>
#include <string>

#include <Bull/Core/Export.hpp>

#define DeclareExceptionFrom(ExceptionName, ParentException)                                          \
struct ExceptionName : public ParentException                                                         \
{                                                                                                     \
    ExceptionName(const std::string& file, Uint64 line, const std::string& source, const std::string& description) : \
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


#define Throw(Exception, Description) Bull::prv::__throw<Exception>(__FILE__, __LINE__, BULL_PRETTY_FUNCTION, Description)

#define DeclareException(ExceptionName) DeclareExceptionFrom(ExceptionName, Bull::Exception)

namespace Bull
{
    class BULL_CORE_API Exception : public std::exception
    {
    public:

        /** \brief Throw an Exception
         *
         * \param file
         * \param line
         * \param source
         * \param description
         *
         */
        template <typename T>
        static void throwException(const std::string& file, Uint64 line, const std::string& source, const std::string& description)
        {
            throw T(file, line, source, description);
        }

    public:

        /** \brief Get the name file where the Exception was thrown
         *
         * \return The name of the file
         *
         */
        const std::string& getFile() const;

        /** \brief Get the line where the Exception was thrown
         *
         * \return The line
         *
         */
        Uint64 getLine() const;

        /** \brief Get the type of Exception thrown
         *
         * \return The type of Exception
         *
         */
        const std::string& getType() const;

        /** \brief Get the method where the Exception was thrown
         *
         * \return The method
         *
         */
        const std::string& getSource() const;

        /**! \brief Get the message describing the Exception
         *
         * \return The description
         *
         */
        const std::string& getDescription() const;

    protected:

        /** \brief Constructor
         *
         * \param file        The name file where the Exception was thrown
         * \param line        The line where the Exception was thrown
         * \param type        The type of Exception thrown
         * \param source      The method where the Exception was thrown
         * \param description The message describing the Exception
         *
         */
        Exception(const std::string& file, Uint64 line, const std::string& type, const std::string& source, const std::string& description);

    private:

        /** \brief Get the exception's description as a C-Style string
         *
         * \return The description
         *
         */
        const char* what() const noexcept override;

    private:

        std::string m_file;
        Uint64 m_line;
        std::string m_type;
        std::string m_source;
        std::string m_description;
    };

    namespace prv
    {
        template <typename T, typename = std::enable_if<std::is_base_of<Exception, T>::value>>
        void __throw(const std::string& file, Uint64 line, const std::string& source, const std::string& description)
        {
            Exception::throwException<T>(file, line, source, description);
        }
    }
}

#endif // BULL_CORE_EXCEPTION_EXCEPTION_HPP
