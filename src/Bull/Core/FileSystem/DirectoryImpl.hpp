#ifndef BULL_CORE_FILESYSTEM_DIRECTORYIMPL_HPP
#define BULL_CORE_FILESYSTEM_DIRECTORYIMPL_HPP

#include <memory>
#include <vector>

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

namespace Bull
{
    namespace prv
    {
        struct DirectoryImpl : public NonCopyable
        {
            /*! \brief Create a OS specific DirectoryImpl
             *
             * \param path The Path of the Directory to open
             *
             * \return The created instance of the DirectoryImpl
             *
             */
            static std::unique_ptr<DirectoryImpl> createInstance(const Path& path);

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
        };
    }
}

#endif // BULL_CORE_FILESYSTEM_DIRECTORYIMPL_HPP

