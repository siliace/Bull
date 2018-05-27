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
            std::size_t read(void* data, std::size_t size) override;

            /*! \brief Write a byte in this file
             *
             * \param byte A byte to write
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
            DateTime getCreationDate() const override;

            /*! \brief Get the date of the creation of the file
             *
             * \return Return the date of the last access of the file
             *
             */
            DateTime getLastAccessDate() const override;

            /*! \brief Get the date of the creation of the file
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
            std::size_t getCursor() const override;

            /*! \brief Set the reading position in the file
             *
             * \param position The position to seek to
             *
             * \return Return true if the cursor reached its new position, false otherwise
             *
             */
            std::size_t moveCursor(Int64 offset) override;

            /*! \brief Set the reading position in the file
             *
             * \param position The position to seek to
             *
             * \return Return true if the cursor reached its new position, false otherwise
             *
             */
            std::size_t setCursor(std::size_t offset) override;

            /*! \brief Get the size of the file
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
