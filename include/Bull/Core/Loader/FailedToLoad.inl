#include <Bull/Core/IO/StringStream.hpp>

namespace Bull
{
    template <typename T>
    FailedToLoad<T>::FailedToLoad(const String& name, const T& resource) :
        m_name(name),
        m_resource(resource)
    {
        /// Nothing
    }

    template <typename T>
    const T& FailedToLoad<T>::getResource() const
    {
        return m_resource;
    }

    template <typename T>
    const String& FailedToLoad<T>::getName() const
    {
        return m_name;
    }

    template <typename T>
    String FailedToLoad<T>::getLogMessage() const
    {
        StringStream ss;

        ss << "Failed to load resource " << m_name;

        return ss.toString();
    }
}