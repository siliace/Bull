#ifndef BULL_CORE_FUNCTORWITHOUT_HPP
#define BULL_CORE_FUNCTORWITHOUT_HPP

#include <Bull/Core/Functor/AbstractFunctor.hpp>

namespace Bull
{
    namespace prv
    {
        template<typename Function, typename Return>
        class FunctorWithoutArgs : public AbstractFunctor<Return>
        {
        public:

            /*! \brief Constructor
             *
             * \param function The method to call
             *
             */
            FunctorWithoutArgs(Function function);

            /*! \brief Call the stored function
             *
             * \return Return what the called function returned
             *
             */
            Return run();

        private:

            Function m_function;
        };
    }
}

#include <Bull/Core/Functor/FunctorWithoutArgs.inl>

#endif // BULL_CORE_FUNCTORWITHOUT_HPP

