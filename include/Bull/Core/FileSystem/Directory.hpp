#ifndef Bull_Directory_hpp
#define Bull_Directory_hpp

#include <memory>
#include <vector>

#include <Bull/Core/FileSystem/DirectoryHandler.hpp>
#include <Bull/Core/FileSystem/FileSystemEntity.hpp>
#include <Bull/Core/Integer.hpp>
#include <Bull/Core/String.hpp>

namespace Bull
{
    namespace prv
    {
        class DirectoryImpl;
    }

    class BULL_API Directory
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
        static bool copy(const String& path, const String& newPath);

        /*! \brief Rename a directory
         *
         * \param path The path of the directory to rename
         * \param newPath The new path of the directory
         *
         * \return Return true if the directory was renamed successfully, false otherwise
         *
         */
        static bool rename(const String& path, const String& newPath);

        /*! \brief Delete a directory
         *
         * \param path The path of the directory to delete
         *
         * \return Return true if the directory was deleted successfully, false otherwise
         *
         */
        static bool remove(const String& path);

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
        Directory(const String& path);

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
        bool open(const String& path);

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
        std::vector<FileSystemEntity> getContent(Uint32 flags = SearchFlag::All);

        /*! \brief Get the name of the directory
         *
         * \return Return the name of the directory
         *
         */
        String getName() const;

        /*! \brief Get the path of the directory
         *
         * \return Return the path of the directory
         *
         */
        String getPath() const;

        /*! \brief Get the directory system handler
         *
         * \return Return the native directory system handler
         *
         */
        DirectoryHandler getSystemHandler() const;

    private:

        String m_path;

        std::unique_ptr<prv::DirectoryImpl> m_impl;
    };
}

#endif // Bull_Directory_hpp
