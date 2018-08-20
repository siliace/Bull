#ifndef BULL_CORE_FILESYSTEM_DIRECTORYIMPL_HPP
#define BULL_CORE_FILESYSTEM_DIRECTORYIMPL_HPP

#include <vector>

#include <Bull/Core/FileSystem/Directory.hpp>
#include <Bull/Core/FileSystem/Path.hpp>

namespace Bull
{
    namespace prv
    {
        class DirectoryImpl : public NonCopyable
        {
        public:

            /*! \brief Create a OS specific DirectoryImpl
             *
             * \param path The path of the directory to open
             *
             * \return Return the instance of the DirectoryImpl if the file exist, nullptr otherwise
             *
             */
            static std::unique_ptr<DirectoryImpl> createInstance(const String& path);

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

            /*! \brief Delete a directory
             *
             * \param path The path of the directory to delete
             *
             * \return Return true if the directory was deleted successfully, false otherwise
             *
             */
            static bool remove(const Path& path);

        public:

            /*! \brief Destructor
             *
             */
            virtual ~DirectoryImpl();

            /*! \brief Get the content of this Directory
             *
             * \param flags What we have to look for
             *
             * \return Return the list of content entity
             *
             */
            virtual std::vector<Path> getContent(Uint32 flags) = 0;

        protected:

            /*! \brief Default constructor
             *
             */
            DirectoryImpl() = default;
        };
    }
}

#endif // BULL_CORE_FILESYSTEM_DIRECTORYIMPL_HPP

