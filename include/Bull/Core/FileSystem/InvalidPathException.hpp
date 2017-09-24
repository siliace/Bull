#ifndef BULL_CORE_FILESYSTEM_INVALIDPATHEXCEPTION_HPP
#define BULL_CORE_FILESYSTEM_INVALIDPATHEXCEPTION_HPP

#include <Bull/Core/Exception/RuntimeError.hpp>
#include <Bull/Core/Export.hpp>

namespace Bull
{
    class BULL_CORE_API InvalidPathException : public RuntimeError
    {
    public:

        /*! \brief Constructor
         *
         * \param path The invalid path
         *
         */
        explicit InvalidPathException(const String& path);

        /*! \brief Get the invalid path
         *
         * \return The path
         */
        const String& getPath() const;

    protected:

        /*! \brief Get the log message
         *
         * \return The log message
         *
         */
        String getLogMessage() const override;

    private:

        String m_path;
    };
}

#endif //BULL_INVALIDPATHEXCEPTION_HPP
