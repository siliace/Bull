#include <Bull/Graphics/Model/Material.hpp>

namespace Bull
{
    Material::Material() :
        m_shininess(0.f)
    {
        /// Nothing
    }

    Material& Material::setShininess(float shininess)
    {
        m_shininess = shininess;

        return (*this);
    }

    float Material::getShininess() const
    {
        return m_shininess;
    }

    Material& Material::setTexture(const Texture* texture, TextureType type)
    {
        m_textures[type] = texture;

        return (*this);
    }

    const Texture* Material::getTexture(TextureType type) const
    {
        return m_textures[type];
    }
}