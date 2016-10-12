#ifndef Bull_LocalImpl_hpp
#define Bull_LocalImpl_hpp

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Thread/LocalHandler.hpp>

namespace Bull
{
    namespace prv
    {
        class LocalImpl : public NonCopyable
        {
        public:

            /*! \brief Create a OS specific instance of LocalImpl
             *
             * \return Return the created instance
             *
             */
            static LocalImpl* createInstance();

        public:

            /*! \brief Destructor
             *
             */
            virtual ~LocalImpl();

            /*! \brief Set the value
             *
             * \param value The new value of the variable
             *
             */
            virtual void set(void* value) = 0;

            /*! \brief Get the value
             *
             * \return Return the value of the variable
             *
             */
            virtual void* get() const = 0;

            /*! \brief Get the system native handler
             *
             * \return Return the system native handler
             *
             */
            virtual LocalHandler getSystemHandler() const = 0;

        protected:

            /*! \brief Default constructor
             *
             */
            LocalImpl() = default;
        };
    }
}

#endif // Bull_LocalImpl_hpp
