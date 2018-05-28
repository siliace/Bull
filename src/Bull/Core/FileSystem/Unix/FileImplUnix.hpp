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

            /*! \brief Create a file
             *
             * \param name The name of the file to create
             *
             */
            static void create(const String& name);

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
             */
            static void remove(const Path& name);

        public:

            /*! \brief Destructor
             *
             */
            ~FileImplUnix();

            /*! \brief Open a file
             *
             * \param name The name of the file
             * \param mode The opening mode of the file (read, write or both)
             *
             * \return Return true if the file was open successfully, false otherwise
             *
             */
            bool open(const Path& name, Uint32 mode);

            /*! \brief Read in a file
             *
             * \param dst The destination of the read data
             * \param size The number of byte to read
             *
             * \param Return the number of byte read
             *
             */
            Uint64 read(void* dst, Uint64 size) override;

            /*! \brief Write a byte in this file
             *
             * \param byte A byte to write
             *
             */
            Uint64 write(const void* data, Uint64 size) override;

            /*! \brief Flush the File
             *
             */
            void flush() override;

            /*! \brief Get the date of the creation of the file
             *
             * \return Return the date of the creation of the file
             *
             */
            DateTime getCreationDate() const override;

            /*! \brief Get the date of the last access of the file
             *
             * \return Return the date of the last access of the file
             *
             */
            DateTime getLastAccessDate() const override;

            /*! \brief Get the date of the last write of the file
             *
             * \return Return the date of the last write of the file
             *
             */
            DateTime getLastWriteDate() const override;

            /*! \brief Get the position of the cursor in the file
             *
             * \return Return the position of the cursor in the file
             *
             */
            Uint64 getCursor() const;

            /*! \brief Move the reading position in the file
             *
             * \param offset The offset to move the cursor
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

            int m_handler;
        };
    }
}

#endif // BULL_CORE_FILESYSTEM_FILEIMPLUNIX_HPP
