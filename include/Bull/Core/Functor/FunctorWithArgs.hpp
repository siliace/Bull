#ifndef Bull_FunctorWithArgs_hpp
#define Bull_FunctorWithArgs_hpp

#include <tuple>

#include <Bull/Core/Functor/AbstractFunctor.hpp>

namespace Bull
{
    namespace prv
    {
        template<typename Return, typename Function, typename... Args>
        class FunctorWithArgs : public AbstractFunctor<Return>
        {
        public:

            /*! @brief Constructor
             *
             * @param function The method to call
             * @param args     Arguments of the method
             *
             */
            FunctorWithArgs(Function function, Args... args);

            /*! @brief Call the stored function
             *
             * @return Return what the called function returned
             *
             */
            Return run();

        private:

            Function m_function;
            std::tuple<Args...> m_args;
        };
    }
}

#include <Bull/Core/Functor/FunctorWithArgs.inl>

#endif // Bull_FunctorWithoutArgs_hpp


