#ifndef BULL_CORE_FILESYSTEM_DIRECTORY_HPP
#define BULL_CORE_FILESYSTEM_DIRECTORY_HPP

#include <memory>
#include <vector>

#include <Bull/Core/Configuration/Integer.hpp>
#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Pattern/ObjectRef.hpp>

namespace Bull
{
    class Directory;

    namespace prv
    {
        class DirectoryImpl;
    }

    using DirectoryRef = ObjectRef<Directory>;
    using DirectoryConstRef = ObjectRef<const Directory>;

    class BULL_CORE_API Directory : public NonCopyable
    {
    public:

        enum SearchFlag
        {
            None        = 0x00,
            Files       = 0x01,
            Directories = 0x02,
            All         = Files | Directories
        };

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

        /*! \brief Make a Directory
         *
         * \param args Arguments to use to construct the Directory
         *
         * \return The created Directory
         *
         */
        template <typename... Args>
        static DirectoryRef make(Args&&... args);

    public:

        /*! \brief Default constructor
         *
         */
        Directory();

        /*! \brief Constructor
         *
         * \param path The path of the directory
         *
         */
        explicit Directory(const Path& path);

        /*! \brief Destructor
         *
         */
        ~Directory();

        /*! \brief Open a directory
         *
         * \param path The path of the directory
         *
         * \return Return true is the directory was opened successfully, false otherwise
         *
         */
        bool open(const Path& path);

        /*! \brief Check whether the directory is open
         *
         * \return Return true if the directory is open, false otherwise
         *
         */
        bool isOpen() const;

        /*! \brief Close the directory
         *
         */
        void close();

        /*! \brief Get the content of this Directory
         *
         * \param flags What we have to look for
         *
         * \return Return the list of content entity
         *
         */
        std::vector<Path> getContent(Uint32 flags = SearchFlag::All);

        /*! \brief Get the path of the directory
         *
         * \return Return the path of the directory
         *
         */
        const Path& getPath() const;

    private:

        Path                                m_path;
        std::unique_ptr<prv::DirectoryImpl> m_impl;
    };
}

#include <Bull/Core/FileSystem/Directory.inl>

#endif // BULL_CORE_FILESYSTEM_DIRECTORY_HPP
