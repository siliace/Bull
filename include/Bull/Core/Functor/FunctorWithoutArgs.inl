namespace Bull
{
    namespace prv
    {
        /*! \brief Constructor
         *
         * \param function The method to call
         *
         */
        template<typename Function, typename Return>
        FunctorWithoutArgs<Function, Return>::FunctorWithoutArgs(Function function) :
            m_function(function)
        {
            /// Nothing
        }

        /*! \brief Call the stored function
         *
         * \return Return what the called function returned
         *
         */
        template<typename Function, typename Return>
        Return FunctorWithoutArgs<Function, Return>::run()
        {
            if(!std::is_same<Return, void>::value)
            {
                return m_function();
            }

            m_function();
        }
    }
}
