#ifndef BULL_CORE_FILESYSTEM_FILESYSTEM_HPP
#define BULL_CORE_FILESYSTEM_FILESYSTEM_HPP

#include <Bull/Core/Export.hpp>
#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/FileSystem/FileSystemInfo.hpp>

namespace Bull
{
    struct BULL_CORE_API FileSystem
    {
        /*! \brief Get the root path of the filesystem
         *
         * \return The root
         *
         */
        static Path getRoot();

        /*! \brief Set the current directory of the process
         *
         * \param path The new path of the process
         *
         * \return True if the path was changed successfully
         *
         */
        static bool setCurrentDirectory(const Path& path);

        /*! \brief Get the current directory of the process
         *
         * \return The directory of the process
         *
         */
        static Path getCurrentDirectory();

        /*! \brief Get information about the file system
         *
         * \param base The base path
         *
         * \return Information about the file system
         *
         */
        static FileSystemInfo getFileSystemInfo(const Path& base = getRoot());

        /*! \brief Create a link on the file system
         *
         * \param target The target of the link
         * \param link   The path of the link to create
         * \param force  True to force the creation
         *
         * \return True if the link was created successfully
         *
         */
        static bool createLink(const Path& target, const String& link, bool force = false);
    };
}

#endif // BULL_CORE_FILESYSTEM_FILESYSTEM_HPP
