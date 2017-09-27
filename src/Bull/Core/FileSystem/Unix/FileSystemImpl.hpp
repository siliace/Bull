#ifndef BULL_CORE_FILESYSTEM_UNIX_FILESYSTEMIMPL_HPP
#define BULL_CORE_FILESYSTEM_UNIX_FILESYSTEMIMPL_HPP

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/FileSystem/FileSystemInfo.hpp>

namespace Bull
{
    namespace prv
    {
        struct FileSystemImpl
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

            /*! \brief Get information about the file system
             *
             * \param base The base path
             *
             * \return Information about the file system
             *
             */
            static FileSystemInfo getFileSystemInfo(const Path& path);

            /*! \brief Create a link on the file system
             *
             * \param target The target of the link
             * \param link   The path of the link to create
             *
             * \return True if the link was created successfully
             *
             */
            static bool createLink(const Path& target, const String& link);
        };
    }
}

#endif // BULL_CORE_FILESYSTEM_UNIX_FILESYSTEMIMPL_HPP
