#ifndef BULL_CORE_FILESYSTEM_FILE_HPP
#define BULL_CORE_FILESYSTEM_FILE_HPP

#include <memory>

#include <Bull/Core/Exception/Exception.hpp>
#include <Bull/Core/FileSystem/FileOpeningMode.hpp>
#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/IO/CursorAwareInStream.hpp>
#include <Bull/Core/IO/OutStream.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Time/DateTime.hpp>

namespace Bull
{
    DeclareException(FileNotFound);
    DeclareException(FileAlreadyExists);

    namespace prv
    {
        class FileImpl;
    }

    class BULL_CORE_API File : public NonCopyable, public CursorAwareInStream, public OutStream
    {
    private:

        #if defined BULL_OS_WINDOWS
            static constexpr const char* EndOfLine = "\r\n";
        #else
            static constexpr char EndOfLine = '\n';
        #endif

    public:

        /*! \brief Create a File
         *
         * \param path The Path of the file to create
         *
         */
        static void create(const Path& path);

        /*! \brief Tell whether a File exists
         *
         * \param path The Path of the File
         *
         * \return True if the file exists
         *
         */
        static bool exists(const Path& path);

        /*! \brief Copy a File
         *
         * \param path    The Path of the file to copy
         * \param newPath The new Path copied File
         *
         */
        static void copy(const Path& path, const Path& newPath);

        /*! \brief Rename a File
         *
         * \param path    The Path of the File to rename
         * \param newPath The new Path of the File
         *
         */
        static void rename(const Path& path, const Path& newPath);

        /*! \brief Delete a File
         *
         * \param path The Path of the File to delete
         *
         */
        static void remove(const Path& path);

    public:

        /*! \brief Default constructor
         *
         */
        File();

        /*! \brief Constructor
         *
         * \param path The Path of the file to open
         * \param mode The opening mode of the file (read, write or both)
         *
         */
        explicit File(const Path& path, Uint32 mode = FileOpeningMode_Read | FileOpeningMode_Write);

        /*! \brief Constructor by movement
         *
         * \param file The File to move
         *
         */
        File(File&& file) noexcept;

        /*! \brief Destructor
         *
         */
        ~File();

        /*! \brief Basic assignment operator by movement
         *
         * \param File The File to move
         *
         * \return This
         *
         */
        File& operator=(File&& file) noexcept;

        /*! \brief Open the File
         *
         * \param path The path of the file to open
         * \param mode The opening mode of the file
         *
         */
        void open(const Path& path, Uint32 mode = FileOpeningMode_Read | FileOpeningMode_Write);

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
        inline const Path& getPath() const
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

        Path                           m_path;
        Uint32                         m_mode;
        std::unique_ptr<prv::FileImpl> m_impl;
    };
}

#endif // BULL_CORE_FILESYSTEM_FILE_HPP
