#include <Bull/Math/Vector/Vector4.hpp>

namespace Bull
{
    template <typename T>
    Camera<T>::Camera()  :
        m_up(Vector3<T>::Up),
        m_right(Vector3<T>::right),
        m_view(Matrix4<T>::Identity),
        m_forward(Vector3<T>::forward)
    {
        /// Nothing
    }

    template <typename T>
    Camera<T>::Camera(const Vector3<T>& eye, const Vector3<T>& center, const Vector3<T>& up) :
        m_up(up),
        m_right(Vector3<T>::Right),
        m_forward(Vector3<T>::Forward)
    {
        setPosition(eye).setTarget(center);
    }

    template <typename T>
    Camera<T>& Camera<T>::setPosition(const Vector3<T>& eye)
    {
        m_eye = eye;

        updateMatrix();

        return (*this);
    }

    template <typename T>
    const Vector3<T> Camera<T>::getPosition() const
    {
        return m_eye;
    }

    template <typename T>
    Camera<T>& Camera<T>::move(const Vector3<T>& offset)
    {
        m_eye += m_right   * offset.x;
        m_eye += m_up      * offset.y;
        m_eye += m_forward * offset.z;

        updateMatrix();

        return (*this);
    }

    template <typename T>
    Camera<T>& Camera<T>::setTarget(const Vector3<T>& center)
    {
        m_center = center;

        updateMatrix();

        return (*this);
    }

    template <typename T>
    const Vector3<T> Camera<T>::getTarget() const
    {
        return m_center;
    }

    template <typename T>
    const Vector3<T>& Camera<T>::getUp() const
    {
        return m_up;
    }

    template <typename T>
    const Vector3<T>& Camera<T>::getRight() const
    {
        return m_right;
    }

    template <typename T>
    const Vector3<T>& Camera<T>::getForward() const
    {
        return m_forward;
    }

    template <typename T>
    const Matrix4<T>& Camera<T>::getMatrix() const
    {
        return m_view;
    }

    template <typename T>
    void Camera<T>::updateMatrix()
    {
        m_forward = Vector3<T>::normalize(m_center - m_eye);
        m_right   = Vector3<T>::crossProduct(m_forward, m_up).normalize();
        m_up      = Vector3<T>::crossProduct(m_right, m_forward).normalize();

        m_view.setColumn(Vector4<T>( m_right,  -m_right.dotProduct(m_eye)),   0);
        m_view.setColumn(Vector4<T>( m_up,     -m_up.dotProduct(m_eye)),      1);
        m_view.setColumn(Vector4<T>(-m_forward, m_forward.dotProduct(m_eye)), 2);
        m_view.setColumn(Vector4<T>(0.f, 0.f, 0.f, 1.f),                      3);
    }
}