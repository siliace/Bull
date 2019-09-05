#ifndef BULL_CORE_FILESYSTEM_PATH_HPP
#define BULL_CORE_FILESYSTEM_PATH_HPP

#include <string>

#include <Bull/Core/Export.hpp>
#include <Bull/Core/FileSystem/FileOpeningMode.hpp>

namespace Bull
{
    /**
     * \brief
     */
    class BULL_CORE_API Path
    {
    public:

        static constexpr char Separator = '\\';

        /**
         * \brief
         * \param path
         * \param newPath
         * \param failIfExists
         */
        static void copy(const Path& path, const Path& newPath, bool failIfExists = false);

        /**
         * \brief
         * \param path
         * \param newPath
         */
        static void rename(const Path& path, const Path& newPath);

    public:

        /** \brief Default constructor
         *
         */
        Path() = default;

        /** \brief Constructor
         *
         * \param path The path to open
         */
        explicit Path(const std::string& path);

        /** \brief Compare two Path
         *
         * \param right The Path to compare to this
         *
         * \return True if this and right are equal
         *
         */
        bool operator==(const Path& right) const;

        /** \brief Compare two Path
         *
         * \param right The Path to compare to this
         *
         * \return True if this and right are not equal
         *
         */
        bool operator!=(const Path& right) const;

        /** \brief Get the parent directory of this Path
         *
         * \return The parent path
         *
         */
        Path getParent() const;

        /** \brief Get a child Path of this Path
         *
         * \param child The name of the child
         *
         * \return The child Path
         *
         */
        Path resolve(const std::string& child) const;

        /** \brief Convert the Path to an absolute Path
         *
         * \return The absolute Path
         *
         */
        Path toAbsolute() const;

        /** \brief Get the file name of the Path
         *
         * This method will return last element of the Path
         *
         * \return The file name
         *
         */
        std::string getFileName() const;

        /** \brief Tell whether the Path is a file
         *
         * \return True if the Path is a file
         *
         */
        bool isFile() const;

        /** \brief Tell whether the Path is a directory
         *
         * \return True if the Path is a directory
         *
         */
        bool isDirectory() const;

        /** \brief Convert the Path to a std::string
         *
         * \return The Path as a std::string
         *
         */
        const std::string& toString() const;

    private:

        std::string m_path;
    };
}

#endif // BULL_CORE_FILESYSTEM_PATH_HPP
