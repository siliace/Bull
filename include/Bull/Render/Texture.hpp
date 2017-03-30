#ifndef Bull_Texture_hpp
#define Bull_Texture_hpp

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Math/Polygon/Rectangle.hpp>
#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Utility/Image.hpp>

#include <Bull/Window/ContextResource.hpp>

namespace Bull
{
    class Texture : public ContextResource, public NonCopyable
    {
    public:

        /*! \brief Default constructor
         *
         */
        Texture();

        /*! \brief Destructor
         *
         */
        ~Texture();

        /*! \brief Create an empty texture
         *
         * \param width  The width of the texture to create
         * \param height The height of the texture to create
         *
         * \return Return true if the texture was created successfully, false otherwise
         *
         */
        bool create(unsigned int width, unsigned int height);

        /*! \brief Create an empty texture
         *
         * \param size The size of the texture to create
         *
         * \return Return true if the texture was created successfully, false otherwise
         *
         */
        bool create(const Vector2UI& size);

        /*! \brief Load a texture form a file
         *
         * \param path The path to the image to load
         *
         * \return Return true if the texture was loaded successfully, false otherwise
         *
         */
        bool loadFromPath(const Path& path);

        /*! \brief Load a texture form an image
         *
         * \param path The image to load
         *
         * \return Return true if the texture was loaded successfully, false otherwise
         *
         */
        bool loadFromImage(const Image& image);

        /*! \brief Load a texture form a pixels array
         *
         * \param path The pixels array to load
         *
         * \return Return true if the texture was loaded successfully, false otherwise
         *
         */
        bool loadFromPixels(const std::vector<Uint8>& pixels, const Vector2UI& size);

        /*! \brief Bind the texture
         *
         * @param sampler The sampler to use to bind the buffer
         *
         */
        void bind(Uint8 sampler = 0) const;

        /*! \brief Enable or disable the texture repeat
         *
         * \param enable True to enable, false to disable
         *
         */
        void enableRepeat(bool enable = true);

        /*! \brief Check whether the texture repeat is enable
         *
         * \return Return true if the texture repeat is enable, false otherwise
         *
         */
        bool isEnableRepeat() const;

        /*! \brief Enable or disable the texture smooth
         *
         * \param enable True to enable, false to disable
         *
         */
        void enableSmooth(bool enable = true);

        /*! \brief Check whether the texture smooth is enable
         *
         * \return Return true if the texture smooth is enable, false otherwise
         *
         */
        bool isEnableSmooth() const;

        /*! \brief Get the size of the texture
         *
         * \return Return the size of the texture
         *
         */
        const Vector2UI& getSize() const;

        /*! \brief Download the texture from the VRAM
         *
         * \return Return return the image
         *
         */
        Image getImage() const;

        /*! \brief Download the texture from the VRAM
         *
         * \param rectangle The rectangle to use to crop the texture
         *
         * \return Return return the image
         *
         */
        Image getImage(const RectangleUI& rectangle) const;

        /*! \brief Get the Texture system handler
         *
         * \return The native Texture system handler
         *
         */
        unsigned int getSystemHandler() const;

    private:

        unsigned int m_id;
        Vector2UI    m_size;
        bool         m_isSmooth;
        bool         m_isRepeated;
    };
}

#endif // Bull_Texture_hpp
