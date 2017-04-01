#ifndef Bull_FunctorMethodWithArgs_hpp
#define Bull_FunctorMethodWithArgs_hpp

#include <tuple>

#include <Bull/Core/Functor/AbstractFunctor.hpp>

namespace Bull
{
    namespace prv
    {
        template<typename Return, typename Instance, typename Class, typename... Args>
        class FunctorMethodWithArgs : public AbstractFunctor<Return>
        {
        public:

            /*! @brief Default constructor
             *
             */
            FunctorMethodWithArgs() = delete;

            /*! @brief Constructor
             *
             * @param instance The instance to use to call the method
             * @param method   The method to call
             * @param args     Arguments of the method
             *
             */
            FunctorMethodWithArgs(Instance& instance, Return(Class::*method)(Args...), Args... args);

            /*! @brief Call the stored function
             *
             * @return Return what the called function returned
             *
             */
            Return run();

        private:

            Instance& m_instance;
            Return(Class::*m_method)(Args...);

            std::tuple<Args...> m_args;
        };
    }
}

#include <Bull/Core/Functor/FunctorMethodWithArgs.inl>

#endif // Bull_FunctorMethodWithArgs_hpp


