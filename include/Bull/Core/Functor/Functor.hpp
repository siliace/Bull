#ifndef Bull_Functor_hpp
#define Bull_Functor_hpp

#include <memory>

#include <Bull/Core/Functor/FunctorMethodConstWithArgs.hpp>
#include <Bull/Core/Functor/FunctorMethodConstWithoutArgs.hpp>
#include <Bull/Core/Functor/FunctorMethodConstWithArgs.hpp>
#include <Bull/Core/Functor/FunctorMethodWithArgs.hpp>
#include <Bull/Core/Functor/FunctorMethodWithoutArgs.hpp>
#include <Bull/Core/Functor/FunctorWithArgs.hpp>
#include <Bull/Core/Functor/FunctorWithoutArgs.hpp>

namespace Bull
{
    template<typename Return = void>
    class BULL_API Functor
    {
    public:

        /*! \brief Default constructor
         *
         */
        Functor();

        /*! \brief Constructor
         *
         * \param function The function to store
         *
         */
        template<typename Function>
        Functor(Function function);

        /*! \brief Constructor
         *
         * \param function The function to store
         * \param args     The arguments of the function
         *
         */
        template<typename Function, typename... Args>
        Functor(Function function, Args... args);

        /*! \brief Constructor
         *
         * \param instance The instance to store
         * \param function The method of the instance to store
         *
         */
        template<typename Instance, typename Class>
        Functor(Instance& instance, Return(Class::*member)());

        /*! \brief Constructor
         *
         * \param instance The instance to store
         * \param function The method of the instance to store
         *
         */
        template<typename Instance, typename Class>
        Functor(const Instance& instance, Return(Class::*member)() const);

        /*! \brief Constructor
         *
         * \param instance The instance to store
         * \param function The method of the instance to store
         * \param args     Arguments of the method
         *
         */
        template<typename Instance, typename Class, typename... Args>
        Functor(Instance& instance, Return(Class::*member)(Args...), Args... args);


        /*! \brief Constructor
         *
         * \param instance The instance to store
         * \param function The method of the instance to store
         * \param args     Arguments of the method
         *
         */
        template<typename Instance, typename Class, typename... Args>
        Functor(const Instance& instance, Return(Class::*member)(Args...) const, Args... args);

        /*! \brief Destructor
         *
         */
        ~Functor();

        /*! \brief Call the stored function
         *
         * \return Return what the called function returned
         *
         */
        Return run() const;

        /*! \brief () operator override
         *
         * \return Return what the called function returned
         *
         */
        Return operator()() const;

    private:

        std::shared_ptr<prv::AbstractFunctor<Return>> m_impl; /*!< The pointer to the implementation */
    };
}

#include <Bull/Core/Functor/Functor.inl>

#endif // Bull_Functor_hpp
