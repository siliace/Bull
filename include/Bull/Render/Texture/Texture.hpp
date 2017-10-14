#ifndef BULL_RENDER_TEXTURE_TEXTURE_HPP
#define BULL_RENDER_TEXTURE_TEXTURE_HPP

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/Image/Image.hpp>
#include <Bull/Core/Image/ImageParameters.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Pattern/ObjectRef.hpp>

#include <Bull/Math/Polygon/Rectangle.hpp>
#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Render/Context/ContextResource.hpp>

namespace Bull
{
    class Texture;

    using TextureRef = ObjectRef<Texture>;
    using TexureConstRef = ObjectRef<const Texture>;

    class BULL_RENDER_API Texture : public ContextResource, public RefCounted, public AbstractImage
    {
    public:

        /*! \brief Make a new Texture
         *
         * \param args Arguments to create the Texture
         *
         * \return A reference to the new Texture
         *
         */
        template <typename... Args>
        static TextureRef make(Args&&... args);

    public:

        /*! \brief Default constructor
         *
         */
        Texture();

        /*! \brief Destructor
         *
         */
        ~Texture();

        /*! \brief Load a texture form an image
         *
         * \param path The image to load
         *
         * \return Return true if the texture was loaded successfully, false otherwise
         *
         */
        bool create(const Image& image);

        /*! \brief Create an empty texture
         *
         * \param size The size of the texture to create
         *
         * \return Return true if the texture was created successfully, false otherwise
         *
         */
        bool create(const Vector2UI& size) override;

        /*! \brief Create an empty texture
         *
         * \param size The size of the texture to create
         *
         * \return Return true if the texture was created successfully, false otherwise
         *
         */
        bool create(const ByteArray& pixels, const Vector2UI& size) override;

        /*! \brief Load a Texture from a Path
         *
         * \param path       The Path of the file to read
         * \param parameters Parameters to load the Texture
         *
         * \return True if the Texture was loaded successfully
         *
         */
        bool loadFromPath(const Path& path, const ImageParameters& parameters = ImageParameters()) override;

        /*! \brief Load a Texture from an InStream
         *
         * \param stream     The stream to read
         * \param parameters Parameters to load the Texture
         *
         * \return True if the Texture was loaded successfully
         *
         */
        bool loadFromStream(InStream& stream, const ImageParameters& parameters = ImageParameters()) override;

        /*! \brief Load a Texture from a memory area
         *
         * \param data       The memory area to read
         * \param length     The length of the memory area
         * \param parameters Parameters to load the Texture
         *
         * \return True if the Texture was loaded successfully
         *
         */
        bool loadFromMemory(const void* data, Index length, const ImageParameters& parameters = ImageParameters()) override;

        /*! \brief Save the Texture to a Path
         *
         * \param path       The path of the
         * \param parameters Parameters to save the Texture
         *
         * \return True if the Texture was saved successfully
         *
         */
        bool saveToPath(const Path& path, const ImageParameters& parameters = ImageParameters()) const override;

        /*! \brief Save the Texture to a stream
         *
         * \param stream     The stream to write
         * \param parameters Parameters to save the Texture
         *
         * \return True if the Texture was saved successfully
         *
         */
        bool saveToStream(OutStream& stream, const ImageParameters& parameters = ImageParameters()) const override;

        /*! \brief Save the Texture to a Path
         *
         * \param data       The memory to write
         * \param length     The length of the memory area
         * \param parameters Parameters to save the Texture
         *
         * \return True if the Texture was saved successfully
         *
         */
        bool saveToMemory(void* data, Index length, const ImageParameters& parameters = ImageParameters()) const override;
        
        /*! \brief Bind the texture
         *
         */
        void bind() const;

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
        inline bool isEnableRepeat() const;

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
        inline bool isEnableSmooth() const;

        /*! \brief Download the texture from the VRAM
         *
         * \return Return return the image
         *
         */
        Image getImage() const;

        /*! \brief Get the size of the Image
         *
         * \return The size
         *
         */
        inline const Vector2UI& getSize() const override;

    private:

        unsigned int m_id;
        Vector2UI    m_size;
        bool         m_isSmooth;
        bool         m_isRepeated;
    };
}

#include <Bull/Render/Texture/Texture.inl>

#endif // BULL_RENDER_TEXTURE_TEXTURE_HPP
