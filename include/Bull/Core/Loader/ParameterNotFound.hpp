#ifndef BULL_CORE_LOADER_PARAMETERNOTFOUND_HPP
#define BULL_CORE_LOADER_PARAMETERNOTFOUND_HPP

#include <Bull/Core/Exception/RuntimeError.hpp>

namespace Bull
{
    class BULL_CORE_API ParameterNotFound : public RuntimeError
    {
    public:

        /*! \brief Constructor
         *
         * \param name
         *
         */
        ParameterNotFound(const String& name);

        /*! \brief Get the name of the parameter not found
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
        virtual String getLogMessage() const override;

    private:

        String m_name; /*!< The name of the parameter not found */
    };
}

#endif // BULL_CORE_LOADER_PARAMETERNOTFOUND_HPP
