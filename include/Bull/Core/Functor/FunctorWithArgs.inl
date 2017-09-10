namespace Bull
{
    namespace prv
    {
        template<typename Return, typename Function, typename... Args>
        FunctorWithArgs<Return, Function, Args...>::FunctorWithArgs(Function function, Args... args) :
            m_function(function),
            m_args(args...)
        {
            /// Nothing
        }

        template<typename Return, typename Function, typename... Args>
        Return FunctorWithArgs<Return, Function, Args...>::run()
        {
            if(!std::is_same<Return, void>::value)
            {
                return AbstractFunctor<Return>::apply(m_function, m_args);
            }

            AbstractFunctor<Return>::apply(m_function, m_args);
        }
    }
}
