namespace Bull
{
    template<typename Function>
    Thread::Thread(Function function) :
        m_impl(nullptr),
        m_function(function),
        m_priority(Priority::Inherit)
    {
        /// Nothing
    }

    template<typename Function, typename... Args>
    Thread::Thread(Function function, Args... args) :
        m_impl(nullptr),
        m_function(function, args...),
        m_priority(Priority::Inherit)
    {
        /// Nothing
    }

     template<typename Instance, typename Class>
    Thread::Thread(Instance& instance, void(Class::*member)()) :
        m_impl(nullptr),
        m_function(instance, member),
        m_priority(Priority::Inherit)
    {
        /// Nothing
    }

    template<typename Instance, typename Class>
    Thread::Thread(const Instance& instance, void(Class::*member)() const) :
        m_impl(nullptr),
        m_function(instance, member),
        m_priority(Priority::Inherit)
    {
        /// Nothing
    }

    template<typename Instance, typename Class, typename... Args>
    Thread::Thread(Instance& instance, void(Class::*member)(Args...), Args... args) :
        m_impl(nullptr),
        m_function(instance, member, args...),
        m_priority(Priority::Inherit)
    {
        /// Nothing
    }

    template<typename Instance, typename Class, typename... Args>
    Thread::Thread(const Instance& instance, void(Class::*member)(Args...) const, Args... args) :
        m_impl(nullptr),
        m_function(instance, member, args...),
        m_priority(Priority::Inherit)
    {
        /// Nothing
    }
}
