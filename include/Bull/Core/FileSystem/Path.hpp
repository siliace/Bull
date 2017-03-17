#ifndef Bull_Path_hpp
#define Bull_Path_hpp

#include <Bull/Core/Integer.hpp>
#include <Bull/Core/String.hpp>
#include <Bull/Core/Time/Date.hpp>

namespace Bull
{
    struct BULL_API Path
    {
    public:

        static Path None;

        /*! \brief Check whether if the path is exists
         *
         * \param path The path to check
         *
         * \return True if the path exists
         *
         */
        static bool exists(const String& path);

        /*! \brief Create a path
         *
         * \param path
         * \param isFile
         * \param isDirectory
         *
         * \return The created path
         *
         */
        static Path make(const String& path, bool isFile, bool isDirectory);

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

        /*! \brief Basic assignment operator
         *
         * \param path The path
         *
         * \return This
         *
         */
        Path& operator=(const String& path);

        /*! \brief Set the path
         *
         * \param path The path
         *
         * \return This
         *
         */
        Path& set(const String& path);

        /*! \brief Compare two paths
         *
         * \param right The path to compare to this
         *
         * \return True if right and this are equal
         *
         */
        bool operator==(const Path& right) const;

        /*! \brief Compare two paths
         *
         * \param right The path to compare to this
         *
         * \return True if right and this are not equal
         *
         */
        bool operator!=(const Path& right) const;

        /*! \brief Get the path
         *
         * \return The path
         *
         */
        const String& getPathName() const;

        /*! \brief Check whether the path is corresponding to a file
         *
         * \return True if the path is a file
         *
         */
        bool isFile() const;

        /*! \brief Check whether the path is corresponding to a directory
         *
         * \return True if the path is a directory
         *
         */
        bool isDirectory() const;

        /*! \brief Check if the path reach something
         *
         * \return True if the path is valid
         *
         */
        bool isValid() const;

        /*! \brief Convert the path to a String
         *
         * \return The path as a string
         *
         */
        operator String() const;

        /*! \brief Convert the path to a const char* buffer
         *
         * \return The path as a const char* buffer
         *
         */
        operator const char*() const;

        /*! \brief Convert the path as a boolean
         *
         * \return True if the path is valid
         *
         */
        operator bool() const;

    private:

        String m_path;
        bool   m_isFile;
        bool   m_isDirectory;
    };
}

#endif // Bull_Path_hpp
