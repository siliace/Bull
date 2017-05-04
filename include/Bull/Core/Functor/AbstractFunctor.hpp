#ifndef BULL_ABSTRACTFUNCTOR_HPP
#define BULL_ABSTRACTFUNCTOR_HPP

#include <utility>

#include <Bull/Core/Pattern/NonCopyable.hpp>

namespace Bull
{
    namespace prv
    {
        template<typename Return>
        class AbstractFunctor : public NonCopyable
        {
        public:

            /*! \brief Call a function using a std::tuple as parameters
             *
             * \param function The function to call
             * \param params   Parameters of the function
             *
             * \return Return what had been returned by the called function
             *
             */
            template<typename Function, typename Tuple>
            static Return apply(Function&& function, Tuple&& params);

            /*! \brief Call a method using a std::tuple as parameters
             *
             * \param instance The instance to use to call the method
             * \param method   The method to call
             * \param params   Parameters of the method
             *
             * \return Return what had been return by the called function
             *
             */
            template<typename Instance, typename Method, typename Tuple>
            static Return apply(Instance& instance, Method&& method, Tuple&& params);

        private:

            /*! \brief Call a function
             *
             */
            template<typename Function, typename Tuple, std::size_t... Size>
            static Return applyImplFunction(Function&& function, Tuple&& params, std::index_sequence<Size...>);

            /*! \brief Call a method
              *
              */
            template<typename Instance, typename Method, typename Tuple, std::size_t... Size>
            static Return applyImplMethod(Instance& instance, Method&& method, Tuple&& params, std::index_sequence<Size...>);

        public:

            /*! \brief Destructor
             *
             */
            virtual ~AbstractFunctor();

            /*! \brief Call the function/method with its parameters
             *
             * \return Return what had been returned by the called function
             *
             */
            virtual Return run() = 0;
        };
    }
}

#include <Bull/Core/Functor/AbstractFunctor.inl>

#endif // BULL_ABSTRACTFUNCTOR_HPP
