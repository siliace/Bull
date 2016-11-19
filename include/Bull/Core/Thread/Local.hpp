#ifndef Bull_Local_hpp
#define Bull_Local_hpp

#include <memory>

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Thread/LocalHandler.hpp>

namespace Bull
{
    namespace prv
    {
        class LocalImpl;
    }

    class BULL_API Local : public NonCopyable
    {
    public:

        /*! \brief Default destructor
         *
         */
        Local() = delete;

        /*! \brief Constructor
         *
         * \param value The value to initialize the variable
         *
         */
        Local(void* value = nullptr);

        /*! \brief Destructor
         *
         */
        virtual ~Local();

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

        std::unique_ptr<prv::LocalImpl> m_impl;
    };
}

#endif // Bull_Local_hpp
