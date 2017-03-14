#include <Bull/Core/FileSystem/File.hpp>

#include <Bull/Utility/Image.hpp>
#include <Bull/Utility/ImageLoader.hpp>

namespace Bull
{
    Image::Image(const std::vector<Uint8>& pixels, const Vector2UI& size) :
        m_size(size),
        m_pixels(pixels)
    {
        /// Nothing
    }

    Image::Image(const void* data, const Vector2UI& size)
    {
        loadFromBuffer(data, size);
    }

    Image::Image(const std::vector<Uint8>& pixels, unsigned int width, unsigned int height) :
        Image(pixels, Vector2UI(width, height))
    {
        /// Nothing
    }

    Image::Image(const void* data, unsigned int width, unsigned int height) :
        Image(data, Vector2UI(width, height))
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
        for(unsigned int i = 0; i < m_pixels.size(); i += 4)
        {
            m_pixels[i]     = color.red;
            m_pixels[i + 1] = color.green;
            m_pixels[i + 2] = color.blue;
            m_pixels[i + 3] = color.alpha;
        }
    }

    bool Image::loadFromPath(const Path& path)
    {
        if(path)
        {
            return prv::ImageLoader::load(path, m_pixels, m_size);
        }

        return false;
    }

    bool Image::loadFromBuffer(const void* data, const Vector2UI& size)
    {
        if(data)
        {
            m_size   = size;
            m_pixels = std::vector<Uint8>(static_cast<const Uint8*>(data), static_cast<const Uint8*>(data) + size.x * size.y * 4);

            return true;
        }

        return false;
    }

    bool Image::loadFromBuffer(const void* data, unsigned int width, unsigned int height)
    {
        return loadFromBuffer(data, Vector2UI(width, height));
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

    const std::vector<Uint8>& Image::getPixels() const
    {
        return m_pixels;
    }

    bool Image::save(const String& path, Format format)
    {
        if(!File::exists(path) && m_pixels.size() > 0)
        {
            return prv::ImageLoader::save(path, format, m_pixels, m_size);
        }

        return false;
    }
}
