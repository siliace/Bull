#ifndef Bull_FunctorWithoutArgs_hpp
#define Bull_FunctorWithoutArgs_hpp

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

#endif // Bull_FunctorWithoutArgs_hpp

