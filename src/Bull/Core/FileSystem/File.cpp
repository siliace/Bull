#include <cstdio>
#include <cstring>

#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/FileSystem/FileImpl.hpp>

namespace Bull
{
    bool File::create(const String& name)
    {
        return prv::FileImpl::create(name);
    }

    bool File::exists(const String& name)
    {
        return prv::FileImpl::exists(name);
    }

    bool File::copy(const Path& path, const String& newPath)
    {
        return prv::FileImpl::copy(path, newPath);
    }

    bool File::rename(const Path& name, const String& newName)
    {
        if(File::exists(name.toString()) && !File::exists(newName))
        {
            return ::rename(name.toString().getBuffer(), newName.getBuffer()) == 0;
        }

        return false;
    }

    bool File::remove(const Path& name)
    {
        return prv::FileImpl::remove(name);
    }

    File::File() :
        m_mode(FileOpeningMode_None)
    {
        /// Nothing
    }

    File::File(const Path& path, Uint32 mode)
    {
        open(path, mode);
    }

    File::~File()
    {
        close();
    }

    bool File::open(const Path& path, Uint32 mode)
    {
        if(path.isFile())
        {
            if(isOpen())
            {
                close();
            }

            m_path = path;
            m_mode = mode;
            m_impl = prv::FileImpl::createInstance(m_path, m_mode);

            if(mode & FileOpeningMode_Read)
            {
                setCursor(0);
            }

            return true;
        }

        return false;
    }

    bool File::isOpen() const
    {
        return m_impl != nullptr;
    }

    void File::close()
    {
        flush();

        m_impl.reset();
        m_path = Path();
        m_mode = FileOpeningMode_None;
    }

    std::size_t File::read(void* data, std::size_t size)
    {
        if(m_impl)
        {
            return m_impl->read(data, size);
        }

        return 0;
    }

    std::size_t File::write(const String& line)
    {
        return write(line.getBuffer(), line.getSize());
    }

    std::size_t File::writeLine(const String& line)
    {
        return write(line + EndOfLine);
    }

    std::size_t File::write(const void* data, std::size_t size)
    {
        if(m_impl)
        {
            return m_impl->write(data, size);
        }

        return 0;
    }

    void File::flush()
    {
        if(m_impl)
        {
            m_impl->flush();
        }
    }

    Date File::getCreationDate() const
    {
        if(m_impl)
        {
            return m_impl->getCreationDate();
        }

        return Date();
    }

    Date File::getLastAccessDate() const
    {
        if(m_impl)
        {
            return m_impl->getLastAccessDate();
        }

        return Date();
    }

    Date File::getLastWriteDate() const
    {
        if(m_impl)
        {
            return m_impl->getLastWriteDate();
        }

        return Date();
    }

    std::size_t File::getCursor() const
    {
        if(m_impl)
        {
            return m_impl->getCursor();
        }

        return 0;
    }

    std::size_t File::moveCursor(Int64 offset)
    {
        if(m_impl)
        {
            return m_impl->moveCursor(offset);
        }

        return 0;
    }

    std::size_t File::setCursor(std::size_t position)
    {
        if(m_impl)
        {
            return m_impl->setCursor(position);
        }

        return 0;
    }

    const Path& File::getPath() const
    {
        return m_path;
    }

    std::size_t File::getSize() const
    {
        if(m_impl)
        {
            return m_impl->getSize();
        }

        return 0;
    }

    Uint32 File::getOpeningMode() const
    {
        return m_mode;
    }

    bool File::canRead() const
    {
        return m_mode & FileOpeningMode_Read;
    }

    bool File::canWrite() const
    {
        return m_mode & FileOpeningMode_Write;
    }
}
