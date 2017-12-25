#include <Bull/Graphics/Light/AbstractLight.hpp>

namespace Bull
{
    LightType AbstractLight::getType() const
    {
        return m_type;
    }

    void AbstractLight::setAmbiantFactor(float ambient)
    {
        m_ambient = ambient;
    }

    float AbstractLight::getAmbiantFactor() const
    {
        return m_ambient;
    }

    void AbstractLight::setDiffuseFactor(float diffuse)
    {
        m_diffuse = diffuse;
    }

    float AbstractLight::getDiffuseFactor() const
    {
        return m_diffuse;
    }

    void AbstractLight::setColor(const Color& color)
    {
        m_color = color;
    }

    const Color& AbstractLight::getColor() const
    {
        return m_color;
    }

    AbstractLight::AbstractLight(LightType type) :
        m_type(type)
    {
        setDiffuseFactor(1.f);
        setAmbiantFactor((type == LightType_Directional) ? 0.2f : 0.f);
    }
}