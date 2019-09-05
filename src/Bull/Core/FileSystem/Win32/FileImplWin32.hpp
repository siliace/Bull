#ifndef BULL_CORE_FILESYSTEM_FILEIMPLWIN32_HPP
#define BULL_CORE_FILESYSTEM_FILEIMPLWIN32_HPP

#include <Bull/Core/FileSystem/FileImpl.hpp>
#include <Bull/Core/Support/Win32/Windows.hpp>

namespace Bull
{
    namespace prv
    {
        class FileImplWin32 : public FileImpl
        {
        public:

            /** \brief Create a File
             *
             * \param path The Path of the file to create
             *
             */
            static void create(const Path& name);

            /** \brief Tell whether a File exists
             *
             * \param path The Path of the File
             *
             * \return True if the file exists
             *
             */
            static bool exists(const Path& path);

            /** \brief Copy a File
             *
             * \param path    The Path of the file to copy
             * \param newPath The new Path copied File
             *
             */
            static void copy(const Path& path, const Path& newPath);

            /** \brief Rename a File
             *
             * \param path    The Path of the File to rename
             * \param newPath The new Path of the File
             *
             */
            static void rename(const Path& path, const Path& newPath);

            /** \brief Delete a File
             *
             * \param path The Path of the File to delete
             *
             */
            static void remove(const Path& path);

        public:

            /** \brief Constructor
             *
             * \param path The path of the file to open
             * \param mode The opening mode of the file
             *
             */
            FileImplWin32(const Path& path, Uint32 mode);

            /** \brief Destructor
             *
             */
            ~FileImplWin32();

            /** \brief Read bytes from the File
             *
             * \param length The length of data to read
             *
             * \return Read bytes
             *
             */
            ByteArray read(std::size_t length) override;

            /** \brief Write data into a File
             *
             * \param bytes Bytes to write
             *
             * \return Return the number of bytes written
             *
             */
            size_t write(const ByteArray& bytes) override;

            /** \brief Flush the File
             *
             */
            void flush() override;

            /** \brief Get the date of the creation of the file
             *
             * \return Return the date of the creation of the file
             *
             */
            DateTime getCreationDate() const override;

            /** \brief Get the date of the creation of the file
             *
             * \return Return the date of the last access of the file
             *
             */
            DateTime getLastAccessDate() const override;

            /** \brief Get the date of the creation of the file
             *
             * \return Return the date of the last write of the file
             *
             */
            DateTime getLastWriteDate() const override;

            /** \brief Get the position of the cursor in the file
             *
             * \return Return the position of the cursor in the file
             *
             */
            std::size_t getCursor() const override;

            /** \brief Set the reading position in the file
             *
             * \param position The position to seek to
             *
             * \return Return true if the cursor reached its new position, false otherwise
             *
             */
            std::size_t moveCursor(Int64 offset) override;

            /** \brief Set the reading position in the file
             *
             * \param position The position to seek to
             *
             * \return Return true if the cursor reached its new position, false otherwise
             *
             */
            std::size_t setCursor(std::size_t offset) override;

            /** \brief Get the size of the file
             *
             * \return Return the size of the file
             *
             */
            std::size_t getSize() const override;

        private:

            HANDLE m_handler;
        };
    }
}

#endif // BULL_CORE_FILESYSTEM_FILEIMPLWIN32_HPP
