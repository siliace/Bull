#ifndef Bull_Texture_hpp
#define Bull_Texture_hpp

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/String.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Render/Context/ContextResource.hpp>
#include <Bull/Render/OpenGL.hpp>

#include <Bull/Utility/Image.hpp>

namespace Bull
{
    class Texture : public ContextResource, public NonCopyable
    {
    public:

        /*! \brief Bind a texture
         *
         * \param texture The texture to bind
         *
         */
        static void bind(const Texture& texture);

        /*! \brief Unbind any texture
         *
         */
        static void unbind();

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
        bool loadFromPath(const String& path);

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

        /*! \brief Get the system handler
         *
         * \return Return the native system texture handler
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
