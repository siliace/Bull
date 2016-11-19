#ifndef Bull_LocalImplUnix_hpp
#define Bull_LocalImplUnix_hpp

#include <Bull/Core/Thread/LocalImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class LocalImplUnix : public LocalImpl
        {
        public:

            /*! \brief Default destructor
             *
             */
            LocalImplUnix();

            /*! \brief Destructor
             *
             */
            ~LocalImplUnix();

            /*! \brief Set the value
             *
             * \param value The new value of the variable
             *
             */
            void set(void* value) override;

            /*! \brief Get the value
             *
             * \return Return the value of the variable
             *
             */
            void* get() const override;

            /*! \brief Get the system native handler
             *
             * \return Return the system native handler
             *
             */
            LocalHandler getSystemHandler() const override;

        private:

            pthread_key_t m_handler;
        };
    }
}

#endif // Bull_LocalImplUnix_hpp
