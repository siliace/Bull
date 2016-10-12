#include <cstdio>

#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/FileSystem/FileImpl.hpp>
#include <Bull/Core/Thread/Lock.hpp>

namespace Bull
{
    /*! \brief Create a file
    *
    * \param name The name of the file to create
    *
    * \return Return true if the file was created successfully, else otherwise
    *
    */
    bool File::create(const String& name)
    {
        return prv::FileImpl::create(name);
    }

    /*! \brief Check if a file exists
     *
     * \param name The name of the file to check
     *
     * \return Return true if the file exists, false otherwise
     *
     */
    bool File::exists(const String& name)
    {
        return prv::FileImpl::exists(name);
    }

    /*! \brief Copy a file
     *
     * \param path The path (relative or absolute) of the file to copy
     * \param path The new path (relative or absolute) of the file
     *
     * \return Return true if the copy was successfully, false otherwise
     *
     */
    bool File::copy(const String& path, const String& newPath)
    {
        return prv::FileImpl::copy(path, newPath);
    }

    /*! \brief Rename a file
     *
     * \param name The name of the file to rename
     * \param name The new name of the file
     *
     * \return Return true if the file was renamed successfully, false otherwise
     *
     */
    bool File::rename(const String& name, const String& newName)
    {
        if(File::exists(name) && !File::exists(newName))
        {
            return ::rename(name, newName);
        }

        return false;
    }

    /*! \brief Delete a file
     *
     * \param name The name of the file to delete
     *
     * \return Return true if the file was deleted successfully, false otherwise
     *
     */
    bool File::remove(const String& name)
    {
        return prv::FileImpl::remove(name);
    }

    /*! \brief Constructor
     *
     */
    File::File() :
        m_mode(OpeningMode::None),
        m_impl(nullptr),
        m_eof(false)
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param name The name of the file to open
     * \param mode The opening mode of the file (read, write or both)
     *
     */
    File::File(const String& name, Uint32 mode) :
        m_impl(nullptr),
        m_eof(false)
    {
        open(name, mode);
    }

    /*! \brief Destructor
     *
     */
    File::~File()
    {
        Lock lock(m_mutex);

        close();
    }

    /*! \brief Open a file
     *
     * \param name The name of the file to open
     * \param mode The opening mode of the file (read, write or both)
     *
     * \return Return true if the file was opened successfully, false otherwise
     *
     */
    bool File::open(const String& name, Uint32 mode)
    {
        Lock lock(m_mutex);

        if(isOpen())
        {
            close();
        }

        m_name = name;
        m_mode = mode;
        m_impl.reset(prv::FileImpl::createInstance(m_name, m_mode));

        if(m_impl && mode & (OpeningMode::Read))
        {
            setCursor(0);
        }

        return isOpen();
    }

    /*! \brief Check if a file is open
     *
     * \param Return true if the file is open, false otherwise
     *
     */
    bool File::isOpen() const
    {
        Lock lock(m_mutex);

        return m_impl.get() != nullptr;
    }

    /*! \brief Close a file
     *
     */
    void File::close()
    {
        Lock lock(m_mutex);

        m_impl.reset(nullptr);
        m_name = "";
    }

    /*! \brief Read bytes from the file
     *
     * \param data The buffer to fill with data of the file
     * \param size The size of the buffer
     *
     * \return Return the number of bytes actually read
     *
     */
    Uint64 File::read(void* data, Uint64 size)
    {
        Lock lock(m_mutex);

        if(m_impl)
        {
            Uint64 read = m_impl->read(data, size);

            if(read < size)
            {
                m_eof = true;
            }

            return read;
        }

        return 0;
    }

    /*! \brief Read a line in the file
     *
     * \param line The line to fill
     *
     * \return Return true if the file has still lines to read
     *
     */
    bool File::readLine(String& line)
    {
        Lock lock(m_mutex);

        if(m_impl && !m_eof)
        {
            Uint8 byte;

            line.clear();

            do
            {
                if(read(&byte, 1) == 1)
                {
                    if(byte != '\n')
                    {
                        line += static_cast<char>(byte);
                    }
                }
                else
                {
                    m_eof = true;
                }
            }while(!m_eof && byte != '\n');

            return true;
        }

        return false;
    }

