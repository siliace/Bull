#ifndef BULL_CORE_FILESYSTEM_UNIX_PATHIMPL_HPP
#define BULL_CORE_FILESYSTEM_UNIX_PATHIMPL_HPP

#include <string>

namespace Bull
{
    namespace prv
    {
        class PathImpl
        {
        public:

            /** \brief Get the absolute path for a given relative path
             *
             * \param relative The relative path
             *
             * \return The absolute path
             *
             */
            static std::string realPath(const std::string& relative);
        };
    }
}

#endif // BULL_CORE_FILESYSTEM_UNIX_PATHIMPL_HPP
