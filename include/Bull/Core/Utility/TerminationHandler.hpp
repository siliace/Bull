#ifndef BULL_CORE_UTILITY_TERMINATIONHANDLER_HPP
#define BULL_CORE_UTILITY_TERMINATIONHANDLER_HPP

#include <functional>
#include <vector>

#include <Bull/Core/Exception/Exception.hpp>

namespace Bull
{
    class BULL_CORE_API TerminationHandler : public Singleton<TerminationHandler>
    {
    public:

        using Callback = std::function<void()>;

    private:

        /*! \brief Run every registered callbacks
         *
         */
        static void runCallbacks();

    public:

        /*! \brief Default constructor
         *
         */
        TerminationHandler();

        /*! \brief Register a callback to call when the program exists normaly
         *
         * \param callback The callback to call
         *
         */
        void registerCallback(const Callback& callback);

        /*! \brief Reset the termination handler to the OS default one
         *
         */
        void reset();

    private:

        /*! \brief Ensure the termination handler will use at the program end
         *
         */
        void ensureInitialized();

        /*! \brief Get callbacks to call a the end of the program
         *
         * \return Callbacks
         *
         */
        std::vector<Callback> getCallbacks();

    private:

        bool m_initialized;
        std::vector<Callback> m_callbacks;
        std::terminate_handler m_terminateHandler;
    };
}

#endif // BULL_CORE_UTILITY_TERMINATIONHANDLER_HPP
