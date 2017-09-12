#ifndef BULL_CORE_LOADER_FAILEDTOLOAD_HPP
#define BULL_CORE_LOADER_FAILEDTOLOAD_HPP

#include <Bull/Core/Exception/RuntimeError.hpp>

namespace Bull
{
    template <typename T>
    class BULL_CORE_API FailedToLoad : public RuntimeError
    {
    public:

        /*! \brief Constructor
         *
         * \param name     The name of the resource failed to load
         * \param resource The resource failed to load
         *
         */
        FailedToLoad(const String& name, const T& resource);

        /*! \brief Get the resource failed to load
         *
         * \return The resource
         *
         */
        const T& getResource() const;

        /*! \brief Get the name of the resource failed to load
         *
         * \return The name
         *
         */
        const String& getName() const;

    protected:

        /*! \brief Get the log message
         *
         * \return The log message
         *
         */
        String getLogMessage() const override;

    private:

        String   m_name;     /*!< The name of the resource failed to load*/
        const T& m_resource; /*!< The resource failed to load*/
    };
}

#include <Bull/Core/Loader/FailedToLoad.inl>

#endif // BULL_CORE_LOADER_FAILEDTOLOAD_HPP
