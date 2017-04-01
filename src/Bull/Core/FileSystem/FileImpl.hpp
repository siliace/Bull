#ifndef Bull_FileImpl_hpp
#define Bull_FileImpl_hpp

#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

namespace Bull
{
    class File;

    namespace prv
    {
        class FileImpl : public NonCopyable
        {
        public:

            /*! @brief Create a OS specific FileImpl
             *
             * @param name The name of the file to open
             * @param mode The opening mode of the file
             *
             * @return Return the instance of the FileImpl if the file exist, nullptr otherwise
             *
             */
            static FileImpl* createInstance(const Path& name, Uint32 mode);

            /*! @brief Create a file
             *
             * @param name The name of the file to create
             *
             * @return Return true if the file was created successfully, else otherwise
             *
             */
            static bool create(const String& name);

            /*! @brief Check if a file exists
             *
             * @param name The name of the file to check
             *
             * @return Return true if the file exists, false otherwise
             *
             */
            static bool exists(const String& name);

            /*! @brief Copy a file
             *
             * @param path The path (relative or absolute) of the file to copy
             * @param path The new path (relative or absolute) of the file
             *
             * @return Return true if the copy was successfully, false otherwise
             *
             */
            static bool copy(const Path& path, const String& newPath);

            /*! @brief Delete a file
             *
             * @param name The name of the file to delete
             *
             * @return Return true if the file was deleted successfully, false otherwise
             *
             */
            static bool remove(const Path& name);

        public:

            /*! @brief Destructor
             *
             */
            virtual ~FileImpl();

            /*! @brief Open a file
             *
             * @param name The name of the file
             * @param mode The opening mode of the file (read, write or both)
             *
             * @return Return true if the file was open successfully, false otherwise
             *
             */
            virtual bool open(const Path& name, Uint32 mode) = 0;

            /*! @brief Read in a file
             *
             * @param dst The destination of the read data
             * @param size The number of byte to read
             *
             * @param Return the number of byte read
             *
             */
            virtual Uint64 read(void* dst, Uint64 size) = 0;

            /*! @brief Write a byte in this file
             *
             * @param byte A byte to write
             *
             */
            virtual Uint64 write(const void* data, Uint64 size) = 0;

            /*! @brief Get the date of the creation of the file
             *
             * @return Return the date of the creation of the file
             *
             */
            virtual Date getCreationDate() const = 0;

            /*! @brief Get the date of the creation of the file
             *
             * @return Return the date of the last access of the file
             *
             */
            virtual Date getLastAccessDate() const = 0;

            /*! @brief Get the date of the creation of the file
             *
             * @return Return the date of the last write of the file
             *
             */
            virtual Date getLastWriteDate() const = 0;

            /*! @brief Get the position of the cursor in the file
             *
             * @return Return the position of the cursor in the file
             *
             */
            virtual Uint64 getCursor() const = 0;

            /*! @brief Move the reading position in the file
             *
             * @param offset The offset to move the cursor
             *
             * @return Return true if the cursor reached its new position, false otherwise
             *
             */
            virtual Uint64 moveCursor(Int64 offset) = 0;

            /*! @brief Set the reading position in the file
             *
             * @param position The position to seek to
             *
             * @return Return true if the cursor reached its new position, false otherwise
             *
             */
            virtual Uint64 setCursor(Uint64 offset) = 0;

            /*! @brief Get the size of the file
             *
             * @return Return the size of the file
             *
             */
            virtual Uint64 getSize() const = 0;

        protected:

            /*! @brief Constructor
             *
             */
            FileImpl() = default;
        };
    }
}

#endif // Bull_FileImpl_hpp
