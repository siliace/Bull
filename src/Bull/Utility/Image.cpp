#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/System/Config.hpp>

#include <Bull/Utility/Image.hpp>
#include <Bull/Utility/ImageLoader.hpp>

std::unique_ptr<Bull::AbstractImageLoader> Bull::Image::loader = std::make_unique<IMAGE_LOADER>();

namespace Bull
{
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

    Image::Image(const std::vector<Uint8>& pixels, const Vector2UI& size) :
        m_size(size),
        m_pixels(pixels)
    {
        /// Nothing
    }

    Image::Image(const std::vector<Uint8>& pixels, unsigned int width, unsigned int height) :
        Image(pixels, Vector2UI(width, height))
    {
        /// Nothing
    }

    bool Image::loadFromPath(const Path& path)
    {
        return loader->loadFromPath(path, m_pixels, m_size);
    }

    bool Image::loadFromStream(InStream& stream)
    {
        return loader->loadFromStream(stream, m_pixels, m_size);
    }

    bool Image::loadFromMemory(const void* data, std::size_t dataSize)
    {
        return loader->loadFromMemory(data, dataSize, m_pixels, m_size);
    }

    bool Image::loadFromPixels(const std::vector<Uint8>& pixels, const Vector2UI& size)
    {
        m_size   = size;
        m_pixels = pixels;

        return true;
    }

    bool Image::loadFromPixels(const std::vector<Uint8>& pixels, unsigned int width, unsigned int height)
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

    const std::vector<Uint8>& Image::getPixels() const
    {
        return m_pixels;
    }

    bool Image::saveToPath(const Path& path, Format format) const
    {
        return loader->saveToPath(path, format, m_pixels, m_size);
    }

    bool Image::saveToMemory(OutStream& stream, Format format) const
    {
        return loader->saveToStream(stream, format, m_pixels, m_size);
    }

    bool Image::saveToSteam(void* data, std::size_t size, Format format) const
    {
        return loader->saveToMemory(data, size, format, m_pixels, m_size);
    }
}
