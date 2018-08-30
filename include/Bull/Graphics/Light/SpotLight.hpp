#ifndef BULL_GRAPHICS_LIGHT_SPOTLIGHT_HPP
#define BULL_GRAPHICS_LIGHT_SPOTLIGHT_HPP

#include <Bull/Graphics/Light/AbstractLight.hpp>

#include <Bull/Math/Vector/Vector3.hpp>

namespace Bull
{
    class BULL_GRAPHICS_API SpotLight : public AbstractLight
    {
    public:

        /*! \brief Default constructor
         *
         */
        SpotLight();

        /*! \brief Constructor
         *
         * \param position  The position
         * \param direction The direction
         * \param color     The Color emitted
         *
         */
        SpotLight(const Vector3F& position, const Vector3F& direction, const Color& color = Color::White);

        /*! \brief Send uniforms values to a Shader
         *
         * \param shader The Shader
         * \param name   The name of the uniform
         *
         */
        void setUniforms(Shader& shader, const String& name) const override;

        inline float getLinear() const
        {
            return m_linear;
        }

        inline void setLinear(float linear)
        {
            m_linear = linear;
        }

        inline float getConstant() const
        {
            return m_constant;
        }

        inline void setConstant(float constant)
        {
            m_constant = constant;
        }

        inline const Vector3F& getPosition() const
        {
            return m_position;
        }

        inline void setPosition(const Vector3F& position)
        {
            m_position = position;
        }

        inline const Vector3F& getDirection() const
        {
            return m_direction;
        }

        inline void setDirection(const Vector3F& direction)
        {
            m_direction = direction;
        }

        inline float getQuadratic() const
        {
            return m_quadratic;
        }

        inline void setQuadratic(float quadratic)
        {
            m_quadratic = quadratic;
        }

        inline const AngleF& getInnerCutOff() const
        {
            return m_innerCutOff;
        }

        inline void setInnerCutOff(const AngleF& innerCutOff)
        {
            m_innerCutOff = innerCutOff;
        }

        inline const AngleF& getOuterCutOff() const
        {
            return m_outerCutOff;
        }

        inline void setOuterCutOff(const AngleF& outerCutOff)
        {
            m_outerCutOff = outerCutOff;
        }

    private:

        float    m_linear;
        float    m_constant;
        Vector3F m_position;
        Vector3F m_direction;
        float    m_quadratic;
        AngleF   m_innerCutOff;
        AngleF   m_outerCutOff;
    };
}

#endif // BULL_GRAPHICS_LIGHT_SPOTLIGHT_HPP
