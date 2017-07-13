#ifndef BULL_CORE_EXCEPTION_EXCEPTION_HPP
#define BULL_CORE_EXCEPTION_EXCEPTION_HPP

#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    class BULL_CORE_API Exception
    {
    public:

        /*! \brief Default constructor
         *
         */
        Exception() = default;

        /*! \brief Constructor
         *
         * \param message The Exception's message
         *
         */
        Exception(const String& message);

        /*! \brief Get the Exception's message
         *
         * \return The message
         *
         */
        const String& getMessage() const;

    protected:

        /*! \brief Get the log message
         *
         * \return The log message
         *
         */
        virtual String getLogMessage() const;

        /*! \brief Get the type of the Exception
         *
         * \return The type
         *
         */
        virtual String getExceptionType() const;

    private:

        String m_message;
    };
}

#endif //BULL_EXCEPTION_HPP
