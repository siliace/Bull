namespace Bull
{
    /*! \brief Default constructor
     *
     */
    template<typename Return>
    Functor<Return>::Functor() :
        m_impl(nullptr)
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param function The function to store
     *
     */
    template<typename Return>
    template<typename Function>
    Functor<Return>::Functor(Function function) :
        m_impl(std::make_shared<prv::FunctorWithoutArgs<Function, Return>>(function))
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param function The function to store
     * \param args The arguments of the function
     *
     */
    template<typename Return>
    template<typename Function, typename... Args>
    Functor<Return>::Functor(Function function, Args... args) :
        m_impl(std::make_shared<prv::FunctorWithArgs<Return, Function, Args...>>(function, args...))
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param instance The instance to store
     * \param function The method of the instance to store
     *
     */
    template<typename Return>
    template<typename Instance, typename Class>
    Functor<Return>::Functor(Instance& instance, Return(Class::*member)()) :
        m_impl(std::make_shared<prv::FunctorMethodWithoutArgs<Instance, Class, Return>>(instance, member))
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param instance The instance to store
     * \param function The method of the instance to store
     *
     */
    template<typename Return>
    template<typename Instance, typename Class>
    Functor<Return>::Functor(const Instance& instance, Return(Class::*member)() const) :
        m_impl(std::make_shared<prv::FunctorMethodConstWithoutArgs<Instance, Class, Return>>(instance, member))
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param instance The instance to store
     * \param function The method of the instance to store
     * \param args     Arguments of the method
     *
     */
    template<typename Return>
    template<typename Instance, typename Class, typename... Args>
    Functor<Return>::Functor(Instance& instance, Return(Class::*member)(Args...), Args... args) :
        m_impl(std::make_shared<prv::FunctorMethodWithArgs<Return, Instance, Class, Args...>>(instance, member, args...))
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param instance The instance to store
     * \param function The method of the instance to store
     * \param args     Arguments of the method
     *
     */
    template<typename Return>
    template<typename Instance, typename Class, typename... Args>
    Functor<Return>::Functor(const Instance& instance, Return(Class::*member)(Args...) const, Args... args) :
        m_impl(std::make_shared<prv::FunctorMethodConstWithArgs<Return, Instance, Class, Args...>>(instance, member, args...))
    {
        /// Nothing
    }

    /*! \brief Destructor
     *
     */
    template<typename Return>
    Functor<Return>::~Functor()
    {
        m_impl.reset();
    }

    /*! \brief Call the stored function
     *
     * \return Return what the called function returned
     *
     */
    template<typename Return>
    Return Functor<Return>::run() const
    {
        if(!std::is_same<Return, void>::value)
        {
            return m_impl->run();
        }

        m_impl->run();
    }

    /*! \brief () operator override
     *
     * \return Return what the called function returned
     *
     */
    template<typename Return>
    Return Functor<Return>::operator()() const
    {
        if(!std::is_same<Return, void>::value)
        {
            return m_impl->run();
        }

        m_impl->run();
    }
}
