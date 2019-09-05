#ifndef BULL_CORE_FILESYSTEM_FILEIMPLUNIX_HPP
#define BULL_CORE_FILESYSTEM_FILEIMPLUNIX_HPP

#include <Bull/Core/FileSystem/FileImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class FileImplUnix : public FileImpl
        {
        public:

            /** \brief Create a file
             *
             * \param path The Path of the File to create
             *
             */
            static void create(const Path& path);

            /** \brief Check if a File exists
             *
             * \param path The Path of the File to check
             *
             * \return True if the file exists
             *
             */
            static bool exists(const Path& path);

            /** \brief Copy a File
             *
             * \param path    The path (relative or absolute) of the File to copy
             * \param newPath The new path (relative or absolute) of the File
             *
             */
            static void copy(const Path& path, const Path& newPath);

            /** \brief Delete a file
             *
             * \param path The Path of the file to delete
             *
             */
            static void remove(const Path& path);

        public:

            /** \brief Open a File
             *
             * \param name The name of the File
             * \param mode The opening mode of the File
             *
             */
            FileImplUnix(const Path& name, Uint32 mode);

            /** \brief Destructor
             *
             */
            ~FileImplUnix();

            /** \brief Read bytes from the File
             *
             * \param length The length of data to read
             *
             * \return Read bytes
             *
             */
            ByteArray read(std::size_t length) override;

            /** \brief Write data into the File
             *
             * \param bytes Bytes to write
             *
             * \return Return the number of bytes written
             *
             */
            std::size_t write(const ByteArray& bytes) override;

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

            /** \brief Get the date of the last access of the file
             *
             * \return Return the date of the last access of the file
             *
             */
            DateTime getLastAccessDate() const override;

            /** \brief Get the date of the last write of the file
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
            Uint64 getCursor() const;

            /** \brief Move the reading position in the file
             *
             * \param offset The offset to move the cursor
             *
             * \return Return true if the cursor reached its new position, false otherwise
             *
             */
            Uint64 moveCursor(Int64 offset) override;

            /** \brief Set the reading position in the file
             *
             * \param position The position to seek to
             *
             * \return Return true if the cursor reached its new position, false otherwise
             *
             */
            Uint64 setCursor(Uint64 offset) override;

            /** \brief Get the size of the file
             *
             * \return Return the size of the file
             *
             */
            Uint64 getSize() const override;

        private:

            int m_handler;
        };
    }
}

#endif // BULL_CORE_FILESYSTEM_FILEIMPLUNIX_HPP
