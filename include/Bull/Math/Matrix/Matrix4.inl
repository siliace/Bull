#include <Bull/Math/Vector/Vector4.hpp>

namespace Bull
{
    template <typename T>
    Matrix4<T> Matrix4<T>::makeScale(const Vector3<T>& scale)
    {
        Matrix4<T> model;

        model.at(0, 0) = scale.at(0);
        model.at(1, 1) = scale.at(1);
        model.at(2, 2) = scale.at(2);

        return model;
    }

    template <typename T>
    Matrix4<T> Matrix4<T>::makeRotation(const Quaternion<T>& rotation)
    {
        Matrix4<T> model;

        T tx  = rotation.x + rotation.x;
        T ty  = rotation.y + rotation.y;
        T tz  = rotation.z + rotation.z;
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

    template <typename T>
    Matrix4<T> Matrix4<T>::makeTranslation(const Vector3<T>& translation)
    {
        Matrix4<T> model = Matrix4<T>::Identity;

        model.at(3, 0) = translation.x();
        model.at(3, 1) = translation.y();
        model.at(3, 2) = translation.z();

        return model;
    }

    template <typename T>
    Matrix4<T> Matrix4<T>::makeOrthographic(const Rectangle<T>& plan, const Vector2<T>& zBounds)
    {
        Matrix4<T> projection;

        T top    = plan.y;
        T left   = plan.x;
        T right  = plan.x + plan.width;
        T bottom = plan.y + plan.height;

        projection(0, 0) = 2 / (right - left);
        projection(1, 1) = 2 / (top - bottom);
        projection(2, 2) = 1 / (zBounds.x - zBounds.y);
        projection(3, 0) = (left + right) / (left - right);
        projection(3, 1) = (top + bottom) / (bottom - top);
        projection(3, 2) = zBounds.x / (zBounds.x - zBounds.y);
        projection(3, 3) = 1;

        return projection;
    }

    template <typename T>
    Matrix4<T> Matrix4<T>::makePerspective(const Angle<T>& angle, float ratio, const Vector2<T>& zBounds)
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

    template <typename T>
    Matrix4<T> Matrix4<T>::makeLookAt(const Vector3<T>& eye, const Vector3<T>& center, const Vector3<T>& up)
    {
        Matrix4<T> view;

        Vector3<T> f = Vector3<T>::normalize(center - eye);
        Vector3<T> s = Vector3<T>::crossProduct(f, up).normalize();
        Vector3<T> u = Vector3<T>::crossProduct(s, f).normalize();

        view.setColumn(Vector4<T>( s, -s.dotProduct(eye)), 0);
        view.setColumn(Vector4<T>( u, -u.dotProduct(eye)), 1);
        view.setColumn(Vector4<T>(-f,  f.dotProduct(eye)), 2);
        view.setColumn(Vector4<T>(0.f, 0.f, 0.f, 1.f),     3);

        return view;
    }

    template <typename T>
    Matrix4<T>::Matrix4(T value) :
        SquareMatrix<T, 4>(value)
    {
        /// Nothing
    }

    template <typename T>
    template <typename U, Index WU, Index HU>
    Matrix4<T>::Matrix4(const Matrix<U, WU, HU>& copy) :
        SquareMatrix<T, 4>(copy)
    {
        /// Nothing
    }
}
