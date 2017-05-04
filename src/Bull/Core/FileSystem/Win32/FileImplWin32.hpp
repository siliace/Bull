#ifndef Bull_FileImplWin32_hpp
#define Bull_FileImplWin32_hpp

#include <windows.h>

#include <Bull/Core/FileSystem/FileImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class FileImplWin32 : public FileImpl
        {
        public:

            /*! \brief Create a file
             *
             * \param name The name of the file to create
             *
             * \return Return true if the file was created successfully, else otherwise
             *
             */
            static bool create(const String& name);

            /*! \brief Check if a file exists
             *
             * \param name The name of the file to check
             *
             * \return Return true if the file exists, false otherwise
             *
             */
            static bool exists(const String& name);

            /*! \brief Copy a file
             *
             * \param path The path (relative or absolute) of the file to copy
             * \param path The new path (relative or absolute) of the file
             *
             * \return Return true if the copy was successfully, false otherwise
             *
             */
            static bool copy(const Path& path, const String& newPath);

            /*! \brief Delete a file
             *
             * \param name The name of the file to delete
             *
             * \return Return true if the file was deleted successfully, false otherwise
             *
             */
            static bool remove(const Path& name);

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
            ~FileImplWin32();

            /*! \brief Open the file
             *
             * \param name The name of the file to open
             * \param mode The opening mode of the file (read, write or both)
             *
             * \return Return true if the file was open successfully, false otherwise
             *
             */
            bool open(const Path& name, Uint32 mode) override;

            /*! \brief Read in a file
             *
             * \param dst The destination of the read data
             * \param size The number of byte to read
             *
             * \param Return the number of byte read
             *
             */
            Uint64 read(void* data, Uint64 size) override;

            /*! \brief Write a byte in this file
             *
             * \param byte A byte to write
             *
             */
            Uint64 write(const void* data, Uint64 size) override;

            /*! \brief Get the date of the creation of the file
             *
             * \return Return the date of the creation of the file
             *
             */
            Date getCreationDate() const override;

            /*! \brief Get the date of the creation of the file
             *
             * \return Return the date of the last access of the file
             *
             */
            Date getLastAccessDate() const override;

            /*! \brief Get the date of the creation of the file
             *
             * \return Return the date of the last write of the file
             *
             */
            Date getLastWriteDate() const override;

            /*! \brief Get the position of the cursor in the file
             *
             * \return Return the position of the cursor in the file
             *
             */
            Uint64 getCursor() const override;

            /*! \brief Set the reading position in the file
             *
             * \param position The position to seek to
             *
             * \return Return true if the cursor reached its new position, false otherwise
             *
             */
            Uint64 moveCursor(Int64 offset) override;

            /*! \brief Set the reading position in the file
             *
             * \param position The position to seek to
             *
             * \return Return true if the cursor reached its new position, false otherwise
             *
             */
            Uint64 setCursor(Uint64 offset) override;

            /*! \brief Get the size of the file
             *
             * \return Return the size of the file
             *
             */
            Uint64 getSize() const override;

        private:

            HANDLE m_handler;
        };
    }
}

#endif // Bull_FileImplWin32_hpp
