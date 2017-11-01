#ifndef BULL_CORE_EXCEPTION_EXCEPTION_HPP
#define BULL_CORE_EXCEPTION_EXCEPTION_HPP

#include <exception>

#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    class BULL_CORE_API Exception : public std::exception
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
        explicit Exception(const String& message);

        /*! \brief Get the Exception's message
         *
         * \return The message
         *
         */
        const char* what() const noexcept override;

    protected:

        /*! \brief Get the log message
         *
         * \return The log message
         *
         */
        virtual String getLogMessage() const;

    private:

        String m_message;
    };
}

#endif //BULL_EXCEPTION_HPP
