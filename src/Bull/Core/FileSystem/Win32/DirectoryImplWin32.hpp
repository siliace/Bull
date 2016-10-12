#ifndef Bull_DirectoryImplWin32_hpp
#define Bull_DirectoryImplWin32_hpp

#include <windows.h>

#include <Bull/Core/FileSystem/DirectoryImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class DirectoryImplWin32 : public DirectoryImpl
        {
        public:

            /*! \brief Create a directory
             *
             * \param name The name of the directory to create
             *
             * \return Return true if the file was created successfully, else otherwise
             *
             */
            static bool create(const String& name);

            /*! \brief Check if a directory exists
             *
             * \param name The name of the directory to check
             *
             * \return Return true if the directory exists, false otherwise
             *
             */
            static bool exists(const String& name);

            /*! \brief Delete a directory
             *
             * \param name The name of the directory to delete
             *
             * \return Return true if the directory was deleted successfully, false otherwise
             *
             */
            static bool remove(const String& name);

        private:

            /*! \brief Convert a SYSTEMTIME to a Bull::Date
             *
             * \param sysTime The SYSTEMTIME to convert
             *
             * \return Return the equivalent Bull::Date
             *
             */
            static Date systemTimeToDate(SYSTEMTIME sysTime);

        public:

            /*! \brief Destructor
             *
             */
            ~DirectoryImplWin32();

            /*! \brief Constructor
             *
             * \param name The name of the directory to open
             *
             */
            bool open(const String& name) override;

            /*! \brief Get the content of this Directory
             *
             * \param flags What we have to look for
             *
             * \return Return the list of content entity
             *
             */
            std::vector<FileSystemEntity> getContent(Uint32 flags) override;

            /*! \brief Get the directory system handler
             *
             * \return Return the native directory system handler
             *
             */
            DirectoryHandler getSystemHandler() const override;

        private:

            HANDLE m_handler;
            WIN32_FIND_DATA m_result;
        };
    }
}

#endif // Bull_DirectoryImplWin32_hpp


