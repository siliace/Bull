#ifndef BULL_CORE_FILESYSTEM_FILESYSTEM_HPP
#define BULL_CORE_FILESYSTEM_FILESYSTEM_HPP

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/FileSystem/FileSystemInfo.hpp>

namespace Bull
{
    struct BULL_CORE_API FileSystem
    {
        /** \brief Get the root path of the filesystem
         *
         * \return The root
         *
         */
        static Path getRoot();

        /** \brief Get the Path of user's home directory
         *
         * \return The home directory
         * 
         */
        static Path getHome();

        /** \brief Get the path of the temporary directory
         *
         * \return The temp path
         *
         */
        static Path getTempPath();

        /** \brief Set the current directory of the process
         *
         * \param path The new path of the process
         *
         */
        static void setCurrentDirectory(const Path& path);

        /** \brief Get the current directory of the process
         *
         * \return The directory of the process
         *
         */
        static Path getCurrentDirectory();

        /** \brief Get information about the file system
         *
         * \param base The base path
         *
         * \return Information about the file system
         *
         */
        static FileSystemInfo getFileSystemInfo(const Path& base = getRoot());

        /** \brief Create a link on the file system
         *
         * \param target The target of the link
         * \param link   The path of the link to create
         *
         */
        static void createLink(const Path& target, const std::string& link);
    };
}

#endif // BULL_CORE_FILESYSTEM_FILESYSTEM_HPP
