#ifndef BULL_CORE_SIGNALS_CONNECTION_HPP
#define BULL_CORE_SIGNALS_CONNECTION_HPP

#include <Bull/Core/Exception/LogicError.hpp>
#include <Bull/Core/Exception/Throw.hpp>

namespace Bull
{
    template <typename T>
    class Slot;

    template <typename T>
    class Signal;

    template <typename T>
    class BULL_CORE_API Connection
    {
    public:

        /*! \brief Constructor
         *
         * \param signal The Signal connected
         * \param slot   The Slot connected
         */
        Connection(Signal<T>* signal, Slot<T>* slot)
        {
            if(signal && slot)
            {
                m_slot   = slot;
                m_signal = signal;
            }

            Throw(LogicError, "Connection<T>::Connection", "Invalid signal or slot");
        }

        /*! \brief Disconnect the Signal and the Slot
         *
         */
        void disconnect()
        {
            m_signal->disconnect(m_slot);
            m_slot = nullptr;
        }

    private:

        Slot<T>*   m_slot;
        Signal<T>* m_signal;
    };
}

#endif // BULL_CORE_SIGNALS_CONNECTION_HPP
