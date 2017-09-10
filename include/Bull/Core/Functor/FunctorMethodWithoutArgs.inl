namespace Bull
{
    namespace prv
    {
        template<typename Instance, typename Class, typename Return>
        FunctorMethodWithoutArgs<Instance, Class, Return>::FunctorMethodWithoutArgs(Instance& instance, Return(Class::*method)()) :
            m_instance(instance),
            m_method(method)
        {
            /// Nothing
        }

        template<typename Instance, typename Class, typename Return>
        Return FunctorMethodWithoutArgs<Instance, Class, Return>::run()
        {
            if(!std::is_same<Return, void>::value)
            {
                return (m_instance.*m_method)();
            }

            (m_instance.*m_method)();
        }
    }
}
