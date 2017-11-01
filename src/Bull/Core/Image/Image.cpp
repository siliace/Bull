#include <Bull/Core/Image/Image.hpp>
#include <Bull/Core/Image/ImageLoader.hpp>
#include <Bull/Core/Image/ImageSaver.hpp>
#include <Bull/Core/Resource/Registrar.hpp>

namespace Bull
{
    namespace
    {
        SaverRegistrar<prv::ImageSaver, Image::Saver> saverRegistrar;
        LoaderRegistrar<prv::ImageLoader, Image::Loader> loaderRegistrar;
    }

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
        if(size.x() && size.y())
        {
            std::size_t pixelsCount = size.x() * size.y() * 4;

            m_size   = size;
            m_pixels = pixels;

            if(m_pixels.getCapacity() != pixelsCount)
            {
                m_pixels.resize(pixelsCount);
            }

            return true;
        }

        return false;
    }

    Image& Image::fill(const Color &color)
    {
        for(std::size_t i = 0; i < m_pixels.getCapacity() / 4; i++)
        {
            m_pixels[i * 4 + 0] = color.red;
            m_pixels[i * 4 + 1] = color.green;
            m_pixels[i * 4 + 2] = color.blue;
            m_pixels[i * 4 + 3] = color.alpha;
        }

        return (*this);
    }

    Image& Image::flipVertically()
    {
        ByteArray pixels(m_size.x() * m_size.y() * 4);

        for(unsigned int i = 0; i < m_size.y() ; i++)
        {
            std::memcpy(&m_pixels[i * m_size.x()], &pixels[m_size.x() * (m_size.y() - i - 1) * 4], m_size.y());
        }

        m_pixels = pixels;

        return (*this);
    }

    Image& Image::flipHorizontally()
    {
        ByteArray pixels(m_size.x() * m_size.y() * 4);

        for(unsigned int i = 0; i < m_size.y() ; i++)
        {
            std::memcpy(&m_pixels[i * m_size.y()], &pixels[m_size.y() * (m_size.x() - i - 1) * 4], m_size.x());
        }

        m_pixels = pixels;

        return (*this);
    }

    bool Image::loadFromPath(const Path& path, const ImageParameters& parameters)
    {
        return Loader::get()->loadFromPath(this, path, parameters);
    }

    bool Image::loadFromStream(InStream& stream, const ImageParameters& parameters)
    {
        return Loader::get()->loadFromStream(this, stream, parameters);
    }

    bool Image::loadFromMemory(const void* data, std::size_t length, const ImageParameters& parameters)
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

    bool Image::saveToMemory(void* data, std::size_t length, const ImageParameters& parameters) const
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
