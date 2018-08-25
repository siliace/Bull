#ifndef BULL_CORE_FILESYSTEM_DIRECTORYIMPLWIN32_HPP
#define BULL_CORE_FILESYSTEM_DIRECTORYIMPLWIN32_HPP

#include <Bull/Core/FileSystem/DirectoryImpl.hpp>
#include <Bull/Core/Support/Win32/Windows.hpp>

namespace Bull
{
    namespace prv
    {
        class DirectoryImplWin32 : public DirectoryImpl
        {
        public:

            /*! \brief Create a Directory
             *
             * \param path The path of the directory to create
             *
             */
            static void create(const Path& path);

            /*! \brief Tell whether a Directory exists
             *
             * \param path The path of the Directory to check
             *
             * \return True if the directory exists
             *
             */
            static bool exists(const Path& path);

            /*! \brief Rename a Directory
             *
             * \param path    The Path of the Directory to rename
             * \param newPath The new Path of the Directory
             *
             */
            static void rename(const Path& path, const Path& newPath);

            /*! \brief Remove a Directory
             *
             * \param path The path of the Directory to remove
             *
             */
            static void remove(const Path& path);

        public:

            /*! \brief Constructor
             *
             * \param path The path of the directory to open
             *
             */
            explicit DirectoryImplWin32(const Path& path);

            /*! \brief Destructor
             *
             */
            ~DirectoryImplWin32();

            /*! \brief Get the content of this Directory
             *
             * \param flags What we have to look for
             *
             * \return Return the list of content entity
             *
             */
            std::vector<Path> getContent(Uint32 flags) override;

        private:

            Path            m_path;
            WIN32_FIND_DATA m_result;
            HANDLE          m_handler;
        };
    }
}

#endif // BULL_CORE_FILESYSTEM_DIRECTORYIMPLWIN32_HPP


