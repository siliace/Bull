#include <Bull/Graphics/Model/Material.hpp>

namespace Bull
{
    Material::Material() :
        m_shininess(0.f)
    {
        /// Nothing
    }

    void Material::setShininess(float shininess)
    {
        m_shininess = shininess;
    }

    float Material::getShininess() const
    {
        return m_shininess;
    }

    void Material::setTexture(const Texture* texture, TextureType type)
    {
        m_textures[type] = texture;
    }

    const Texture* Material::getTexture(TextureType type) const
    {
        return m_textures[type];
    }
}