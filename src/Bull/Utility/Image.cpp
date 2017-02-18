#include <Bull/Core/FileSystem/File.hpp>

#include <Bull/Utility/Image.hpp>
#include <Bull/Utility/ImageLoader.hpp>

namespace Bull
{
    Image::Image(const std::vector<Uint8>& pixels, const Vector2UI size) :
        m_pixels(pixels),
        m_size(size)
    {
        /// Nothing
    }

    Image::Image(const std::vector<Uint8>& pixels, unsigned int width, unsigned int height) :
        Image(pixels, Vector2UI(width, height))
    {
        /// Nothing
    }

    Image::Image(const Vector2UI& size, const Color& color) :
        Image(size.x, size.y, color)
    {
        /// Nothing
    }

    Image::Image(unsigned int width, unsigned int height, const Color& color) :
        m_pixels(width * height * 4),
        m_size(width, height)
    {
        for(unsigned int i = 0; i < m_pixels.size(); i += 4)
        {
            m_pixels[i]     = color.red;
            m_pixels[i + 1] = color.green;
            m_pixels[i + 2] = color.blue;
            m_pixels[i + 3] = color.alpha;
        }
    }

    bool Image::load(const String& path)
    {
        if(File::exists(path))
        {
            return prv::ImageLoader::load(path, m_pixels, m_size);
        }

        return false;
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
