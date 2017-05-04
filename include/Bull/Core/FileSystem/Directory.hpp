#ifndef BULL_DIRECTORY_HPP
#define BULL_DIRECTORY_HPP

#include <memory>
#include <vector>

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/System/Integer.hpp>

namespace Bull
{
    namespace prv
    {
        class DirectoryImpl;
    }

    class BULL_CORE_API Directory
    {
    public:

        enum SearchFlag
        {
            None        = 0x00,
            Files       = 0x01,
            Directories = 0x02,
            All         = Files | Directories
        };

        /*! \brief Create a directory
         *
         * \param path The path of the directory to create
         *
         * \return Return true if the file was created successfully, else otherwise
         *
         */
        static bool create(const String& path);

        /*! \brief Check if a directory exists
         *
         * \param path The path of the directory to check
         *
         * \return Return true if the directory exists, false otherwise
         *
         */
        static bool exists(const String& path);

        /*! \brief Copy a directory
         *
         * \param path The path (relative or absolute) of the directory to copy
         * \param path The new path (relative or absolute) of the directory
         *
         * \return Return true if the copy was successfully, false otherwise
         *
         */
        static bool copy(const Path& path, const String& newPath);

        /*! \brief Rename a directory
         *
         * \param path The path of the directory to rename
         * \param newPath The new path of the directory
         *
         * \return Return true if the directory was renamed successfully, false otherwise
         *
         */
        static bool rename(const Path& path, const String& newPath);

        /*! \brief Delete a directory
         *
         * \param path The path of the directory to delete
         *
         * \return Return true if the directory was deleted successfully, false otherwise
         *
         */
        static bool remove(const Path& path);

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
        Directory(const Path& path);

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

#endif // BULL_DIRECTORY_HPP
