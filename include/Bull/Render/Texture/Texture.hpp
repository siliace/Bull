#ifndef BULL_RENDER_TEXTURE_TEXTURE_HPP
#define BULL_RENDER_TEXTURE_TEXTURE_HPP

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Math/Polygon/Rectangle.hpp>
#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Render/Context/ContextResource.hpp>
#include <Bull/Render/OpenGL.hpp>

#include <Bull/Utility/Image/Image.hpp>

namespace Bull
{
    class BULL_RENDER_API Texture : public ContextResource, public NonCopyable
    {
    public:

        enum Sampler : unsigned int
        {
            Sampler0  = 0,
            Sampler1  = 1,
            Sampler2  = 2,
            Sampler3  = 3,
            Sampler4  = 4,
            Sampler5  = 5,
            Sampler6  = 6,
            Sampler7  = 7,
            Sampler8  = 8,
            Sampler9  = 9,
            Sampler10 = 10,
            Sampler11 = 11,
            Sampler12 = 12,
            Sampler13 = 13,
            Sampler14 = 14,
            Sampler15 = 15,
            Sampler16 = 16,
            Sampler17 = 17,
            Sampler18 = 18,
            Sampler19 = 19,
            Sampler20 = 20,
            Sampler21 = 21,
            Sampler22 = 22,
            Sampler23 = 23,
            Sampler24 = 24,
            Sampler25 = 25,
            Sampler26 = 26,
            Sampler27 = 27,
            Sampler28 = 28,
            Sampler29 = 29,
            Sampler30 = 30,
            Sampler31 = 31,
        };

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
         * \param size The size of the texture to create
         *
         * \return Return true if the texture was created successfully, false otherwise
         *
         */
        bool create(const Vector2UI& size);

        /*! \brief Load a texture form an image
         *
         * \param path The image to load
         *
         * \return Return true if the texture was loaded successfully, false otherwise
         *
         */
        bool create(const Image& image);

        /*! \brief Load a Resource from a Path
         *
         * \param path       The path
         * \param parameters Parameters to create the resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        bool loadFromPath(const Path& path, const ImageParameterBag& parameters = ImageParameterBag());

        /*! \brief Load a Resource from a Path
         *
         * \param stream     The stream to read to load
         * \param parameters Parameters to create the resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        bool loadFromStream(InStream& stream, const ImageParameterBag& parameters = ImageParameterBag());

        /*! \brief Load a Resource from a memory area
         *
         * \param data       The memory
         * \param length     The length of data
         * \param parameters Parameters to create the resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        bool loadFromMemory(const void* data, Index length, const ImageParameterBag& parameters = ImageParameterBag());

        /*! \brief Bind the texture
         *
         */
        void bind() const;

        /*! \brief Set the Sampler of the Texture
         *
         * \param sampler The Sampler to use
         *
         */
        void setSampler(Sampler sampler);

        /*! \brief Get the Sampler used by the texture
         *
         * \return The Sampler
         *
         */
        Sampler getSampler() const;

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
        Sampler      m_sampler;
        bool         m_isSmooth;
        bool         m_isRepeated;
    };
}

#endif // BULL_RENDER_TEXTURE_TEXTURE_HPP
