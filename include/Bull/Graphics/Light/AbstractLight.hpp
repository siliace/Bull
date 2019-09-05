#ifndef BULL_GRAPHICS_LIGHT_ABSTRACTLIGHT_HPP
#define BULL_GRAPHICS_LIGHT_ABSTRACTLIGHT_HPP

#include <Bull/Graphics/Export.hpp>
#include <Bull/Graphics/Light/LightType.hpp>

#include <Bull/Render/Shader/Shader.hpp>

namespace Bull
{
    class BULL_GRAPHICS_API AbstractLight
    {
    protected:

        /** \brief Compose the name of a member
         *
         * \param base
         * \param uniform
         *
         * \return
         *
         */
        static std::string compose(const std::string& base, const std::string& uniform);

    public:

        /** \brief Get the type of the Light
         *
         * \return The type
         *
         */
        LightType getType() const;

        /** \brief Set the Light's Color
         *
         * \param color The Color
         *
         */
        void setColor(const Color& color);

        /** \brief Get the Light's Color
         *
         * \return The Color
         *
         */
        const Color& getColor() const;

        /** \brief Set the ambient factor of the Light
         *
         * \param ambient The ambient factor
         *
         */
        void setAmbientFactor(float ambient);

        /** \brief Get the ambient factor of the Light
         *
         * \return The ambient factor
         *
         */
        float getAmbientFactor() const;

        /** \brief Set the diffuse factor of the Light
         *
         * \param diffuse The ambient factor
         *
         */
        void setDiffuseFactor(float diffuse);

        /** \brief Get the diffuse factor of the Light
         *
         * \return The diffuse factor
         *
         */
        float getDiffuseFactor() const;

    protected:

        /** \brief Constructor
         *
         * \param type The type of the Light
         *
         */
        explicit AbstractLight(LightType type);

        /** \brief Send uniforms values to a Shader
         *
         * \param shader The Shader
         * \param name   The name of the uniform
         *
         */
        virtual void setUniforms(Shader& shader, const std::string& name) const;

    private:

        LightType m_type;    /**< The type of the Light */
        Color m_color;   /**< The color of lights rays */
        float m_ambient; /**< The ambient factor of the Light */
        float m_diffuse; /**< The diffuse factor of the Light */
    };
}

#endif // BULL_GRAPHICS_LIGHT_ABSTRACTLIGHT_HPP
