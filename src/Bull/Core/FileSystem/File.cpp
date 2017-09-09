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
        return prv::FileImpl::copy(path.toString(), newPath);
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
        return prv::FileImpl::remove(name.toString());
    }

    File::File() :
        m_eof(false),
        m_mode(OpeningMode::None)
    {
        /// Nothing
    }

    File::File(const Path& path, Uint32 mode) :
        m_eof(false)
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
            m_impl.reset(prv::FileImpl::createInstance(m_path.toString(), m_mode));

            if(m_impl && (mode & OpeningMode::Read))
            {
                setCursor(0);
            }

            return isOpen();
        }

        return false;
    }

    bool File::isOpen() const
    {
        return m_impl != nullptr;
    }

    void File::close()
    {
        m_eof  = false;
        m_path = Path();
        m_mode = File::OpeningMode::None;
        m_impl.reset(nullptr);
    }

    Uint64 File::read(void* data, Uint64 size)
    {
        if(m_impl)
        {
            std::memset(data, 0, size);
            Uint64 read = m_impl->read(data, size);

            if(read < size)
            {
                m_eof = true;
            }

            return read;
        }

        return 0;
    }

    bool File::readLine(String& line)
    {
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
                        line += String(static_cast<char>(byte));
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

    Uint64 File::write(const void* data, Uint64 size)
    {
        if(m_impl)
        {
            return m_impl->write(data, size);
        }

        return 0;
    }

    Uint64 File::write(const String& string)
    {
        return write(&string[0], string.getSize());
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

    Uint64 File::getCursor() const
    {
        if(m_impl)
        {
            return m_impl->getCursor();
        }

        return 0;
    }

    Uint64 File::moveCursor(Int64 offset)
    {
        if(m_impl)
        {
            return m_impl->moveCursor(offset);
        }

        return 0;
    }

    Uint64 File::setCursor(Uint64 offset)
    {
        if(m_impl)
        {
            return m_impl->setCursor(offset);
        }

        return 0;
    }

    const Path& File::getPath() const
    {
        return m_path;
    }

    Uint64 File::getSize() const
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
        return m_mode & OpeningMode::Read;
    }

    bool File::canWrite() const
    {
        return m_mode & OpeningMode::Write;
    }

    bool File::isAtEof() const
    {
        return m_eof;
    }

    File::operator bool() const
    {
        return isOpen();
    }
}
