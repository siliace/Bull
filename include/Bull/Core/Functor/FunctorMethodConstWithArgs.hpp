#ifndef Bull_FunctorMethodConstWithArgs_hpp
#define Bull_FunctorMethodConstWithArgs_hpp

#include <tuple>

#include <Bull/Core/Functor/AbstractFunctor.hpp>

namespace Bull
{
    namespace prv
    {
        template<typename Return, typename Instance, typename Class, typename... Args>
        class FunctorMethodConstWithArgs : public AbstractFunctor<Return>
        {
        public:

            /*! \brief Default constructor
             *
             */
            FunctorMethodConstWithArgs() = delete;

            /*! \brief Constructor
             *
             * \param instance The instance to use to call the method
             * \param method   The method to call
             * \param args     Arguments of the method
             *
             */
            FunctorMethodConstWithArgs(const Instance& instance, Return(Class::*method)(Args...) const, Args... args);

            /*! \brief Call the stored function
             *
             * \return Return what the called function returned
             *
             */
            Return run();

        private:

            const Instance& m_instance;
            Return(Class::*m_method)(Args...) const;

            std::tuple<Args...> m_args;
        };
    }
}

#include <Bull/Core/Functor/FunctorMethodConstWithArgs.inl>

#endif // Bull_FunctorMethodConstWithArgs_hpp

