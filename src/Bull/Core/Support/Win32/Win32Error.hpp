#ifndef BULL_CORE_SUPPORT_WIN32ERROR_HPP
#define BULL_CORE_SUPPORT_WIN32ERROR_HPP

#include <Bull/Core/Exception/InternalError.hpp>

namespace Bull
{
    namespace prv
    {
        class Win32Error : public Exception
        {
        public:

            /** \brief Constructor
             *
             * \param file        The name file where the Exception was thrown
             * \param line        The line where the Exception was thrown
             * \param type        The type of Exception thrown
             * \param source      The method where the Exception was thrown
             * \param description The message describing the Exception
             *
             */
            Win32Error(const std::string& file, Uint64 line, const std::string& source, const std::string& description);

        private:

            /** \brief Create the description of the Win32Error
             *
             * \return The description
             *
             */
            std::string createDescription() const;
        };
    }
}

#endif // BULL_CORE_SUPPORT_WIN32ERROR_HPP
