#ifndef BULL_GRAPHICS_MATERIAL_HPP
#define BULL_GRAPHICS_MATERIAL_HPP

#include <array>

#include <Bull/Graphics/Export.hpp>
#include <Bull/Graphics/TextureType.hpp>

#include <Bull/Render/Texture/Texture.hpp>

namespace Bull
{
    class BULL_GRAPHICS_API Material
    {
    public:

        /*! \brief Default constructor
         *
         */
        Material();

        /*! \brief Set the shininess of the Material
         *
         * \param shininess The shininess
         *
         * \return This
         *
         */
        Material& setShininess(float shininess);

        /*! \brief Get the shininess of the Material
         *
         * \return The shininess
         *
         */
        float getShininess() const;

        /*! \brief Set a Texture of the Material
         *
         * \param texture The texture
         * \param type    The type of the texture
         *
         * \return This
         *
         */
        Material& setTexture(TextureRef texture, TextureType::TextureType type);

        /*! \brief Get a Texture
         *
         * \param type The type of the Texture
         *
         * \return The texture
         *
         */
        const TextureRef& getTexture(TextureType::TextureType type) const;

    private:

        std::array<TextureRef, 4> m_textures;
        float                     m_shininess;
    };
}

#endif // BULL_GRAPHICS_MATERIAL_HPP
