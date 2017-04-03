#ifndef BULL_UTILITY_IMAGE_HPP
#define BULL_UTILITY_IMAGE_HPP

#include <vector>

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/IO/InStream.hpp>
#include <Bull/Core/System/Integer.hpp>
#include <Bull/Core/System/Export.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Utility/Color.hpp>
#include <Bull/Core/IO/OutStream.hpp>

namespace Bull
{
    class AbstractImageLoader;

    class BULL_API Image
    {
    public:

        enum Format
        {
            Bmp,
            Jpg,
            Jpeg,
            Png,
            Tga
        };

        static std::unique_ptr<AbstractImageLoader> loader;

    public:

        /*! @brief Default constructor
         *
         */
        Image() = default;

        /*! @brief Constructor
         *
         * @param size  The size of the image
         * @param color The color to fill the image
         *
         */
        Image(const Vector2UI& size, const Color& color = Color::Black);

        /*! @brief Constructor
         *
         * @param pixels Pixels of the image
         * @param size   The size of the image
         *
         */
        Image(const std::vector<Uint8>& pixels, const Vector2UI& size);

        /*! @brief Constructor
         *
         * @param pixels Pixels of the image
         * @param width  The width of the image to create
         * @param height The height of the image to create
         *
         */
        Image(const std::vector<Uint8>& pixels, unsigned int width, unsigned int height);

        /*! @brief Constructor
         *
         * @param width  The width of the image to create
         * @param height The height of the image to create
         * @param color  The color to fill the image
         *
         */
        Image(unsigned int width, unsigned int height, const Color& color = Color::Black);

        /*! @brief Load an image from a file
         *
         * @param path The path to the image to load
         *
         * @return True if the image was loaded successfully
         *
         */
        bool loadFromPath(const Path& path);

        /*! @brief Load an image from memory
         *
         * @param data     Buffer which contains row data
         * @param dataSize The size of data
         *
         * @return True if the image was loaded successfully
         *
         */
        bool loadFromMemory(const void* data, std::size_t dataSize);

        /*! @brief Load an image from a stream
         *
         * @param stream The stream to read to load the image
         *
         * @return True if the image was created successfully
         *
         */
        bool loadFromStream(InStream& stream);

        /*! @brief Set the color of a pixel
         *
         * @param x
         * @param y
         * @param color
         *
         */
        void set(unsigned int x, unsigned int y, const Color& color);

        /*! @brief Get the color of a pixel
         *
         * @param x
         * @param y
         *
         * @return The color
         *
         */
        Color get(unsigned int x, unsigned int y) const;

        /*! @brief Get the size of the image
         *
         * @return Return the size
         *
         */
        const Vector2UI& getSize() const;

        /*! @brief Get pixels of the image
         *
         * @return Return pixels
         *
         */
        const std::vector<Uint8>& getPixels() const;

        /*! @brief Save the image
         *
         * @param path
         * @param format
         *
         * @return Return
         *
         */
        bool saveToPath(const Path& path, Format format) const;

        /*! @brief
         *
         * @param stream
         * @param format
         *
         * @return
         *
         */
        bool saveToMemory(OutStream& stream, Format format) const;

        /*! @brief
         *
         * @param data
         * @param size
         * @param format
         *
         * @return
         *
         */
        bool saveToSteam(void* data, std::size_t size, Format format) const;

    private:

        Vector2UI          m_size;
        std::vector<Uint8> m_pixels;
    };
}

#endif // BULL_UTILITY_IMAGE_HPP
