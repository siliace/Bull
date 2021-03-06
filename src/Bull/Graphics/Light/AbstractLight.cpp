#include <Bull/Graphics/Light/AbstractLight.hpp>

namespace Bull
{
    std::string AbstractLight::compose(const std::string& base, const std::string& member)
    {
        return base + "." + member;
    }

    LightType AbstractLight::getType() const
    {
        return m_type;
    }

    void AbstractLight::setAmbientFactor(float ambient)
    {
        m_ambient = ambient;
    }

    float AbstractLight::getAmbientFactor() const
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
        setAmbientFactor(0.2f);
    }

    void AbstractLight::setUniforms(Shader& shader, const std::string& name) const
    {
        shader.setUniformVector(compose(name, "ambient"), Vector4F::makeFromColor(m_color) * m_ambient);
        shader.setUniformVector(compose(name, "diffuse"), Vector4F::makeFromColor(m_color) * m_diffuse);
        shader.setUniformVector(compose(name, "specular"), Vector4F::makeFromColor(m_color));
    }
}