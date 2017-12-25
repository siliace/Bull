#ifndef BULL_GRAPHICS_LIGHT_ABSTRACTLIGHT_HPP
#define BULL_GRAPHICS_LIGHT_ABSTRACTLIGHT_HPP

#include <Bull/Core/Utility/Color.hpp>

#include <Bull/Graphics/Export.hpp>
#include <Bull/Graphics/Light/LightType.hpp>

namespace Bull
{ 
    class BULL_GRAPHICS_API AbstractLight
    {
    public:

        /*! \brief Get the type of the Light
         *
         * \return The type
         *
         */
        LightType getType() const;

        /*! \brief Set the Light's Color
         *
         * \param color The Color
         *
         */
        void setColor(const Color& color);

        /*! \brief Get the Light's Color
         *
         * \return The Color
         *
         */
        const Color& getColor() const;

        /*! \brief Set the ambient factor of the Light
         *
         * \param ambient The ambient factor
         *
         */
        void setAmbiantFactor(float ambient);

        /*! \brief Get the ambient factor of the Light
         *
         * \return The ambient factor
         *
         */
        float getAmbiantFactor() const;

        /*! \brief Set the diffuse factor of the Light
         *
         * \param diffuse The ambient factor
         *
         */
        void setDiffuseFactor(float diffuse);

        /*! \brief Get the diffuse factor of the Light
         *
         * \return The diffuse factor
         *
         */
        float getDiffuseFactor() const;

    protected:

        /*! \brief Constructor
         *
         * \param type The type of the Light
         *
         */
        explicit AbstractLight(LightType type);

    private:

        LightType m_type;    /*!< The type of the Light */
        Color     m_color;   /*!< The color of lights rays */
        float     m_ambient; /*!< The ambient factor of the Light */
        float     m_diffuse; /*!< The diffuse factor of the Light */
    };
}

#endif // BULL_GRAPHICS_LIGHT_ABSTRACTLIGHT_HPP
