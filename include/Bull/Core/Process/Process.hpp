#ifndef BULL_CORE_PROCESS_PROCESS_HPP
#define BULL_CORE_PROCESS_PROCESS_HPP

#include <memory>
#include <vector>

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Process/CommandLine.hpp>
#include <Bull/Core/Process/ProcessState.hpp>

namespace Bull
{
    namespace prv
    {
        class ProcessImpl;
    }

    class BULL_CORE_API Process : public NonCopyable
    {
    public:

        typedef unsigned int Id;

    public:

        /*! \brief Default constructor
         *
         */
        Process() = default;

        /*! \brief Constructor
         *
         * \param commandLine The CommandLine to start
         *
         */
        explicit Process(const CommandLine& commandLine);

        /*! \brief Start the Process
         *
         * \param commandLine The CommandLine to start
         *
         */
        void start(const CommandLine& commandLine);

        /*! \brief Get the PID of the Process
         *
         * \return The PID of the Process
         *
         */
        Id getId() const;

    private:

        std::unique_ptr<prv::ProcessImpl> m_impl;
        CommandLine                       m_commandLine;
    };
}

#endif // BULL_CORE_PROCESS_PROCESS_HPP
