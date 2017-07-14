#ifndef BULL_CORE_EXCEPTION_LOGICERROR_HPP
#define BULL_CORE_EXCEPTION_LOGICERROR_HPP

#include <Bull/Core/Exception/Exception.hpp>

namespace Bull
{
    class BULL_CORE_API LogicError : public Exception
    {
    public:

        /*! \brief Default constructor
         *
         */
        LogicError() = default;

        /*! \brief Constructor
         *
         * \param message The Exception's message
         *
         */
        LogicError(const String& message);

        /*! \brief Constructor
         *
         * \param message  The Exception's message
         * \param expected The expected value
         *
         */
        LogicError(const String& message, const String& expected);

        /*! \brief Get the expected value
         *
         * \return The expected value
         *
         */
        const String& getExpected() const;

    protected:

        /*! \brief Get the log message
         *
         * \return The log message
         *
         */
        virtual String getLogMessage() const override;

    private:

        String m_expected;
    };
}

#endif // BULL_CORE_EXCEPTION_LOGICERROR_HPP
