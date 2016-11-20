namespace Bull
{
    /*! \brief Convert an angle from radian to degree
     *
     * \param rad The angle in radian
     *
     * \return The angle converted in degree
     *
     */
    template<typename T>
    T degree(T rad)
    {
        return rad * (180.0 / Pi);
    }

    /*! \brief Convert an angle from degree to radian
     *
     * \param deg The angle in degree
     *
     * \return The angle converted in radian
     *
     */
    template<typename T>
    T radian(T deg)
    {
        return deg * (Pi / 180.0);
    }
}
