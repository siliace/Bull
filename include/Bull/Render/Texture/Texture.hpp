#ifndef BULL_RENDER_TEXTURE_TEXTURE_HPP
#define BULL_RENDER_TEXTURE_TEXTURE_HPP

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/Image/Image.hpp>
#include <Bull/Core/Image/ImageParameters.hpp>
#include <Bull/Core/Pattern/RefCounted.hpp>

#include <Bull/Math/Polygon/Rectangle.hpp>
#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Render/Context/ContextResource.hpp>

namespace Bull
{
    class BULL_RENDER_API Texture : public ContextResource, public RefCounted<Texture>, public AbstractImage
    {
    public:

        /*! \brief Get the maximum size of a Texture
         *
         * \return The size
         *
         */
        static unsigned int getMaximumSize();

    public:

        /*! \brief Default constructor
         *
         */
        Texture();

        /*! \brief Destructor
         *
         */
        virtual ~Texture();

        /*! \brief Load a Texture form an Image
         *
         * \param image The Image to load
         *
         * \return True if the Texture was loaded successfully
         *
         */
        bool create(const Image& image);

        /*! \brief Create an empty Texture
         *
         * \param size The size of the Texture to create
         *
         * \return True if the Texture was created successfully
         *
         */
        bool create(const Vector2UI& size) override;

        /*! \brief Create a Texture
         *
         * \param pixels Pixels of the Texture
         * \param size   The size of the Texture
         *
         * \return True if the Texture was created successfully
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
        
        /*! \brief Bind the Texture
         *
         */
        void bind() const;

        /*! \brief Enable or disable the Texture repeat
         *
         * \param enable True to enable, false to disable
         *
         */
        void enableRepeat(bool enable = true);

        /*! \brief Check whether the Texture repeat is enable
         *
         * \return Return true if the Texture repeat is enable, false otherwise
         *
         */
        inline bool isEnableRepeat() const;

        /*! \brief Enable or disable the Texture smooth
         *
         * \param enable True to enable, false to disable
         *
         */
        void enableSmooth(bool enable = true);

        /*! \brief Check whether the Texture smooth is enable
         *
         * \return Return true if the Texture smooth is enable, false otherwise
         *
         */
        inline bool isEnableSmooth() const;

        /*! \brief Download the Texture from the VRAM
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
