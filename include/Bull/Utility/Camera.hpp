#ifndef BULL_CAMERA_HPP
#define BULL_CAMERA_HPP

#include <Bull/Core/System/Export.hpp>

#include <Bull/Math/Matrix/Matrix4.hpp>
#include <Bull/Math/Vector/Vector3.hpp>

namespace Bull
{
    class BULL_API Camera
    {
    public:

        /*! \brief Default constructor
         *
         */
        Camera();

        /*! \brief Constructor
         *
         * \param position The position of the Camera
         * \param front    The front position of the camera
         * \param up       The up vector of the camera
         *
         */
        Camera(const Vector3F& position, const Vector3F& front, const Vector3F& up = Vector3F::makeUp());

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
