#ifndef BULL_CORE_FILESYSTEM_PATHIMPL_HPP
#define BULL_CORE_FILESYSTEM_PATHIMPL_HPP

#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    namespace prv
    {
        class PathImpl
        {
        public:

            /*! \brief Get the absolute path for a given relative path
             *
             * \param relative The relative path
             *
             * \return The absolute path
             *
             */
            static String realPath(const String& relative);
        };
    }
}

#endif // BULL_CORE_FILESYSTEM_PATHIMPL_HPP
