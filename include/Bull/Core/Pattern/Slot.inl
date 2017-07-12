namespace Bull
{
    template <typename... Args>
    Signal<Args...>::Slot::Slot() :
        m_id(0)
    {
        /// Nothing
    }

    template <typename... Args>
    Signal<Args...>::Slot::Slot(const Function& function) :
        Slot()
    {
        reset(function);
    }

    template <typename... Args>
    template <typename Object>
    Signal<Args...>::Slot::Slot(Object* instance, void(Object::*method)(Args...)) :
        Slot()
    {
        reset(instance, method);
    }

    template <typename... Args>
    template <typename Object>
    Signal<Args...>::Slot::Slot(Object& instance, void(Object::*method)(Args...)) :
        Slot()
    {
        reset(instance, method);
    }

    template <typename... Args>
    template <typename Object>
    Signal<Args...>::Slot::Slot(const Object* instance, void(Object::*method)(Args...) const) :
        Slot()
    {
        reset(instance, method);
    }

    template <typename... Args>
    template <typename Object>
    Signal<Args...>::Slot::Slot(const Object& instance, void(Object::*method)(Args...) const) :
        Slot()
    {
        reset(instance, method);
    }

    template <typename... Args>
    Signal<Args...>::Slot::~Slot()
    {
        for(Signal<Args...>* signal : m_signals)
        {
            signal->unbind(m_id);
        }
    }

    template <typename... Args>
    void Signal<Args...>::Slot::reset(const Function& function)
    {
        if(m_id == 0)
        {
            Lock lock(s_idMutex);
            s_nextId++;

            m_id = s_nextId;
        }

        m_function = function;
    }

    template <typename... Args>
    template <typename Object>
    void Signal<Args...>::Slot::reset(Object* instance, void(Object::*method)(Args...))
    {
        reset([instance, method](Args... args){
            (instance->*method)(args...);
        });
    }

    template <typename... Args>
    template <typename Object>
    void Signal<Args...>::Slot::reset(Object& instance, void(Object::*method)(Args...))
    {
        reset([instance, method](Args... args){
            (instance.*method)(args...);
        });
    }

    template <typename... Args>
    template <typename Object>
    void Signal<Args...>::Slot::reset(const Object* instance, void(Object::*method)(Args...) const)
    {
        reset([instance, method](Args... args){
            (instance.*method)(args...);
        });
    }

    template <typename... Args>
    template <typename Object>
    void Signal<Args...>::Slot::reset(const Object& instance, void(Object::*method)(Args...) const)
    {
        reset([instance, method](Args... args){
            (instance.*method)(args...);
        });
    }

    template <typename... Args>
    void Signal<Args...>::Slot::call(Args... args) const
    {
        m_function(std::forward<Args>(args)...);
    }

    template <typename... Args>
    Uint64 Signal<Args...>::Slot::getId() const
    {
        return m_id;
    }

    template <typename... Args>
    void Signal<Args...>::Slot::addSignal(Signal<Args...>* signal)
    {
        m_signals.push_back(signal);
    }
}