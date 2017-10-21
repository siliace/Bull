#ifndef BULL_CORE_FILESYSTEM_TEMPDIRECTORY_HPP
#define BULL_CORE_FILESYSTEM_TEMPDIRECTORY_HPP

#include <Bull/Core/Export.hpp>
#include <Bull/Core/FileSystem/Directory.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/FileSystem/FileSystem.hpp>
#include <Bull/Core/Pattern/ObjectRef.hpp>

namespace Bull
{
    class TempDirectory;

    using TempDirectoryRef = ObjectRef<TempDirectory>;
    using TempDirectoryConstRef = ObjectRef<const TempDirectory>;

    struct BULL_CORE_API TempDirectory : public Directory
    {
        /*! \brief Make a Directory
         *
         * \param args Arguments to use to construct the Directory
         *
         * \return The created Directory
         *
         */
        template <typename... Args>
        static TempDirectoryRef make(Args&&... args);

        /*! \brief Constructor
         *
         * \param name The name of TempDirectory
         *
         */
        explicit TempDirectory(const String& name = "BullTempDirectory", const Path& path = FileSystem::getTempPath());

        /*! \brief Destructor
         *
         */
        ~TempDirectory();

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
        TempDirectoryRef createDirectory(const String& name);
    };
}

#include <Bull/Core/FileSystem/TempDirectory.inl>

#endif // BULL_CORE_FILESYSTEM_TEMPDIRECTORY_HPP
