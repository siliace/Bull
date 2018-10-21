#ifndef BULL_GRAPHICS_MATERIAL_HPP
#define BULL_GRAPHICS_MATERIAL_HPP

#include <map>
#include <memory>

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
         */
        void setShininess(float shininess);

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
         */
        void setTexture(const std::shared_ptr<Texture>& texture, TextureType type);

        /*! \brief Get a Texture
         *
         * \param type The type of the Texture
         *
         * \return The texture
         *
         */
        const Texture* getTexture(TextureType type) const;

    private:

        std::map<TextureType, std::shared_ptr<Texture>> m_textures;
        float                                           m_shininess;
        Color                                           m_ambientColor;
        Color                                           m_diffuseColor;
        Color                                           m_specularColor;
        float                                           m_alphaThreshold;
    };
}

#endif // BULL_GRAPHICS_MATERIAL_HPP
