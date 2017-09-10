namespace Bull
{
    namespace prv
    {
        template<typename Function, typename Return>
        FunctorWithoutArgs<Function, Return>::FunctorWithoutArgs(Function function) :
            m_function(function)
        {
            /// Nothing
        }

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
