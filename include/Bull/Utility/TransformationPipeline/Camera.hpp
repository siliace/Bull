#ifndef BULL_CAMERA_HPP
#define BULL_CAMERA_HPP

#include <Bull/Math/EulerAngles.hpp>
#include <Bull/Math/Matrix/Matrix4.hpp>
#include <Bull/Math/Vector/Vector3.hpp>

#include <Bull/Utility/TransformationPipeline/Matrixable.hpp>

namespace Bull
{
    class BULL_UTILITY_API Camera : public Matrixable
    {
    public:

        /*! \brief Constructor
         *
         * \param position The initial position of the Camera
         * \param rotation The initial rotation of the Camera
         *
         */
        Camera(const Vector3F& position = Vector3F::makeZero(), const EulerAnglesF& rotation = EulerAnglesF::Zero);

        /*! \brief Move the Camera
         *
         * \param offset Offset to move the Camera
         *
         * \return This
         *
         */
        Camera& move(const Vector3F& offset);

        /*! \brief Rotate the Camera
         *
         * \param rotation Angles to rotate the Camera
         *
         * \return This
         *
         */
        Camera& rotate(const EulerAnglesF& rotation);

        /*! \brief Convert to a Matrix4F
         *
         * \return The Matrix4F
         *
         */
        Matrix4F toMatrix() const override;

    private:

        /*! \brief Update Camera's vectors
         *
         */
        void update();

        Vector3F     m_up;
        Vector3F     m_right;
        Vector3F     m_target;
        Vector3F     m_forward;
        Vector3F     m_position;
        EulerAnglesF m_rotation;
    };
}

#endif //BULL_CAMERA_HPP
