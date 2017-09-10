namespace Bull
{
    namespace prv
    {
        template<typename Instance, typename Class, typename Return>
        FunctorMethodConstWithoutArgs<Instance, Class, Return>::FunctorMethodConstWithoutArgs(const Instance& instance, Return(Class::*method)() const) :
            m_instance(instance),
            m_method(method)
        {
            /// Nothing
        }

        template<typename Instance, typename Class, typename Return>
        Return FunctorMethodConstWithoutArgs<Instance, Class, Return>::run()
        {
            if(!std::is_same<Return, void>::value)
            {
                return (m_instance.*m_method)();
            }

            (m_instance.*m_method)();
        }
    }
}
