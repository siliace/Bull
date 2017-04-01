#ifndef Bull_FunctorMethodWithoutArgs_hpp
#define Bull_FunctorMethodWithoutArgs_hpp

#include <Bull/Core/Functor/AbstractFunctor.hpp>

namespace Bull
{
    namespace prv
    {
        template<typename Instance, typename Class, typename Return>
        class FunctorMethodWithoutArgs : public AbstractFunctor<Return>
        {
        public:

            /*! @brief Default constructor
             *
             */
            FunctorMethodWithoutArgs() = delete;

            /*! @brief Constructor
             *
             * @param instance The instance to use to call the method
             * @param method   The method to call
             *
             */
            FunctorMethodWithoutArgs(Instance& instance, Return(Class::*method)());

            /*! @brief Call the stored function
             *
             * @return Return what the called function returned
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

#endif // Bull_FunctorMethodWithoutArgs_hpp


