#ifndef BULL_CORE_FILESYSTEM_DIRECTORYIMPLWIN32_HPP
#define BULL_CORE_FILESYSTEM_DIRECTORYIMPLWIN32_HPP

#include <Bull/Core/FileSystem/DirectoryImpl.hpp>
#include <Bull/Core/Support/Win32/Windows.hpp>
#include <Bull/Core/Time/Date.hpp>

namespace Bull
{
    namespace prv
    {
        class DirectoryImplWin32 : public DirectoryImpl
        {
        public:

            /*! \brief Create a directory
             *
             * \param name The name of the directory to create
             *
             * \return Return true if the file was created successfully, else otherwise
             *
             */
            static bool create(const String& name);

            /*! \brief Check if a directory exists
             *
             * \param name The name of the directory to check
             *
             * \return Return true if the directory exists, false otherwise
             *
             */
            static bool exists(const String& name);

            /*! \brief Delete a directory
             *
             * \param name The name of the directory to delete
             *
             * \return Return true if the directory was deleted successfully, false otherwise
             *
             */
            static bool remove(const Path& name);

        public:

            /*! \brief Constructor
             *
             * \param path The path of the directory to open
             *
             */
            explicit DirectoryImplWin32(const String& path);

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

            String          m_path;
            WIN32_FIND_DATA m_result;
            HANDLE          m_handler;
        };
    }
}

#endif // BULL_CORE_FILESYSTEM_DIRECTORYIMPLWIN32_HPP


