#ifndef BULL_CORE_FUNCTOR_FUNCTORMETHODCONSTWITHARGS_HPP
#define BULL_CORE_FUNCTOR_FUNCTORMETHODCONSTWITHARGS_HPP

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

#endif // BULL_CORE_FUNCTOR_FUNCTORMETHODCONSTWITHARGS_HPP

