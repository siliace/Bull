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

    void Material::setTexture(const Asset<Texture>& texture, TextureType type)
    {
        m_textures[type] = texture;
    }

    const Texture* Material::getTexture(TextureType type) const
    {
        auto iterator = m_textures.find(type);

        if(iterator != m_textures.end())
        {
            return iterator->second.get();
        }

        return nullptr;
    }
}