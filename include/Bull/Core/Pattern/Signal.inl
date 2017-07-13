namespace Bull
{
    template <typename... Args>
    void Signal<Args...>::bind(Signal<Args...>::Slot& slot)
    {
        slot.addSignal(this);
        m_slots.push_back(slot);
    }

    template <typename... Args>
    void Signal<Args...>::operator()(Args... args) const
    {
        for(const Signal<Args...>::Slot& slot : m_slots)
        {
            slot.call(args...);
        }
    }

    template <typename... Args>
    void Signal<Args...>::unbind(Uint64 slotId)
    {
        for(unsigned int i = 0; i < m_slots.size(); i++)
        {
            if(m_slots[i].getId() == slotId)
            {
                m_slots.erase(m_slots.begin() + i);
            }
        }
    }
}