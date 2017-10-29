#ifndef BULL_GRAPHICS_MATERIAL_HPP
#define BULL_GRAPHICS_MATERIAL_HPP

#include <array>

#include <Bull/Core/Utility/Color.hpp>

#include <Bull/Graphics/Export.hpp>
#include <Bull/Graphics/Model/TextureType.hpp>

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
        Material& setTexture(const TextureRef& texture, TextureType type);

        /*! \brief Get a Texture
         *
         * \param type The type of the Texture
         *
         * \return The texture
         *
         */
        const TextureRef& getTexture(TextureType type) const;

    private:

        std::array<TextureRef, 7> m_textures;
        float                     m_shininess;
        Color                     m_ambientColor;
        Color                     m_diffuseColor;
        Color                     m_specularColor;
        float                     m_alphaThreshold;
    };
}

#endif // BULL_GRAPHICS_MATERIAL_HPP
