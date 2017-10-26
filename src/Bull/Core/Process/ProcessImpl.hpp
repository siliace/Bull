#ifndef BULL_CORE_PROCESS_PROCESSIMPL_HPP
#define BULL_CORE_PROCESS_PROCESSIMPL_HPP

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Process/Process.hpp>
#include <Bull/Core/Time/Time.hpp>

namespace Bull
{
    namespace prv
    {
        class ProcessImpl : public NonCopyable
        {
        public:

            static ProcessImpl* createInstance(const CommandLine& commandLine);

        public:

            /*! \brief Wait for the Process to stop
             *
             * \return The state of the Process
             *
             */
            virtual ProcessState wait() = 0;

            /*! \brief Wait for the Process to stop
             *
             * \param timeout The time to wait before failure
             *
             * \return The state of the Process
             *
             */
            virtual ProcessState wait(const Time& timeout) = 0;

            /*! \brief Get the PID of the Process
             *
             * \return The PID of the Process
             *
             */
            virtual Process::Id getId() const = 0;
        };
    }
}

#endif // BULL_CORE_PROCESS_PROCESSIMPL_HPP
