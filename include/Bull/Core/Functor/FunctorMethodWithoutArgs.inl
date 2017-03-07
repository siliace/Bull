namespace Bull
{
    namespace prv
    {
        /*! \brief Constructor
         *
         * \param instance The instance to use to call the method
         * \param method   The method to call
         *
         */
        template<typename Instance, typename Class, typename Return>
        FunctorMethodWithoutArgs<Instance, Class, Return>::FunctorMethodWithoutArgs(Instance& instance, Return(Class::*method)()) :
            m_instance(instance),
            m_method(method)
        {
            /// Nothing
        }

        /*! \brief Call the stored function
         *
         * \return Return what the called function returned
         *
         */
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