    /*! \brief Write a buffer in the file
     *
     * \param data The buffer to write into the file
     * \param size The size of the buffer
     *
     * \return Return the number of bytes actually written
     *
     */
    Uint64 File::write(const void* data, Uint64 size)
    {
        Lock lock(m_mutex);

        if(m_impl)
        {
            return m_impl->write(data, size);
        }

        return 0;
    }

    /*! \brief Write a string in the file
     *
     * \param string The string to write
     *
     * \return Return the number of bytes actually written
     *
     */
    Uint64 File::write(const String& string)
    {
        Lock lock(m_mutex);

        return write(&string[0], string.getSize());
    }


    /*! \brief Get the date of the creation of the file
     *
     * \return Return the date of the creation of the file
     *
     */
    Date File::getCreationDate() const
    {
        Lock lock(m_mutex);

        if(m_impl)
        {
            return m_impl->getCreationDate();
        }

        return Date();
    }

    /*! \brief Get the date of the creation of the file
     *
     * \return Return the date of the last access of the file
     *
     */
    Date File::getLastAccessDate() const
    {
        Lock lock(m_mutex);

        if(m_impl)
        {
            return m_impl->getLastAccessDate();
        }

        return Date();
    }

    /*! \brief Get the date of the creation of the file
     *
     * \return Return the date of the last write of the file
     *
     */
    Date File::getLastWriteDate() const
    {
        Lock lock(m_mutex);

        if(m_impl)
        {
            return m_impl->getLastWriteDate();
        }

        return Date();
    }

    /*! \brief Get the position of the cursor in the file
     *
     * \return Return the position of the cursor in the file
     *
     */
    Uint64 File::getCursor() const
    {
        Lock lock(m_mutex);

        if(m_impl)
        {
            return m_impl->getCursor();
        }

        return 0;
    }

    /*! \brief Move the reading position in the file
     *
     * \param offset The offset to move the cursor
     *
     * \return Return the actual position of the cursor
     *
     */
    Uint64 File::moveCursor(Int64 offset)
    {
        Lock lock(m_mutex);

        if(m_impl)
        {
            return m_impl->moveCursor(offset);
        }

        return 0;
    }

    /*! \brief Set the reading position in the file
     *
     * \param position The position to seek to
     *
     * \return Return the actual position of the cursor
     *
     */
    Uint64 File::setCursor(Uint64 offset)
    {
        Lock lock(m_mutex);

        if(m_impl)
        {
            return m_impl->setCursor(offset);
        }

        return 0;
    }

    /*! \brief Get the name of the file
     *
     * \return Return the name of the file
     *
     */
    String File::getName() const
    {
        Lock lock(m_mutex);

        return m_name;
    }

    /*! \brief Get the size of the file
     *
     * \return Return the size of the file
     *
     */
    Uint64 File::getSize() const
    {
        Lock lock(m_mutex);

        if(m_impl)
        {
            return m_impl->getSize();
        }

        return 0;
    }

    /*! \brief Get the opening mode of the file
     *
     * \return Return the opening mode of the file
     *
     */
    Uint32 File::getOpeningMode() const
    {
        return m_mode;
    }

    /*! \brief Check if this file is open with read permission
     *
     * \return Return true if this file is open with read permission, false otherwise
     *
     */
    bool File::canRead() const
    {
        return m_mode & OpeningMode::Read;
    }

    /*! \brief Check if this file is open with write permission
     *
     * \return Return true if this file is open with write permission, false otherwise
     *
     */
    bool File::canWrite() const
    {
        return m_mode & OpeningMode::Write;
    }

    /*! \brief Check if the cursor is at the end of the file
     *
     * \param Return true if the cursor is at end of file, false otherwise
     *
     */
    bool File::isAtEof() const
    {
        Lock lock(m_mutex);

        return m_eof;
    }

    /*! \brief Get the file system handler
     *
     * \return Return the native file system handler
     *
     */
    FileHandler File::getSystemHandler() const
    {
        if(m_impl)
        {
            return m_impl->getSystemHandler();
        }

        return 0;
    }
}
