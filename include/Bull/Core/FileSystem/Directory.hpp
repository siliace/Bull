#ifndef BULL_CORE_FILESYSTEM_DIRECTORY_HPP
#define BULL_CORE_FILESYSTEM_DIRECTORY_HPP

#include <memory>
#include <vector>

#include <Bull/Core/FileSystem/DirectorySearchFlag.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

namespace Bull
{
    class Path;

    namespace prv
    {
        class DirectoryImpl;
    }

    class BULL_CORE_API Directory : public NonCopyable
    {
    public:

        /*! \brief Create a Directory
         *
         * \param path The Path of the Directory to create
         *
         * \return True if the file was created successfully
         *
         */
        static bool create(const String& path);

        /*! \brief Check if a Directory exists
         *
         * \param path The Path of the Directory to check
         *
         * \return True if the Directory exists
         *
         */
        static bool exists(const String& path);

        /*! \brief Copy a Directory
         *
         * \param path    The Path of the directory to copy
         * \param newPath The Path of the copied directory
         *
         * \return True if the copy was successfully
         *
         */
        static bool copy(const Path& path, const String& newPath);

        /*! \brief Rename a Directory
         *
         * \param path    The Path of the Directory to rename
         * \param newPath The new Path of the Directory
         *
         * \return True if the directory was renamed successfully
         *
         */
        static bool rename(const Path& path, const String& newPath);

        /*! \brief Delete a Directory
         *
         * \param path The Path of the directory to delete
         *
         * \return True if the Directory was deleted successfully
         *
         */
        static bool remove(const Path& path);

    public:

        /*! \brief Constructor by movement
         *
         * \param directory The Directory to move
         *
         */
        Directory(Directory&& directory) noexcept = default;

        /*! \brief Basic assignment operator by movement
         *
         * \param directory The Directory to move
         *
         * \return This
         *
         */
        Directory& operator=(Directory&& directory) noexcept = default;

        /*! \brief Get the content of this Directory
         *
         * \param flags What we have to look for
         *
         * \return Return the list of content entity
         *
         */
        std::vector<Path> getContent(Uint32 flags = DirectorySearchFlag_All);

        /*! \brief Get the path of the directory
         *
         * \return The path of the directory
         *
         */
        const String& getPath() const;

    private:

        friend class Path;

        /*! \brief Constructor
         *
         * \param path The path of the directory
         *
         */
        explicit Directory(const String& path);

    private:

        String                              m_path;
        std::unique_ptr<prv::DirectoryImpl> m_impl;
    };
}

#endif // BULL_CORE_FILESYSTEM_DIRECTORY_HPP
