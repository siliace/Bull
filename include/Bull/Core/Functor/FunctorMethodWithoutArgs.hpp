#ifndef BULL_CORE_FUNCTORMETHODTWITHOUT_HPP
#define BULL_CORE_FUNCTORMETHODTWITHOUT_HPP

#include <Bull/Core/Functor/AbstractFunctor.hpp>

namespace Bull
{
    namespace prv
    {
        template<typename Instance, typename Class, typename Return>
        class FunctorMethodWithoutArgs : public AbstractFunctor<Return>
        {
        public:

            /*! \brief Constructor
             *
             * \param instance The instance to use to call the method
             * \param method   The method to call
             *
             */
            FunctorMethodWithoutArgs(Instance& instance, Return(Class::*method)());

            /*! \brief Call the stored function
             *
             * \return Return what the called function returned
             *
             */
            Return run();

        private:

            Instance& m_instance;
            Return(Class::*m_method)();
        };
    }
}

#include <Bull/Core/Functor/FunctorMethodWithoutArgs.inl>

#endif // BULL_CORE_FUNCTORMETHODTWITHOUT_HPP


