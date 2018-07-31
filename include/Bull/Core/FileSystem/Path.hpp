#ifndef BULL_CORE_FILESYSTEM_PATH_HPP
#define BULL_CORE_FILESYSTEM_PATH_HPP

#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    class BULL_CORE_API Path
    {
    public:

        #ifdef BULL_OS_WINDOWS
            static constexpr char Separator = '\\';
        #else
            static constexpr char Separator = '/';
        #endif

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

        /*! \brief Default constructor
         *
         */
        Path() = default;

        /*! \brief Constructor
         *
         * \param path The path to open
         */
        explicit Path(const String& path);

        /*! \brief Open a Path
         *
         * \param path The path to open
         *
         * \return This
         *
         */
        Path& open(const String& path);

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
        Path getChild(const String& child) const;

        /*! \brief Get the extension of the file path
         *
         * \return The file's extension
         *
         */
        String getFileExtension() const;

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
