#ifndef BULL_GRAPHICS_LIGHT_POINTLIGHT_HPP
#define BULL_GRAPHICS_LIGHT_POINTLIGHT_HPP

#include <Bull/Graphics/Light/AbstractLight.hpp>

#include <Bull/Math/Vector/Vector3.hpp>

namespace Bull
{
    class BULL_GRAPHICS_API PointLight : public AbstractLight
    {
    public:

        /** \brief Default constructor
         *
         */
        PointLight();

        /** \brief Constructor
         *
         * \param position The position of the PointLight
         * \param color    The color of the PointLight
         *
         */
        explicit PointLight(const Vector3F& position, const Color& color = Color::White);

        /** \brief Set the attenuation of the PointLight
         *
         * \param constant
         * \param linear
         * \param quadratic
         *
         */
        void setAttenuation(float constant, float linear, float quadratic);

        /** \brief Send uniforms values to a Shader
         *
         * \param shader The Shader
         * \param name   The name of the uniform
         *
         */
        void setUniforms(Shader& shader, const std::string& name) const override;

        /** \brief Set the position of the PointLight
         *
         * \param position The position
         *
         */
        void setPosition(const Vector3F& position);

        /** \brief Get the position of the PointLight
         *
         * \return The position
         *
         */
        const Vector3F& getPosition() const;

    private:

        float m_linear;
        float m_constant;
        Vector3F m_position;
        float m_quadratic;
    };
}

#endif // BULL_GRAPHICS_LIGHT_POINTLIGHT_HPP
