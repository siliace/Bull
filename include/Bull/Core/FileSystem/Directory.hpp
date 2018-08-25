#ifndef BULL_CORE_FILESYSTEM_DIRECTORY_HPP
#define BULL_CORE_FILESYSTEM_DIRECTORY_HPP

#include <memory>
#include <vector>

#include <Bull/Core/FileSystem/DirectorySearchFlag.hpp>
#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

namespace Bull
{
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
         */
        static void create(const Path& path);

        /*! \brief Check if a Directory exists
         *
         * \param path The Path of the Directory to check
         *
         * \return True if the Directory exists
         *
         */
        static bool exists(const Path& path);

        /*! \brief Copy a Directory
         *
         * \param path    The Path of the directory to copy
         * \param newPath The Path of the copied directory
         *
         */
        static void copy(const Path& path, const Path& newPath);

        /*! \brief Rename a Directory
         *
         * \param path    The Path of the Directory to rename
         * \param newPath The new Path of the Directory
         *
         */
        static void rename(const Path& path, const Path& newPath);

        /*! \brief Delete a Directory
         *
         * \param path The Path of the directory to delete
         *
         */
        static void remove(const Path& path);

    public:

        /*! \brief Default constructor
         *
         */
        Directory() = default;

        /*! \brief Constructor
         *
         * \param path The Path of the directory
         *
         */
        explicit Directory(const Path& path);

        /*! \brief Constructor by movement
         *
         * \param directory The Directory to move
         *
         */
        Directory(Directory&& directory) noexcept = default;

        /*! \brief Destructor
         *
         */
        ~Directory();

        /*! \brief Basic assignment operator by movement
         *
         * \param directory The Directory to move
         *
         * \return This
         *
         */
        Directory& operator=(Directory&& directory) noexcept = default;

        /*! \brief Open the Directory
         *
         * \param path The Path of the Directory to open
         *
         */
        void open(const Path& path);

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
        const Path& getPath() const;

    private:

        Path                                m_path;
        std::unique_ptr<prv::DirectoryImpl> m_impl;
    };
}

#endif // BULL_CORE_FILESYSTEM_DIRECTORY_HPP
