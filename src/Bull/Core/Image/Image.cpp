#include <Bull/Core/Image/Image.hpp>

namespace Bull
{
    bool Image::create(const Vector2UI& size)
    {
        if(size.x() && size.y())
        {
            m_size   = size;
            m_pixels = ByteArray(m_size.x() * m_size.y() * 4);

            return true;
        }

        return false;
    }

    bool Image::create(const ByteArray& pixels, const Vector2UI& size)
    {
        if(size.x() && size.y() && pixels.getCapacity() == size.x() * size.y() * 4)
        {
            m_size   = size;
            m_pixels = pixels;

            return true;
        }

        return false;
    }

    bool Image::loadFromPath(const Path& path, const ImageParameters& parameters)
    {
        return Loader::get()->loadFromPath(this, path, parameters);
    }

    bool Image::loadFromStream(InStream& stream, const ImageParameters& parameters)
    {
        return Loader::get()->loadFromStream(this, stream, parameters);
    }

    bool Image::loadFromMemory(const void* data, Index length, const ImageParameters& parameters)
    {
        return Loader::get()->loadFromMemory(this, data, length, parameters);
    }

    bool Image::saveToPath(const Path& path, const ImageParameters& parameters) const
    {
        return Saver::get()->saveToPath(this, path, parameters);
    }

    bool Image::saveToStream(OutStream& stream, const ImageParameters& parameters) const
    {
        return Saver::get()->saveToStream(this, stream, parameters);
    }

    bool Image::saveToMemory(void* data, Index length, const ImageParameters& parameters) const
    {
        return Saver::get()->saveToMemory(this, data, length, parameters);
    }

    const Vector2UI& Image::getSize() const
    {
        return m_size;
    }

    const ByteArray& Image::getPixels() const
    {
        return m_pixels;
    }
}
