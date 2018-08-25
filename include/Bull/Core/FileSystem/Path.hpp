#ifndef BULL_CORE_FILESYSTEM_PATH_HPP
#define BULL_CORE_FILESYSTEM_PATH_HPP

#include <Bull/Core/FileSystem/FileOpeningMode.hpp>
#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    class BULL_CORE_API Path
    {
    public:

    #if defined BULL_OS_WINDOWS
        static constexpr char Separator = '\\';
    #else
        static constexpr char Separator = '/';
    #endif

    public:

        /*! \brief Default constructor
         *
         */
        Path() = default;

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

        /*! \brief Convert the Path to an absolute Path
         *
         * \return The absolute Path
         *
         */
        Path toAbsolute() const;

        /*! \brief Get the file name of the Path
         *
         * This method will return last element of the Path
         *
         * \return The file name
         *
         */
        String getFileName() const;

        /*! \brief Tell whether the Path is a file
         *
         * \return True if the Path is a file
         *
         */
        bool isFile() const;

        /*! \brief Tell whether the Path is a directory
         *
         * \return True if the Path is a directory
         *
         */
        bool isDirectory() const;

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
