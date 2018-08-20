#ifndef BULL_CORE_FILESYSTEM_PATH_HPP
#define BULL_CORE_FILESYSTEM_PATH_HPP

#include <Bull/Core/FileSystem/FileOpeningMode.hpp>
#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    class File;
    class Directory;

    class BULL_CORE_API Path
    {
    public:

        static constexpr char Separator = '/';

        /*! \brief Create a canonical Path
         *
         * \param path The relative path
         *
         * \return The canonical Path
         *
         */
        static Path canonical(const String& path);

        /*! \brief Create a canonical Path
         *
         * \param path The relative path
         *
         * \return The canonical Path
         *
         */
        static Path canonical(const Path& path);

    public:

        /*! \brief Constructor
         *
         * \param path The path to open
         */
        explicit Path(const String& path);

        /*! \brief Compare two Path
         *
         * \param right The Path to compare to this
         *
         * \return True if this and right are equal
         *
         */
        bool operator==(const Path& right) const;

        /*! \brief Compare two Path
         *
         * \param right The Path to compare to this
         *
         * \return True if this and right are not equal
         *
         */
        bool operator!=(const Path& right) const;

        /*! \brief Get the parent directory of this Path
         *
         * \return The parent path
         *
         */
        Path getParent() const;

        /*! \brief Get a child Path of this Path
         *
         * \param child The name of the child
         *
         * \return The child Path
         *
         */
        Path resolve(const String& child) const;

        /*! \brief Tell whether the Path is a file
         *
         * \return True if the Path is a file
         *
         */
        bool isFile() const;

        /*! \brief Open the Path as a File
         *
         * \param mode The mode to use to open the File
         *
         * \return The File
         *
         */
        File toFile(Uint32 mode = FileOpeningMode_ReadWrite) const;

        /*! \brief Tell whether the Path is a directory
         *
         * \return True if the Path is a directory
         *
         */
        bool isDirectory() const;

        /*! \brief Open the Path as a Directory
         *
         * \return The Directory
         *
         */
        Directory toDirectory() const;

        /*! \brief Convert the Path to a String
         *
         * \return The Path as a String
         *
         */
        const String& toString() const;

    private:

        String m_path;
    };
}

#endif // BULL_CORE_FILESYSTEM_PATH_HPP
