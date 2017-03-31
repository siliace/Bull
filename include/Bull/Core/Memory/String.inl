namespace Bull
{
    template <typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
    String String::number(T number)
    {
        return std::to_string(number).c_str();
    };
}