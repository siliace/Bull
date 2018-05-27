#ifndef BULL_CORE_FILESYSTEM_FILE_HPP
#define BULL_CORE_FILESYSTEM_FILE_HPP

#include <memory>

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/FileSystem/FileOpeningMode.hpp>
#include <Bull/Core/IO/CursorAwareInStream.hpp>
#include <Bull/Core/IO/OutStream.hpp>
#include <Bull/Core/Time/DateTime.hpp>

namespace Bull
{
    namespace prv
    {
        class FileImpl;
    }

    class BULL_CORE_API File : public CursorAwareInStream, public OutStream
    {
    private:

        #if defined BULL_OS_WINDOWS
            static constexpr const char* EndOfLine = "\r\n";
        #else
            static constexpr char EndOfLine = '\n';
        #endif

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
        explicit File(const Path& path, Uint32 mode = FileOpeningMode_ReadWrite);

        /*! \brief Constructor by movement
         *
         * \param file The File to move
         *
         */
        File(File&& file) noexcept = default;

        /*! \brief Destructor
         *
         */
        ~File();

        /*! \brief Basic assignment operator by movement
         *
         * \param directory The File to move
         *
         * \return This
         *
         */
        File& operator=(File&& file) noexcept = default;

        /*! \brief Open a file
         *
         * \param path The path of the file to open
         * \param mode The opening mode of the file (read, write or both)
         *
         * \return Return true if the file was opened successfully, false otherwise
         *
         */
        bool open(const Path& path, Uint32 mode = FileOpeningMode_ReadWrite);

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
        std::size_t read(void* data, std::size_t size) override;

        /*! \brief Write a String to the File
         *
         * \param string The String to write
         *
         * \return The number of bytes written
         *
         */
        std::size_t write(const String& line);

        /*! \brief Write a line to the File
         *
         * \param string The String to write
         *
         * \return The number of bytes written
         *
         */
        std::size_t writeLine(const String& line);

        /*! \brief Write a buffer in the file
         *
         * \param data The buffer to write into the file
         * \param size The size of the buffer
         *
         * \return Return the number of bytes actually written
         *
         */
        std::size_t write(const void* data, std::size_t size) override;

        /*! \brief Flush the File
         *
         */
        void flush() override;

        /*! \brief Get the date of the creation of the file
         *
         * \return Return the date of the creation of the file
         *
         */
        DateTime getCreationDate() const;

        /*! \brief Get the date of the creation of the file
         *
         * \return Return the date of the last access of the file
         *
         */
        DateTime getLastAccessDate() const;

        /*! \brief Get the date of the creation of the file
         *
         * \return Return the date of the last write of the file
         *
         */
        DateTime getLastWriteDate() const;

        /*! \brief Get the position of the cursor in the file
         *
         * \return Return the position of the cursor in the file
         *
         */
        std::size_t getCursor() const override;

        /*! \brief Move the reading position in the file
         *
         * \param offset The offset to move the cursor
         *
         * \return Return the actual position of the cursor
         *
         */
        std::size_t moveCursor(Int64 offset);

        /*! \brief Set the reading position in the file
         *
         * \param position The position to seek to
         *
         * \return Return the actual position of the cursor
         *
         */
        std::size_t setCursor(std::size_t position) override;

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
        std::size_t getSize() const override;

        /*! \brief Get the opening mode of the file
         *
         * \return Return the opening mode of the file
         *
         */
        Uint32 getOpeningMode() const;

        /*! \brief Check if this file is open with read permission
         *
         * \return Return true if this file is open with read permission, false otherwise
         *
         */
        bool canRead() const;

        /*! \brief Check if this file is open with write permission
         *
         * \return Return true if this file is open with write permission, false otherwise
         *
         */
        bool canWrite() const;

    private:

        Path                   m_path;
        Uint32                 m_mode;
        std::unique_ptr<prv::FileImpl> m_impl;
    };
}

#endif // BULL_CORE_FILESYSTEM_FILE_HPP
