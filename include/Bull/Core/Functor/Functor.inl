namespace Bull
{
    template<typename Return>
    template<typename Function>
    Functor<Return>::Functor(Function function) :
        m_impl(std::make_shared<prv::FunctorWithoutArgs<Function, Return>>(function))
    {
        /// Nothing
    }

    template<typename Return>
    template<typename Function, typename... Args>
    Functor<Return>::Functor(Function function, Args... args) :
        m_impl(std::make_shared<prv::FunctorWithArgs<Return, Function, Args...>>(function, args...))
    {
        /// Nothing
    }

    template<typename Return>
    template<typename Instance, typename Class>
    Functor<Return>::Functor(Instance& instance, Return(Class::*member)()) :
        m_impl(std::make_shared<prv::FunctorMethodWithoutArgs<Instance, Class, Return>>(instance, member))
    {
        /// Nothing
    }

    template<typename Return>
    template<typename Instance, typename Class>
    Functor<Return>::Functor(const Instance& instance, Return(Class::*member)() const) :
        m_impl(std::make_shared<prv::FunctorMethodConstWithoutArgs<Instance, Class, Return>>(instance, member))
    {
        /// Nothing
    }

    template<typename Return>
    template<typename Instance, typename Class, typename... Args>
    Functor<Return>::Functor(Instance& instance, Return(Class::*member)(Args...), Args... args) :
        m_impl(std::make_shared<prv::FunctorMethodWithArgs<Return, Instance, Class, Args...>>(instance, member, args...))
    {
        /// Nothing
    }

    template<typename Return>
    template<typename Instance, typename Class, typename... Args>
    Functor<Return>::Functor(const Instance& instance, Return(Class::*member)(Args...) const, Args... args) :
        m_impl(std::make_shared<prv::FunctorMethodConstWithArgs<Return, Instance, Class, Args...>>(instance, member, args...))
    {
        /// Nothing
    }

    template<typename Return>
    Functor<Return>::~Functor()
    {
        m_impl.reset();
    }

    template<typename Return>
    Return Functor<Return>::run() const
    {
        if(!std::is_same<Return, void>::value)
        {
            return m_impl->run();
        }

        m_impl->run();
    }

    template<typename Return>
    Return Functor<Return>::operator()() const
    {
        if(!std::is_void<Return>::value)
        {
            return m_impl->run();
        }

        m_impl->run();
    }
}
