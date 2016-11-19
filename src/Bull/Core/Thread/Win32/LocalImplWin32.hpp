#ifndef Bull_LocalImplWin32_hpp
#define Bull_LocalImplWin32_hpp

#include <windows.h>

#include <Bull/Core/Thread/LocalImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class LocalImplWin32 : public LocalImpl
        {
        public:

            /*! \brief Default destructor
             *
             */
            LocalImplWin32();

            /*! \brief Destructor
             *
             */
            ~LocalImplWin32();

            /*! \brief Set the value
             *
             * \param value The new value of the variable
             *
             */
            void set(void* value);

            /*! \brief Get the value
             *
             * \return Return the value of the variable
             *
             */
            void* get() const;

            /*! \brief Get the system native handler
             *
             * \return Return the system native handler
             *
             */
            LocalHandler getSystemHandler() const;

        private:

            DWORD m_id;
        };
    }
}

#endif // Bull_LocalImplWin32_hpp
