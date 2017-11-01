namespace Bull
{
    namespace prv
    {
        template<typename Return>
        template<typename Function, typename Tuple>
        Return AbstractFunctor<Return>::apply(Function&& function, Tuple&& params)
        {
            constexpr std::size_t size = std::tuple_size<typename std::remove_reference<Tuple>::type>::value;

            if(!std::is_same<Return, void>::value)
            {
                return AbstractFunctor<Return>::applyImplFunction(std::forward<Function>(function), std::forward<Tuple>(params), std::make_index_sequence<size>());
            }

            AbstractFunctor<Return>::applyImplFunction(std::forward<Function>(function), std::forward<Tuple>(params), std::make_index_sequence<size>());
        }

        template<typename Return>
        template<typename Instance, typename Method, typename Tuple>
        Return AbstractFunctor<Return>::apply(Instance& instance, Method&& method, Tuple&& params)
        {
            constexpr std::size_t size = std::tuple_size<typename std::remove_reference<Tuple>::type>::value;

            if(!std::is_same<Return, void>::value)
            {
                return AbstractFunctor<Return>::applyImplMethod(instance, std::forward<Method>(method), std::forward<Tuple>(params), std::make_index_sequence<size>());
            }

            AbstractFunctor<Return>::applyImplMethod(instance, std::forward<Method>(method), std::forward<Tuple>(params), std::make_index_sequence<size>());
        }

        template<typename Return>
        template<typename Function, typename Tuple, size_t... Size>
        Return AbstractFunctor<Return>::applyImplFunction(Function&& function, Tuple&& params, std::index_sequence<Size...>)
        {
            if(!std::is_same<Return, void>::value)
            {
                return std::forward<Function>(function)(std::get<Size>(std::forward<Tuple>(params))...);
            }

            std::forward<Function>(function)(std::get<Size>(std::forward<Tuple>(params))...);
        }

        template<typename Return>
        template<typename Instance, typename Method, typename Tuple, std::size_t... Size>
        Return AbstractFunctor<Return>::applyImplMethod(Instance& instance, Method&& method, Tuple&& params, std::index_sequence<Size...>)
        {
            if(!std::is_same<Return, void>::value)
            {
                return (instance .* std::forward<Method>(method))(std::get<Size>(std::forward<Tuple>(params))...);
            }

            (instance .* std::forward<Method>(method))(std::get<Size>(std::forward<Tuple>(params))...);
        }

        template<typename Return>
        AbstractFunctor<Return>::~AbstractFunctor()
        {
            /// Nothing
        }
    }
}
