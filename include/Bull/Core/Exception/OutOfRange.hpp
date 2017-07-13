#ifndef BULL_CORE_EXCEPTION_OUTOFRANGE_HPP
#define BULL_CORE_EXCEPTION_OUTOFRANGE_HPP

#include <Bull/Core/Exception/RuntimeError.hpp>

namespace Bull
{
    class BULL_CORE_API OutOfRange : public RuntimeError
    {
    public:

        /*! \brief Default constructor
         *
         */
        OutOfRange();

        /*! \brief Constructor
         *
         * \param message
         *
         */
        OutOfRange(const String& message);

        /*! \brief Constructor
         *
         * \param message
         * \param min
         * \param max
         * \param index
         *
         */
        OutOfRange(const String& message, std::size_t min, std::size_t max, std::size_t index);

        std::size_t index;
        std::size_t min, max;

    protected:

        /*! \brief Get the log message
         *
         * \return The log message
         *
         */
        virtual String getLogMessage() const override;

        /*! \brief Get the type of the Exception
         *
         * \return The type
         *
         */
        virtual String getExceptionType() const override;

    private:

        bool m_hasIndex;
    };
}

#endif // BULL_CORE_EXCEPTION_OUTOFRANGE_HPP
