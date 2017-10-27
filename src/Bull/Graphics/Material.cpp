#include <Bull/Graphics/Material.hpp>

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

    Material& Material::setTexture(Texture::Ref texture, MaterialTextureType type)
    {
        m_textures[type] = std::move(texture);

        return (*this);
    }

    const Texture::Ref& Material::getTexture(MaterialTextureType type) const
    {
        return m_textures[type];
    }
}