#include <Bull/Graphics/Light/SpotLight.hpp>

namespace Bull
{
    SpotLight::SpotLight() :
        SpotLight(Vector3F::Zero, Vector3F::Zero)
    {
        /// Nothing
    }

    SpotLight::SpotLight(const Vector3F& position, const Vector3F& direction, const Color& color) :
        AbstractLight(LightType_Spot),
        m_position(position),
        m_direction(direction)
    {
        setColor(color);
        m_constant    = 1.f;
        m_linear      = 0.09f;
        m_quadratic   = 0.0032f;
        m_innerCutOff = AngleF::degree(12.5f);
        m_outerCutOff = AngleF::degree(17.5f);
    }

    void SpotLight::setUniforms(Shader& shader, const String& name) const
    {
        AbstractLight::setUniforms(shader, name);

        shader.setUniform(compose(name, "linear"), m_linear);
        shader.setUniform(compose(name, "constant"), m_constant);
        shader.setUniform(compose(name, "quadratic"), m_quadratic);
        shader.setUniformVector(compose(name, "position"), m_position);
        shader.setUniformVector(compose(name, "direction"), m_direction);
        shader.setUniform(compose(name, "innerCutOff"), std::cos(m_innerCutOff));
        shader.setUniform(compose(name, "outerCutOff"), std::cos(m_outerCutOff));
    }

    void SpotLight::setLinear(float linear)
    {
        m_linear = linear;
    }

    float SpotLight::getLinear() const
    {
        return m_linear;
    }

    void SpotLight::setConstant(float constant)
    {
        m_constant = constant;
    }

    float SpotLight::getConstant() const
    {
        return m_constant;
    }

    void SpotLight::setPosition(const Vector3F& position)
    {
        m_position = position;
    }

    const Vector3F& SpotLight::getPosition() const
    {
        return m_position;
    }

    void SpotLight::setDirection(const Vector3F& direction)
    {
        m_direction = direction;
    }

    const Vector3F& SpotLight::getDirection() const
    {
        return m_direction;
    }

    void SpotLight::setQuadratic(float quadratic)
    {
        m_quadratic = quadratic;
    }

    float SpotLight::getQuadratic() const
    {
        return m_quadratic;
    }

    void SpotLight::setInnerCutOff(const AngleF& innerCutOff)
    {
        m_innerCutOff = innerCutOff;
    }

    const AngleF& SpotLight::getInnerCutOff() const
    {
        return m_innerCutOff;
    }

    void SpotLight::setOuterCutOff(const AngleF& outerCutOff)
    {
        m_outerCutOff = outerCutOff;
    }

    const AngleF& SpotLight::getOuterCutOff() const
    {
        return m_outerCutOff;
    }
}