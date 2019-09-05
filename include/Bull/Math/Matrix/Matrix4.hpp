#ifndef BULL_MATH_MATRIX_MATRIX4_HPP
#define BULL_MATH_MATRIX_MATRIX4_HPP

#include <array>

#include <Bull/Math/Angle.hpp>
#include <Bull/Math/Matrix/SquareMatrix.hpp>
#include <Bull/Math/Polygon/Rectangle.hpp>
#include <Bull/Math/Quaternion.hpp>
#include <Bull/Math/Vector/Vector4.hpp>

namespace Bull
{
    template <typename T>
    class Matrix4 : public SquareMatrix<T, 4>
    {
    public:

        static Matrix4<T> Identity;

        /** \brief Create a scaling transformation matrix
         *
         * \param scale The scaling factor
         *
         * \return The transformation matrix
         *
         */
        static Matrix4<T> makeScale(const Vector3<T>& scale)
        {
            Matrix4<T> model = Matrix4<T>::Identity;

            model.at(0, 0) = scale.at(0);
            model.at(1, 1) = scale.at(1);
            model.at(2, 2) = scale.at(2);

            return model;
        }

        /** \brief Create a rotation transformation matrix
         *
         * \param rotation The rotation
         *
         * \return The transformation matrix
         *
         */
        static Matrix4<T> makeRotation(const Quaternion<T>& rotation)
        {
            Matrix4<T> model = Identity;

            T tx = rotation.x + rotation.x;
            T ty = rotation.y + rotation.y;
            T tz = rotation.z + rotation.z;
            T twx = tx * rotation.w;
            T twy = ty * rotation.w;
            T twz = tz * rotation.w;
            T txx = tx * rotation.x;
            T txy = ty * rotation.x;
            T txz = tz * rotation.x;
            T tyy = ty * rotation.y;
            T tyz = tz * rotation.y;
            T tzz = tz * rotation.z;

            model.at(0, 0) = 1.f - (tyy + tzz);
            model.at(0, 1) = txy + twz;
            model.at(0, 2) = txz - twy;

            model.at(1, 0) = txy - twz;
            model.at(1, 1) = 1.f - (txx + tzz);
            model.at(1, 2) = tyz + twx;

            model.at(2, 0) = txz + twy;
            model.at(2, 1) = tyz - twx;
            model.at(2, 2) = 1.f - (txx + tyy);

            return model;
        }

        /** \brief Create a translation transformation matrix
         *
         * \param translation The translation
         *
         * \return The translation matrix
         *
         */
        static Matrix4<T> makeTranslation(const Vector3<T>& translation)
        {
            Matrix4<T> model = Matrix4<T>::Identity;

            model.at(3, 0) = translation.x();
            model.at(3, 1) = translation.y();
            model.at(3, 2) = translation.z();

            return model;
        }

        /** \brief Create an orthographic projection matrix
         *
         * \param plan
         * \param zBounds
         *
         * \return The projection matrix
         *
         */
        static Matrix4<T> makeOrthographic(const Rectangle<T>& plan, const Vector2<T>& zBounds)
        {
            Matrix4<T> projection;

            T n = zBounds.x();
            T f = zBounds.y();

            T top = plan.y;
            T left = plan.x;
            T right = plan.x + plan.width;
            T bottom = plan.y + plan.height;

            projection.at(0, 0) = 2 / (right - left);
            projection.at(1, 1) = 2 / (top - bottom);
            projection.at(2, 2) = -2 / (f - n);
            projection.at(3, 0) = -((right + left) / (right - left));
            projection.at(3, 1) = -((top + bottom) / (top - bottom));
            projection.at(3, 2) = -((f + n) / (f - n));
            projection.at(3, 3) = 1;

            return projection;
        }

        /** \brief Create a perspective projection matrix
         *
         * \param angle
         * \param ratio
         * \param zBounds
         *
         * \return The projection matrix
         *
         */
        static Matrix4<T> makePerspective(const Angle<T>& angle, float ratio, const Vector2<T>& zBounds)
        {
            Matrix4<T> projection;
            Angle<T> fov = angle / static_cast<T>(2);

            float yScale = std::tan(Angle<T>::radian(Pi2) - fov);

            projection.at(0, 0) = yScale / ratio;
            projection.at(1, 1) = yScale;
            projection.at(2, 2) = -(zBounds.y() + zBounds.x()) / (zBounds.y() - zBounds.x());
            projection.at(2, 3) = -1;
            projection.at(3, 2) = -2 * (zBounds.x() * zBounds.y()) / (zBounds.y() - zBounds.x());

            return projection;
        }

        /** \brief Create a look at matrix
         *
         * \param eye    The position of the camera
         * \param center The target to look at
         * \param up     The up vector of the camera
         *
         * \return The view matrix
         *
         */
        static Matrix4<T> makeLookAt(const Vector3<T>& eye, const Vector3<T>& center, const Vector3<T>& up = Vector3<T>::Up)
        {
            Matrix4<T> view;

            Vector3<T> f = Vector3<T>::normalize(center - eye);
            Vector3<T> u = Vector3<T>::normalize(up);
            Vector3<T> s = Vector3<T>::crossProduct(f, u).normalize();
            u = Vector3<T>::crossProduct(s, f).normalize();

            view.setColumn(Vector4<T>(s, -s.dotProduct(eye)), 0);
            view.setColumn(Vector4<T>(u, -u.dotProduct(eye)), 1);
            view.setColumn(Vector4<T>(-f, f.dotProduct(eye)), 2);
            view.setColumn(Vector4<T>(0.f, 0.f, 0.f, 1.f), 3);

            return view;
        }

    public:

        /** \brief Default constructor
         *
         */
        Matrix4() = default;

        /** \brief Constructor
         *
         * \param value The value to use to fill the Matrix
         *
         */
        explicit Matrix4(T value) :
                SquareMatrix<T, 4>(value)
        {
            /// Nothing
        }

        /** \brief Copy constructor
         *
         * \param copy The Matrix to copy
         *
         */
        template <typename U, std::size_t WU, std::size_t HU>
        Matrix4(const Matrix<U, WU, HU>& copy) :
                SquareMatrix<T, 4>(copy)
        {
            /// Nothing
        }
    };

    template <typename T>
    Matrix4<T> Matrix4<T>::Identity = Matrix4<T>::makeIdentity();

    typedef Matrix4<int> Matrix4I;
    typedef Matrix4<float> Matrix4F;
    typedef Matrix4<double> Matrix4D;
    typedef Matrix4<unsigned int> Matrix4UI;
}

#endif // BULL_MATRIX4_HPP
