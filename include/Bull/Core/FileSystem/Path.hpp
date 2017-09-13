#ifndef BULL_CORE_FILESYSTEM_PATH_HPP
#define BULL_CORE_FILESYSTEM_PATH_HPP

#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    struct BULL_CORE_API Path
    {
    public:

        #ifdef BULL_OS_WINDOWS
            static constexpr char Separator = '\\';
        #else
            static constexpr char Separator = '/';
        #endif

    public:

        /*! \brief Default constructor
         *
         */
        Path();

        /*! \brief Constructor
         *
         * \param path The path
         *
         */
        explicit Path(const String& path);

        /*! \brief Open the Path
         *
         * \param path The path to open
         *
         * \return This
         *
         */
        Path& open(const String& path);

        /*! \brief Tell whether the Path is valid
         *
         * \return True if the path is valid
         *
         */
        bool isValid() const;

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

        /*! \brief Get the path without the filename
         *
         * \return The path
         *
         */
        String getPath() const;

        /*! \brief Get the filename in the path
         *
         * \return The filename
         *
         */
        String getFileName() const;

        /*! \brief Get the filename without its extension in the path
         *
         * \return The filename without extension
         *
         */
        String getFileNameWithoutExtension() const;

        /*! \brief Get the extension of the file
         *
         * \return The extension
         *
         */
        String getExtension() const;

        /*! \brief Set the base Path
         *
         * \param base The base Path
         *
         * \return This
         *
         */
        Path& setBasePath(const Path& base);

        /*! \brief Check whether the path is a file
         *
         * \return True if the file is a string
         *
         */
        bool isFile() const;

        /*! \brief Check whether the path is a directory
         *
         * \return True if the directory is a string
         *
         */
        bool isDirectory() const;

        /*! \brief Convert the Path to a String
         *
         * \return The Path as a String
         *
         */
        String toString() const;

    private:

        String m_path;
        bool   m_isFile;
        bool   m_isDirectory;
    };
}

#endif // BULL_CORE_FILESYSTEM_PATH_HPP
