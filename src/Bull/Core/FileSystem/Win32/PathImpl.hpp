#ifndef BULL_CORE_FILESYSTEM_PATHIMPL_HPP
#define BULL_CORE_FILESYSTEM_PATHIMPL_HPP

#include <Bull/Core/FileSystem/Path.hpp>

namespace Bull
{
    namespace prv
    {
        class PathImpl
        {
        public:

            /**
             * \brief
             * \param path
             * \param newPath
             * \param failsIfExists
             */
            static void copy(const Path& path, const Path& newPath, bool failsIfExists);

            /**
             * \brief
             * \param path
             * \param newPath
             */
            static void rename(const Path& path, const Path& newPath);

            /**
             * \brief Get the absolute path for a given relative path
             * \param relative The relative path
             * \return The absolute path
             */
            static std::string realPath(const std::string& relative);
        };
    }
}

#endif // BULL_CORE_FILESYSTEM_PATHIMPL_HPP
