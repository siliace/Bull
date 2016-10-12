namespace Bull
{
    namespace prv
    {
        /*! \brief Constructor
         *
         * \param instance The instance to use to call the method
         * \param method   The method to call
         * \param args     Arguments of the method
         *
         */
        template<typename Return, typename Instance, typename Class, typename... Args>
        FunctorMethodConstWithArgs<Return, Instance, Class, Args...>::FunctorMethodConstWithArgs(const Instance& instance, Return(Class::*method)(Args...) const, Args... args) :
            m_instance(instance),
            m_method(method),
            m_args(args...)
        {
            /// Nothing
        }

        /*! \brief Call the stored function
         *
         * \return Return what the called function returned
         *
         */
        template<typename Return, typename Instance, typename Class, typename... Args>
        Return FunctorMethodConstWithArgs<Return, Instance, Class, Args...>::run()
        {
            if(!std::is_same<Return, void>::value)
            {
                return AbstractFunctor<Return>::apply(m_instance, m_method, m_args);
            }

            AbstractFunctor<Return>::apply(m_instance, m_method, m_args);
        }
    }
}
