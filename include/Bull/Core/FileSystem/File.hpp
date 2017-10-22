#ifndef BULL_CORE_FILESYSTEM_FILE_HPP
#define BULL_CORE_FILESYSTEM_FILE_HPP

#include <memory>

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/IO/InOutStream.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Pattern/ObjectRef.hpp>
#include <Bull/Core/Time/Date.hpp>

namespace Bull
{
    class File;

    namespace prv
    {
        class FileImpl;
    }

    using FileRef = ObjectRef<File>;
    using FileConstRef = ObjectRef<const File>;

    class BULL_CORE_API File : public InOutStream, public RefCounted
    {
    public:

        enum OpeningMode
        {
            None      = 0x00,
            Append    = 0x01,
            Write     = 0x02,
            Exists    = 0x04,
            Truncate  = 0x08,
            Read      = 0x16,
            ReadWrite = Read | Write,
        };

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

        /*! \brief Copy a File
         *
         * \param path    The Path of the file to copy
         * \param newPath The new Path copied File
         *
         * \return True if the copy was successfully
         *
         */
        static bool copy(const Path& path, const String& newPath);

        /*! \brief Rename a File
         *
         * \param name    The name of the File to rename
         * \param newName The new name of the File
         *
         * \return True if the file was renamed successfully
         *
         */
        static bool rename(const Path& name, const String& newName);

        /*! \brief Delete a file
         *
         * \param name The name of the file to delete
         *
         * \return Return true if the file was deleted successfully, false otherwise
         *
         */
        static bool remove(const Path& name);

        /*! \brief Make a File
         *
         * \param args Arguments to use to construct the File
         *
         * \return The created File
         *
         */
        template <typename... Args>
        static FileRef make(Args&&... args);

    public:

        /*! \brief Constructor
         *
         */
        File();

        /*! \brief Constructor
         *
         * \param path The path of the file to open
         * \param mode The opening mode of the file (read, write or both)
         *
         */
        explicit File(const Path& path, Uint32 mode = OpeningMode::Read | OpeningMode::Write);

        /*! \brief Destructor
         *
         */
        ~File();

        /*! \brief Open a file
         *
         * \param path The path of the file to open
         * \param mode The opening mode of the file (read, write or both)
         *
         * \return Return true if the file was opened successfully, false otherwise
         *
         */
        bool open(const Path& path, Uint32 mode = OpeningMode::Read | OpeningMode::Write);

        /*! \brief Check if a file is open
         *
         * \return Return true if the file is open, false otherwise
         *
         */
        bool isOpen() const;

        /*! \brief Close a file
         *
         */
        void close();

        /*! \brief Read bytes from the file
         *
         * \param data The buffer to fill with data of the file
         * \param size The size of the buffer
         *
         * \return Return the number of bytes actually read
         *
         */
        Uint64 read(void* data, Uint64 size);

        /*! \brief Read a line in the file
         *
         * \param line The line to fill
         *
         * \return Return true if the file has still lines to read
         *
         */
        bool readLine(String& line);

        /*! \brief Write a buffer in the file
         *
         * \param data The buffer to write into the file
         * \param size The size of the buffer
         *
         * \return Return the number of bytes actually written
         *
         */
        Uint64 write(const void* data, Uint64 size);

        /*! \brief Write a string in the file
         *
         * \param string The string to write
         *
         * \return Return the number of bytes actually written
         *
         */
        Uint64 write(const String& string);

        /*! \brief Get the date of the creation of the file
         *
         * \return Return the date of the creation of the file
         *
         */
        Date getCreationDate() const;

        /*! \brief Get the date of the creation of the file
         *
         * \return Return the date of the last access of the file
         *
         */
        Date getLastAccessDate() const;

        /*! \brief Get the date of the creation of the file
         *
         * \return Return the date of the last write of the file
         *
         */
        Date getLastWriteDate() const;

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
         * \return Return the actual position of the cursor
         *
         */
        Uint64 moveCursor(Int64 offset);

        /*! \brief Set the reading position in the file
         *
         * \param position The position to seek to
         *
         * \return Return the actual position of the cursor
         *
         */
        Uint64 setCursor(Uint64 position);

        /*! \brief Get the path of the file
         *
         * \return Return the path of the file
         *
         */
        inline const Path& getPath() const;

        /*! \brief Get the size of the file
         *
         * \return Return the size of the file
         *
         */
        Uint64 getSize() const;

        /*! \brief Get the opening mode of the file
         *
         * \return Return the opening mode of the file
         *
         */
        inline Uint32 getOpeningMode() const;

        /*! \brief Check if this file is open with read permission
         *
         * \return Return true if this file is open with read permission, false otherwise
         *
         */
        inline bool canRead() const;

        /*! \brief Check if this file is open with write permission
         *
         * \return Return true if this file is open with write permission, false otherwise
         *
         */
        inline bool canWrite() const;

        /*! \brief Check if the cursor is at the end of the file
         *
         * \return Return true if the cursor is at end of file, false otherwise
         *
         */
        inline bool isAtEof() const;

        /*! \brief Convert the file to a boolean
         *
         * \return True if the file is open
         *
         */
        operator bool() const;

    private:

        bool                           m_eof;
        Path                           m_path;
        Uint32                         m_mode;
        std::unique_ptr<prv::FileImpl> m_impl;
    };
}

#include <Bull/Core/FileSystem/File.inl>

#endif // BULL_CORE_FILESYSTEM_FILE_HPP
