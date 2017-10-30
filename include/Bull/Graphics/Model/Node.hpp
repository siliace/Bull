#ifndef BULL_GRAPHICS_NODE_HPP
#define BULL_GRAPHICS_NODE_HPP

#include <Bull/Graphics/Export.hpp>

#include <Bull/Math/EulerAngles.hpp>
#include <Bull/Math/Matrix/Matrix4.hpp>
#include <Bull/Math/Vector/Vector3.hpp>

namespace Bull
{
    class BULL_GRAPHICS_API Node
    {
    public:

        /*! \brief Default constructor
         *
         */
        Node();

        /*! \brief Scale the Node
         *
         * \param scale The scaling factor
         *
         * \return This
         *
         */
        Node& scale(const Vector3F& scale);

        /*! \brief Rotate the Node
         *
         * \param rotation The rotation
         *
         * \return This
         *
         */
        Node& rotate(const EulerAnglesF& rotation);

        /*! \brief Move the Node
         *
         * \param translation The translation
         *
         * \return This
         *
         */
        Node& move(const Vector3F& translation);

        /*! \brief Get the model Matrix of the Node
         *
         * \return The model Matrix
         *
         */
        Matrix4F getModelMatrix() const;

    private:

        Vector3F     m_scale; /*!< The scale of the Node */
        EulerAnglesF m_rotation; /*!< The rotation of the Node */
        Vector3F     m_translation; /*!< The translation of the Node */
    };
}

#endif // BULL_GRAPHICS_NODE_HPP
