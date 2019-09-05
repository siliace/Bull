#ifndef BULL_GRAPHICS_LIGHT_SPOTLIGHT_HPP
#define BULL_GRAPHICS_LIGHT_SPOTLIGHT_HPP

#include <Bull/Graphics/Light/AbstractLight.hpp>

#include <Bull/Math/Vector/Vector3.hpp>

namespace Bull
{
    class BULL_GRAPHICS_API SpotLight : public AbstractLight
    {
    public:

        /** \brief Default constructor
         *
         */
        SpotLight();

        /** \brief Constructor
         *
         * \param position  The position
         * \param direction The direction
         * \param color     The Color emitted
         *
         */
        SpotLight(const Vector3F& position, const Vector3F& direction, const Color& color = Color::White);

        /** \brief Send uniforms values to a Shader
         *
         * \param shader The Shader
         * \param name   The name of the uniform
         *
         */
        void setUniforms(Shader& shader, const std::string& name) const override;

        /** \brief Set the linear attenuation factor of the SpotLight
         *
         * \param linear The linear attenuation factor
         *
         */
        void setLinear(float linear);

        /** \brief Get the linear attenuation factor of the SpotLight
         *
         * \return The linear attenuation factor
         *
         */
        float getLinear() const;

        /** \brief Set the constant attenuation factor of the SpotLight
         *
         * \param constant The constant attenuation factor
         *
         */
        void setConstant(float constant);

        /** \brief Get the constant attenuation factor of the SpotLight
         *
         * \return The constant attenuation factor
         *
         */
        float getConstant() const;

        /** \brief Set the position of the SpotLight
         *
         * \param position The position
         *
         */
        void setPosition(const Vector3F& position);

        /** \brief Get the position of the SpotLight
         *
         * \return The position
         *
         */
        const Vector3F& getPosition() const;

        /** \brief Set the direction of the SpotLight
         *
         * \param direction The direction
         *
         */
        void setDirection(const Vector3F& direction);

        /** \brief Get the direction of the SpotLight
         *
         * \return The direction
         *
         */
        const Vector3F& getDirection() const;

        /** \brief Set the quadratic attenuation factor of the SpotLight
         *
         * \param quadratic The quadratic attenuation factor
         *
         */
        void setQuadratic(float quadratic);

        /** \brief Get the quadratic attenuation factor of the SpotLight
         *
         * \return The quadratic attenuation factor
         *
         */
        float getQuadratic() const;

        /** \brief Get the inner cut off angle of the SpotLight
         *
         * \param innerCutOff The inner cut off angle
         *
         */
        void setInnerCutOff(const AngleF& innerCutOff);

        /** \brief Get the inner cut off angle of the SpotLight
         *
         * \return The outer cut off angle
         *
         */
        const AngleF& getInnerCutOff() const;

        /** \brief Get the outer cut off angle of the SpotLight
         *
         * \param outerCutOff The outer cut off angle
         *
         */
        void setOuterCutOff(const AngleF& outerCutOff);

        /** \brief Get the outer cut off angle of the SpotLight
         *
         * \return The outer cut off angle
         *
         */
        const AngleF& getOuterCutOff() const;

    private:

        float m_linear;
        float m_constant;
        Vector3F m_position;
        Vector3F m_direction;
        float m_quadratic;
        AngleF m_innerCutOff;
        AngleF m_outerCutOff;
    };
}

#endif // BULL_GRAPHICS_LIGHT_SPOTLIGHT_HPP
