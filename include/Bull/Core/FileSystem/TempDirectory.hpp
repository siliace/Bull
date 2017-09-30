#ifndef BULL_CORE_FILESYSTEM_TEMPDIRECTORY_HPP
#define BULL_CORE_FILESYSTEM_TEMPDIRECTORY_HPP

#include <Bull/Core/Export.hpp>
#include <Bull/Core/FileSystem/Directory.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/FileSystem/FileSystem.hpp>

namespace Bull
{
    struct BULL_CORE_API TempDirectory : public Directory
    {
        /*! \brief Constructor
         *
         * \param name The name of TempDirectory
         *
         */
        explicit TempDirectory(const String& name = "BullTempDirectory", const Path& path = FileSystem::getTempPath());

        /*! \brief Create a File in the temporary directory
         *
         * \param name The name of the file to create
         *
         * \return The created file
         *
         */
        FileRef createFile(const String& name);

        /*! \brief Create a File in the temporary directory
         *
         * \param name The name of the file to create
         *
         * \return The created file
         *
         */
        DirectoryRef createDirectory(const String& name);
    };
}

#endif // BULL_CORE_FILESYSTEM_TEMPDIRECTORY_HPP
