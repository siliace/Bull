namespace Bull
{
    namespace prv
    {
        template<typename Return, typename Instance, typename Class, typename... Args>
        FunctorMethodWithArgs<Return, Instance, Class, Args...>::FunctorMethodWithArgs(Instance& instance, Return(Class::*method)(Args...), Args... args) :
            m_instance(instance),
            m_method(method),
            m_args(args...)
        {
            /// Nothing
        }

        template<typename Return, typename Instance, typename Class, typename... Args>
        Return FunctorMethodWithArgs<Return, Instance, Class, Args...>::run()
        {
            if(!std::is_same<Return, void>::value)
            {
                return AbstractFunctor<Return>::apply(m_instance, m_method, m_args);
            }

            AbstractFunctor<Return>::apply(m_instance, m_method, m_args);
        }
    }
}
