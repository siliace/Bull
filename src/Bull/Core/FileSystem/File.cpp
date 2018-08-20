#include <cstdio>
#include <cstring>

#include <Bull/Core/Exception/FileNotFound.hpp>
#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/FileSystem/FileImpl.hpp>
#include <Bull/Core/FileSystem/Path.hpp>

namespace Bull
{
    void File::create(const String& name)
    {
        prv::FileImpl::create(name);
    }

    bool File::exists(const String& name)
    {
        return prv::FileImpl::exists(name);
    }

    bool File::copy(const Path& path, const String& newPath)
    {
        return prv::FileImpl::copy(path, newPath);
    }

    void File::rename(const Path& name, const String& newName)
    {
        Expect(File::exists(name.toString()), Throw(InvalidParameter, "File::rename", "The file to rename does not exists"));
        Expect(!File::exists(newName), Throw(InvalidParameter, "File::rename", "A file with the new name already exists"));

        Expect(::rename(name.toString().getBuffer(), newName.getBuffer()) != 0, Throw(InternalError, "File::rename", "Failed to rename file"));
    }

    void File::remove(const Path& name)
    {
        prv::FileImpl::remove(name);
    }

    File::~File()
    {
        flush();
    }

    ByteArray File::read(std::size_t length)
    {
        return m_impl->read(length);
    }

    std::size_t File::write(const ByteArray& bytes)
    {
        return m_impl->write(bytes);
    }

    void File::skip(std::size_t length)
    {
        read(length);
    }

    bool File::isAtEnd() const
    {
        return getCursor() >= getSize();
    }

    void File::flush()
    {
        m_impl->flush();
    }

    DateTime File::getCreationDate() const
    {
        return m_impl->getCreationDate();
    }

    DateTime File::getLastAccessDate() const
    {
        return m_impl->getLastAccessDate();
    }

    DateTime File::getLastWriteDate() const
    {
        return m_impl->getLastWriteDate();
    }

    std::size_t File::getCursor() const
    {
        return m_impl->getCursor();
    }

    std::size_t File::moveCursor(Int64 offset)
    {
        return m_impl->moveCursor(offset);
    }

    std::size_t File::setCursor(std::size_t position)
    {
        return m_impl->setCursor(position);
    }

    std::size_t File::getSize() const
    {
        return m_impl->getSize();
    }

    File::File(const String& path, Uint32 mode)
    {
        Expect(File::exists(path) || mode != FileOpeningMode_Read, Throw(FileNotFound, "File::File", "The file " + path + " does not exists"))

        m_path = path;
        m_mode = mode;
        m_impl = prv::FileImpl::createInstance(m_path, m_mode);

        if(mode & FileOpeningMode_Read)
        {
            setCursor(0);
        }
    }
}
