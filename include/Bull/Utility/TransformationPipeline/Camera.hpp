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
        Camera() = default;

        /*! \brief Constructor
         *
         * \param position The position of the Camera
         * \param front    The front position of the camera
         * \param up       The up vector of the camera
         *
         */
        Camera(const Vector3F& position, const Vector3F& front, const Vector3F& up = Vector3F::makeUp());

        /*! \brief Move the Camera
         *
         * \param offset Offset to move the Camera
         *
         * \return This
         *
         */
        Camera& move(const Vector3F& offset);

        /*! \brief Move the Camera on the X axis
         *
         * \param offset The offset to move the Camera
         *
         * \return This
         *
         */
        Camera& moveX(float offset);

        /*! \brief Move the Camera on the Y axis
         *
         * \param offset The offset to move the Camera
         *
         * \return This
         *
         */
        Camera& moveY(float offset);

        /*! \brief Move the Camera on the Z axis
         *
         * \param offset The offset to move the Camera
         *
         * \return This
         *
         */
        Camera& moveZ(float offset);

        /*! \brief Get the target looked by the Camera
         *
         * \return The target
         *
         */
        Vector3F getTarget() const;

        /*! \brief Convert the camera to a view matrix
         *
         * \return The view matrix
         *
         */
        Matrix4F toMatrix() const;

    private:

        Vector3F m_position;
        Vector3F m_front;
        Vector3F m_up;
    };
}

#endif //BULL_CAMERA_HPP
