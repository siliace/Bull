#ifndef BULL_CORE_PATTERN_SIGNAL_HPP
#define BULL_CORE_PATTERN_SIGNAL_HPP

#include <functional>
#include <vector>

#include <Bull/Core/Export.hpp>

namespace Bull
{
    template <typename... Args>
    class BULL_CORE_API Signal
    {
    public:

        using Slot = std::function<void(Args...)>;

    public:

        /*! \brief Connect a Slot to the Signal
         *
         * \param slot To Slot to connect
         *
         */
        void connect(const Slot& slot)
        {
            m_slots.push_back(slot);
        }

        /*! \brief Emit a Signal
         *
         * \param args Arguments to send to each Slot
         *
         */
        void emit(Args&&... args)
        {
            for(const Slot& slot : m_slots)
            {
                slot(std::forward<Args>(args)...);
            }
        }

        /*! \brief Emit a Signal
         *
         * \param args Arguments to send to each Slot
         *
         */
        void operator()(Args&&... args)
        {
            emit(std::forward<Args>(args)...);
        }

    private:

        std::vector<Slot> m_slots;
    };
}

#endif // BULL_CORE_PATTERN_SIGNAL_HPP
