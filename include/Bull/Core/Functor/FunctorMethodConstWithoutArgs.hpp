#ifndef Bull_FunctorMethodConstWithoutArgs_hpp
#define Bull_FunctorMethodConstWithoutArgs_hpp

#include <Bull/Core/Functor/AbstractFunctor.hpp>

namespace Bull
{
    namespace prv
    {
        template<typename Instance, typename Class, typename Return>
        class FunctorMethodConstWithoutArgs : public AbstractFunctor<Return>
        {
        public:

            /*! \brief Default constructor
             *
             */
            FunctorMethodConstWithoutArgs() = delete;

            /*! \brief Constructor
             *
             * \param instance The instance to use to call the method
             * \param method   The method to call
             *
             */
            FunctorMethodConstWithoutArgs(const Instance& instance, Return(Class::*method)() const);

            /*! \brief Call the stored function
             *
             * \return Return what the called function returned
             *
             */
            Return run();

        private:

            const Instance& m_instance;
            Return(Class::*m_method)() const;
        };
    }
}

#include <Bull/Core/Functor/FunctorMethodConstWithoutArgs.inl>

#endif // Bull_FunctorMethodConstWithoutArgs_hpp


