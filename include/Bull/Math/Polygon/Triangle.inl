namespace Bull
{
    template<typename T>
    template<typename U, typename V, typename W>
    Triangle<T>::Triangle(const Vector2<U>& center, V radius, const Angle<W>& rotation) :
        CircularPolygon<T, 3>(center, radius, rotation)
    {
        /// Nothing
    }
}
