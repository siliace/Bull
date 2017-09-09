#include <Bull/Core/FileSystem/File.hpp>

#include <Bull/Utility/Image/Image.hpp>
#include <Bull/Utility/Image/ImageLoader.hpp>

namespace Bull
{
    Image::Image()
    {
        /// Nothing
    }

    Image::Image(const Vector2UI& size, const Color& color) :
        Image(size.x, size.y, color)
    {
        /// Nothing
    }

    Image::Image(unsigned int width, unsigned int height, const Color& color) :
        m_size(width, height),
        m_pixels(width * height * 4)
    {
        for(unsigned int i = 0; i < m_pixels.getCapacity(); i += 4)
        {
            m_pixels[i]     = color.red;
            m_pixels[i + 1] = color.green;
            m_pixels[i + 2] = color.blue;
            m_pixels[i + 3] = color.alpha;
        }
    }

    Image::Image(const ByteArray& pixels, const Vector2UI& size) :
        m_size(size),
        m_pixels(pixels)
    {
        /// Nothing
    }

    Image::Image(const ByteArray& pixels, unsigned int width, unsigned int height) :
        Image(pixels, Vector2UI(width, height))
    {
        /// Nothing
    }

    bool Image::loadFromPath(const Path& path)
    {
        return prv::ImageLoader::get()->loadFromPath(path, m_pixels, m_size);
    }

    bool Image::loadFromStream(InStream& stream)
    {
        return prv::ImageLoader::get()->loadFromStream(stream, m_pixels, m_size);
    }

    bool Image::loadFromMemory(const void* data, Index length)
    {
        return prv::ImageLoader::get()->loadFromMemory(data, length, m_pixels, m_size);
    }

    bool Image::loadFromPixels(const ByteArray& pixels, const Vector2UI& size)
    {
        m_size   = size;
        m_pixels = pixels;

        return true;
    }

    bool Image::loadFromPixels(const ByteArray& pixels, unsigned int width, unsigned int height)
    {
        return loadFromPixels(pixels, Vector2UI(width, height));
    }

    void Image::set(unsigned int x, unsigned int y, const Color& color)
    {
        unsigned int position = x * y * 4;

        m_pixels[position]     = color.red;
        m_pixels[position + 1] = color.green;
        m_pixels[position + 2] = color.blue;
        m_pixels[position + 3] = color.alpha;
    }

    Color Image::get(unsigned int x, unsigned int y) const
    {
        unsigned int position = x * y * 4;

        Uint8 red   = m_pixels[position];
        Uint8 green = m_pixels[position + 1];
        Uint8 blue  = m_pixels[position + 2];
        Uint8 alpha = m_pixels[position + 3];

        return Color(red, green, blue, alpha);
    }

    const Vector2UI& Image::getSize() const
    {
        return m_size;
    }

    const ByteArray& Image::getPixels() const
    {
        return m_pixels;
    }

    bool Image::saveToPath(const Path& path, ImageFormat format) const
    {
        return prv::ImageLoader::get()->saveToPath(path, format, m_pixels, m_size);
    }

    bool Image::saveToMemory(OutStream& stream, ImageFormat format) const
    {
        return prv::ImageLoader::get()->saveToStream(stream, format, m_pixels, m_size);
    }

    bool Image::saveToSteam(void* data, Index length, ImageFormat format) const
    {
        return prv::ImageLoader::get()->saveToMemory(data, length, format, m_pixels, m_size);
    }
}
