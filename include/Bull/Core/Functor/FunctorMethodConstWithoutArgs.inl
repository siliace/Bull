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
        FunctorMethodConstWithoutArgs<Instance, Class, Return>::FunctorMethodConstWithoutArgs(const Instance& instance, Return(Class::*method)() const) :
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
