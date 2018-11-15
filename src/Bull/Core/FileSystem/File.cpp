#include <Bull/Core/Exception/FileNotFound.hpp>
#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/IO/TextReader.hpp>
#include <Bull/Core/IO/TextWriter.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/FileSystem/FileImpl.hpp>

namespace Bull
{
    void File::create(const Path& path)
    {
        prv::FileImpl::create(path);
    }

    bool File::exists(const Path& path)
    {
        return prv::FileImpl::exists(path);
    }

    void File::copy(const Path& path, const Path& newPath)
    {
        prv::FileImpl::copy(path, newPath);
    }

    void File::rename(const Path& path, const Path& newPath)
    {
        prv::FileImpl::rename(path, newPath);
    }

    void File::remove(const Path& name)
    {
        prv::FileImpl::remove(name);
    }

    File::File() :
        m_mode(0)
    {
        /// Nothing
    }

    File::File(const Path& path, Uint32 mode)
    {
        open(path, mode);
    }

    File::File(File&& file) noexcept
    {
        std::swap(m_path, file.m_path);
        std::swap(m_mode, file.m_mode);
        std::swap(m_impl, file.m_impl);
    }

    File::~File()
    {
        flush();
    }

    File& File::operator=(File&& file) noexcept
    {
        std::swap(m_path, file.m_path);
        std::swap(m_mode, file.m_mode);
        std::swap(m_impl, file.m_impl);

        return *this;
    }

    void File::open(const Path& path, Uint32 mode)
    {
        Expect(!path.isDirectory(), Throw(InvalidParameter, "The path " + path.toString() + " is not a file"));
        Expect(File::exists(path) || mode != FileOpeningMode_Read, Throw(FileNotFound, "The file " + path.toString() + " does not exists"));

        m_path = path;
        m_mode = mode;
        m_impl = prv::FileImpl::createInstance(m_path, m_mode);

        if(mode & FileOpeningMode_Read)
        {
            setCursor(0);
        }
    }

    ByteArray File::read(std::size_t length)
    {
        return m_impl->read(length);
    }

    std::size_t File::write(const ByteArray& bytes)
    {
        return m_impl->write(bytes);
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
}
