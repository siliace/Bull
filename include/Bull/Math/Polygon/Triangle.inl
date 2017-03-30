namespace Bull
{
    template<typename T>
    Triangle<T>::Triangle(const Vector2<T>& center, T radius, const Angle<T>& rotation) :
        RegularPolygon<T, 3>(center, radius, rotation)
    {
        /// Nothing
    }
}
