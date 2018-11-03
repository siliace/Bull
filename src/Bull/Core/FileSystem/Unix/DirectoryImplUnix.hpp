#ifndef BULL_CORE_FILESYSTEM_DIRECTORYIMPLUNIX_HPP
#define BULL_CORE_FILESYSTEM_DIRECTORYIMPLUNIX_HPP

#include <dirent.h>

#include <Bull/Core/FileSystem/DirectoryImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class DirectoryImplUnix : public DirectoryImpl
        {
        public:

            /*! \brief Create a Directory
             *
             * \param path The Path of the directory to create
             *
             */
            static void create(const Path& path);

            /*! \brief Check if a directory exists
             *
             * \param path The path of the directory to check
             *
             * \return True if the directory exists
             *
             */
            static bool exists(const Path& path);

            /*! \brief Delete a directory
             *
             * \param path The path of the directory to delete
             *
             * \return True if the directory was deleted successfully
             *
             */
            static void remove(const Path& path);

        public:

            /*! \brief Constructor
             *
             * \param path The Path of the Directory
             *
             */
            explicit DirectoryImplUnix(const Path& path);

            /*! \brief Destructor
             *
             */
            ~DirectoryImplUnix();

            /*! \brief Get the content of this Directory
             *
             * \param flags What we have to look for
             *
             * \return Return the list of content entity
             *
             */
            std::vector<Path> getContent(Uint32 flags) override;

        private:

            Path m_path;
            DIR* m_handle;
        };
    }
}

#endif // BULL_CORE_FILESYSTEM_DIRECTORYIMPLUNIX_HPP
