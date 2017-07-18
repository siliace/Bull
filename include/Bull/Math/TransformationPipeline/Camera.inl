namespace Bull
{
    template <typename T>
    Matrix4<T> Camera<T>::lootAt(const Vector3<T>& eye, const Vector3<T>& target, const Vector3<T>& up)
    {
        Matrix4<T> view;

        Vector3<T> f = Vector3<T>::normalize(target - eye);
        Vector3<T> u = Vector3<T>::normalize(up);
        Vector3<T> s = Vector3<T>::crossProduct(f, u).normalize();
        u            = Vector3<T>::crossProduct(s, f);

        view.setColumn(Vector4<T>( s, -s.dotProduct(eye)), 0);
        view.setColumn(Vector4<T>( u, -u.dotProduct(eye)), 1);
        view.setColumn(Vector4<T>(-f,  f.dotProduct(eye)), 2);
        view.setColumn(Vector4<T>(0.f, 0.f, 0.f, 1.f),     3);

        return view;
    }
}