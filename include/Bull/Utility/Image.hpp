#ifndef Bull_Image_hpp
#define Bull_Image_hpp

#include <vector>

#include <Bull/Core/Integer.hpp>
#include <Bull/Core/System/Export.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Render/Color.hpp>

namespace Bull
{
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

    public:

        /*! \brief Default constructor
         *
         */
        Image() = default;

        /*! \brief Constructor
         *
         * \param pixels Pixels of the image
         * \param size   The size of the image
         *
         */
        Image(const std::vector<Uint8>& pixels, const Vector2UI size);

        /*! \brief Constructor
         *
         * \param pixels Pixels of the image
         * \param width  The width of the image to create
         * \param height The height of the image to create
         *
         */
        Image(const std::vector<Uint8>& pixels, unsigned int width, unsigned int height);

        /*! \brief Constructor
         *
         * \param size  The size of the image
         * \param color The color to fill the image
         *
         */
        Image(const Vector2UI& size, const Color& color = Color::Black);

        /*! \brief Constructor
         *
         * \param width  The width of the image to create
         * \param height The height of the image to create
         * \param color  The color to fill the image
         *
         */
        Image(unsigned int width, unsigned int height, const Color& color = Color::Black);

        /*! \brief Load an image from a file
         *
         * \param path The path to the image to load
         *
         * \return Return true if the image was loaded successfully, false otherwise
         *
         */
        bool load(const String& path);

        /*! \brief Set the color of a pixel
         *
         * \param x
         * \param y
         * \param color
         *
         */
        void set(unsigned int x, unsigned int y, const Color& color);

        /*! \brief Get the color of a pixel
         *
         * \param x
         * \param y
         *
         * \return Return the color
         *
         */
        Color get(unsigned int x, unsigned int y) const;

        /*! \brief Get the size of the image
         *
         * \return Return the size
         *
         */
        const Vector2UI& getSize() const;

        /*! \brief Get pixels of the image
         *
         * \return Return pixels
         *
         */
        const std::vector<Uint8>& getPixels() const;

        /*! \brief Save the image
         *
         * \param path
         * \param format
         *
         * \return Return
         *
         */
        bool save(const String& path, Format format);

    private:

        std::vector<Uint8> m_pixels;
        Vector2UI          m_size;
    };
}

#endif // Bull_Image_hpp
