#ifndef BULL_CORE_FILESYSTEM_FILEIMPL_HPP
#define BULL_CORE_FILESYSTEM_FILEIMPL_HPP

#include <memory>

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/Memory/ByteArray.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Time/DateTime.hpp>

namespace Bull
{
    namespace prv
    {
        class FileImpl : public NonCopyable
        {
        public:

            /** \brief Create a OS specific FileImpl
             *
             * \param name The Path of the File to open
             * \param mode The opening mode of the File
             *
             * \return The created FileImpl
             *
             */
            static std::unique_ptr<FileImpl> createInstance(const Path& path, Uint32 mode);

            /** \brief Create a File
             *
             * \param path The Path of the file to create
             *
             */
            static void create(const Path& path);

            /** \brief Tell whether a File exists
             *
             * \param path The Path of the File
             *
             * \return True if the file exists
             *
             */
            static bool exists(const Path& path);

            /** \brief Copy a file
             *
             * \param path The Path of the File to copy
             * \param path The new Path of the File
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

            /** \brief Delete a file
             *
             * \param path The Path of the File to delete
             *
             */
            static void remove(const Path& path);

        public:

            /** \brief Destructor
             *
             */
            virtual ~FileImpl();

            /** \brief Read bytes from the File
             *
             * \param length The length of data to read
             *
             * \return Read bytes
             *
             */
            virtual ByteArray read(std::size_t length) = 0;

            /** \brief Write data into a File
             *
             * \param bytes Bytes to write
             *
             * \return Return the number of bytes written
             *
             */
            virtual std::size_t write(const ByteArray& bytes) = 0;

            /** \brief Flush the File
             *
             */
            virtual void flush() = 0;

            /** \brief Get the date of the creation of the file
             *
             * \return Return the date of the creation of the file
             *
             */
            virtual DateTime getCreationDate() const = 0;

            /** \brief Get the date of the creation of the file
             *
             * \return Return the date of the last access of the file
             *
             */
            virtual DateTime getLastAccessDate() const = 0;

            /** \brief Get the date of the creation of the file
             *
             * \return Return the date of the last write of the file
             *
             */
            virtual DateTime getLastWriteDate() const = 0;

            /** \brief Get the position of the cursor in the file
             *
             * \return Return the position of the cursor in the file
             *
             */
            virtual std::size_t getCursor() const = 0;

            /** \brief Move the reading position in the file
             *
             * \param offset The offset to move the cursor
             *
             * \return Return true if the cursor reached its new position, false otherwise
             *
             */
            virtual std::size_t moveCursor(Int64 offset) = 0;

            /** \brief Set the reading position in the file
             *
             * \param position The position to seek to
             *
             * \return Return true if the cursor reached its new position, false otherwise
             *
             */
            virtual std::size_t setCursor(std::size_t offset) = 0;

            /** \brief Get the size of the file
             *
             * \return Return the size of the file
             *
             */
            virtual std::size_t getSize() const = 0;
        };
    }
}

#endif // BULL_CORE_FILESYSTEM_FILEIMPL_HPP
