#ifndef BULL_CORE_FILESYSTEM_FILEIMPL_HPP
#define BULL_CORE_FILESYSTEM_FILEIMPL_HPP

#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

namespace Bull
{
    class File;

    namespace prv
    {
        class FileImpl : public NonCopyable
        {
        public:

            /*! \brief Create a OS specific FileImpl
             *
             * \param name The name of the file to open
             * \param mode The opening mode of the file
             *
             * \return The created FileImpl
             *
             */
            static std::unique_ptr<FileImpl> createInstance(const String& name, Uint32 mode);

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
            virtual ~FileImpl();

            /*! \brief Read bytes from the File
             *
             * \param length The length of data to read
             *
             * \return Read bytes
             *
             */
            virtual ByteArray read(std::size_t length) = 0;

            /*! \brief Write data into a File
             *
             * \param bytes Bytes to write
             *
             * \return Return the number of bytes written
             *
             */
            virtual std::size_t write(const ByteArray& bytes) = 0;

            /*! \brief Flush the File
             *
             */
            virtual void flush() = 0;

            /*! \brief Get the date of the creation of the file
             *
             * \return Return the date of the creation of the file
             *
             */
            virtual DateTime getCreationDate() const = 0;

            /*! \brief Get the date of the creation of the file
             *
             * \return Return the date of the last access of the file
             *
             */
            virtual DateTime getLastAccessDate() const = 0;

            /*! \brief Get the date of the creation of the file
             *
             * \return Return the date of the last write of the file
             *
             */
            virtual DateTime getLastWriteDate() const = 0;

            /*! \brief Get the position of the cursor in the file
             *
             * \return Return the position of the cursor in the file
             *
             */
            virtual std::size_t getCursor() const = 0;

            /*! \brief Move the reading position in the file
             *
             * \param offset The offset to move the cursor
             *
             * \return Return true if the cursor reached its new position, false otherwise
             *
             */
            virtual std::size_t moveCursor(Int64 offset) = 0;

            /*! \brief Set the reading position in the file
             *
             * \param position The position to seek to
             *
             * \return Return true if the cursor reached its new position, false otherwise
             *
             */
            virtual std::size_t setCursor(std::size_t offset) = 0;

            /*! \brief Get the size of the file
             *
             * \return Return the size of the file
             *
             */
            virtual std::size_t getSize() const = 0;

        protected:

            /*! \brief Constructor
             *
             */
            FileImpl() = default;
        };
    }
}

#endif // BULL_CORE_FILESYSTEM_FILEIMPL_HPP
