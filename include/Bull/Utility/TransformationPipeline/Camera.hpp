#ifndef BULL_CAMERA_HPP
#define BULL_CAMERA_HPP

#include <Bull/Math/Matrix/Matrix4.hpp>
#include <Bull/Math/Vector/Vector3.hpp>

#include <Bull/Utility/TransformationPipeline/Matrixable.hpp>

namespace Bull
{
    class BULL_UTILITY_API Camera : public Matrixable
    {
    public:

        /*! \brief Default constructor
         *
         */
        Camera();

        /*! \brief Constructor
         *
         * \param position The initial position of the Camera
         * \param rotation The initial rotation of the Camera
         *
         */
        Camera(const Vector3F& position, const EulerAnglesF& rotation = EulerAnglesF());

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

        Vector3F m_up;
        Vector3F m_right;
        Vector3F m_forward;
        Vector3F m_position;
    };
}

#endif //BULL_CAMERA_HPP
