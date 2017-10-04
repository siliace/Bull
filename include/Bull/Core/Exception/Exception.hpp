#ifndef BULL_CORE_EXCEPTION_EXCEPTION_HPP
#define BULL_CORE_EXCEPTION_EXCEPTION_HPP

#include <vector>

#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    class BULL_CORE_API Exception
    {
    public:

        using ExceptionQueue = std::vector<const Exception*>;

        /*! \brief Get the current exception queue
         *
         * \return The exception queue
         *
         */
        static const ExceptionQueue& getExceptionQueue();

    private:

        static ExceptionQueue s_queue;

    public:

        /*! \brief Default constructor
         *
         */
        Exception();

        /*! \brief Constructor
         *
         * \param message The Exception's message
         *
         */
        explicit Exception(const String& message);

        /*! \brief Destructor
         *
         */
        ~Exception();

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

    private:

        String m_message;
    };
}

#endif //BULL_EXCEPTION_HPP
