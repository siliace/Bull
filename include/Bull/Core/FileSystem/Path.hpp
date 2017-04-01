#ifndef Bull_Path_hpp
#define Bull_Path_hpp

#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    struct BULL_API Path
    {
    public:

        /*! @brief Default constructor
         *
         */
        Path();

        /*! @brief Constructor
         *
         * @param path The path
         *
         */
        Path(const String& path);

        /*! @brief Compare two Path
         *
         * @param right The Path to compare to this
         *
         * @return True if this and right are equal
         *
         */
        bool operator==(const Path& right) const;

        /*! @brief Compare two Path
         *
         * @param right The Path to compare to this
         *
         * @return True if this and right are not equal
         *
         */
        bool operator!=(const Path& right) const;

        /*! @brief Check whether the path is a file
         *
         * @return True if the file is a string
         *
         */
        bool isFile() const;

        /*! @brief Check whether the path is a directory
         *
         * @return True if the directory is a string
         *
         */
        bool isDirectory() const;

        /*! @brief Convert the Path to a String
         *
         * @return The Path as a String
         *
         */
        String toString() const;

    private:

        String m_path;
        bool   m_isFile;
        bool   m_isDirectory;
    };
}

#endif // Bull_Path_hpp
