#include <Bull/Core/Utility/TerminationHandler.hpp>

namespace Bull
{
    void TerminationHandler::runCallbacks()
    {
        for(const Callback& callback : getInstance()->getCallbacks()) {
            callback();
        }
    }

    TerminationHandler::TerminationHandler() :
        m_initialized(false)
    {
        /// Nothing
    }

    TerminationHandler::~TerminationHandler()
    {
        reset();
    }

    void TerminationHandler::registerCallback(const TerminationHandler::Callback& callback)
    {
        ensureInitialized();

        m_callbacks.push_back(callback);
    }

    void TerminationHandler::reset()
    {
        std::set_terminate(m_terminateHandler);

        m_callbacks.clear();

        m_initialized = false;
        m_terminateHandler = nullptr;
    }

    void TerminationHandler::ensureInitialized()
    {
        if(!m_initialized)
        {
            m_initialized = true;
            m_terminateHandler = std::set_terminate(&TerminationHandler::runCallbacks);
        }
    }

    std::vector<TerminationHandler::Callback> TerminationHandler::getCallbacks()
    {
        return m_callbacks;
    }
}