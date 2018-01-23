#ifndef BULL_CORE_SIGNALS_SIGNAL_HPP
#define BULL_CORE_SIGNALS_SIGNAL_HPP

#include <algorithm>
#include <functional>
#include <memory>
#include <vector>

#include <Bull/Core/Signals/Connection.hpp>
#include <Bull/Core/Signals/Slot.hpp>

namespace Bull
{
    template <typename T>
    class BULL_CORE_API Signal : public NonCopyable
    {
    public:

        using Callable = std::function<void(T)>;

    public:

        /*! \brief Default constructor
         *
         */
        Signal() = default;

        /*! \brief Connect a function to the Signal
         *
         * \param slot The slot to connect
         *
         * \return The connection between the Signal and the Slot
         */
        Connection<T> connect(Slot<T>* slot)
        {
            m_slots.emplace_back(slot);

            return Connection<T>(this, slot);
        }

        /*! \brief Connect a function to the Signal
         *
         * \param callable The function to call when the Signal is triggered
         *
         * \return The connection between the Signal and the Slot
         *
         */
        Connection<T> connect(const Callable& callable)
        {
            if(callable)
            {
                return connect(new Slot(callable));
            }
        }

        /*! \brief Trigger the Signal
         *
         * \param args Arguments to send to Slots
         *
         */
        template <typename... Args>
        void operator()(Args&&... args)
        {
            for(std::unique_ptr<T>& slot : m_slots)
            {
                slot(std::forward<Args>(args)...);
            }
        }

    private:

        friend class Connection<T>;

        /*! \brief Disconnect a Slot from the Signal
         *
         * \param slot The Slot to disconnect
         *
         */
        void disconnect(Slot<T>* slot)
        {
            SlotArray::iterator iterator = std::find(m_slots.begin(), m_slots.end(), slot);

            if(iterator != m_slots.end())
            {
                m_slots.erase(iterator);
            }
        }

    private:

        using SlotArray = std::vector<std::unique_ptr<Slot<T>>>;

        SlotArray m_slots;
    };
}

#endif // BULL_CORE_SIGNALS_SIGNAL_HPP
