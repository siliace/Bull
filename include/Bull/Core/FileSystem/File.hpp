#ifndef BULL_CORE_FILESYSTEM_FILE_HPP
#define BULL_CORE_FILESYSTEM_FILE_HPP

#include <memory>

#include <Bull/Core/FileSystem/FileOpeningMode.hpp>
#include <Bull/Core/IO/InStream.hpp>
#include <Bull/Core/IO/OutStream.hpp>
#include <Bull/Core/Time/DateTime.hpp>

namespace Bull
{
    class Path;

    namespace prv
    {
        class FileImpl;
    }

    class BULL_CORE_API File : public InStream, public OutStream
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
         */
        static void rename(const Path& name, const String& newName);

        /*! \brief Delete a file
         *
         * \param name The name of the file to delete
         *
         */
        static void remove(const Path& name);

    public:

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

        /*! \brief Read bytes from the File
         *
         * \param length The length of data to read
         *
         * \return Read bytes
         *
         */
        ByteArray read(std::size_t length) override;

        /*! \brief Write data into the File
         *
         * \param bytes Bytes to write
         *
         * \return Return the number of bytes written
         *
         */
        std::size_t write(const ByteArray& bytes) override;

        /*! \brief Skip bytes in the File
         *
         * \param length The number of bytes to skip
         *
         */
        void skip(std::size_t length) override;

        /*! \brief Tell whether the File is at its end
         *
         * \return True if the File is at the end
         *
         */
        bool isAtEnd() const override;

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
        std::size_t getCursor() const;

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
        std::size_t setCursor(std::size_t position);

        /*! \brief Get the path of the file
         *
         * \return Return the path of the file
         *
         */
        inline const String& getPath() const
        {
            return m_path;
        }

        /*! \brief Get the size of the file
         *
         * \return Return the size of the file
         *
         */
        std::size_t getSize() const override;

    private:

        friend class Path;

        /*! \brief Constructor
         *
         * \param path The path of the file to open
         * \param mode The opening mode of the file (read, write or both)
         *
         */
        File(const String& path, Uint32 mode);

    private:

        String                         m_path;
        Uint32                         m_mode;
        std::unique_ptr<prv::FileImpl> m_impl;
    };
}

#endif // BULL_CORE_FILESYSTEM_FILE_HPP
