#include <Bull/Core/Loader/ParameterBag.hpp>

namespace Bull
{
    ParameterBag::Destructor ParameterBag::getDefaultDestructor()
    {
        return [](void* data){
            delete static_cast<unsigned char*>(data);
        };
    }

    ParameterBag& ParameterBag::setParameter(const String& name, int value)
    {
        Parameter parameter;

        parameter.intValue = value;
        parameter.type = Parameter::IntType;

        m_parameters[name] = parameter;

        return (*this);
    }

    ParameterBag& ParameterBag::setParameter(const String& name, char value)
    {
        Parameter parameter;

        parameter.charValue = value;
        parameter.type = Parameter::CharType;

        m_parameters[name] = parameter;

        return (*this);
    }

    ParameterBag& ParameterBag::setParameter(const String& name, long value)
    {
        Parameter parameter;

        parameter.longValue = value;
        parameter.type = Parameter::LongType;

        m_parameters[name] = parameter;

        return (*this);
    }

    ParameterBag& ParameterBag::setParameter(const String& name, float value)
    {
        Parameter parameter;

        parameter.floatValue = value;
        parameter.type = Parameter::FloatType;

        m_parameters[name] = parameter;

        return (*this);
    }

    ParameterBag& ParameterBag::setParameter(const String& name, void* value)
    {
        Parameter parameter;

        parameter.pointerValue = value;
        parameter.type = Parameter::PointerType;

        m_parameters[name] = parameter;

        return (*this);
    }

    ParameterBag& ParameterBag::setParameter(const String& name, double  value)
    {
        Parameter parameter;

        parameter.doubleValue = value;
        parameter.type = Parameter::DoubleType;

        m_parameters[name] = parameter;

        return (*this);
    }

    ParameterBag& ParameterBag::setParameter(const String& name, unsigned int value)
    {
        Parameter parameter;

        parameter.unsignedIntValue = value;
        parameter.type = Parameter::UnsignedIntType;

        m_parameters[name] = parameter;

        return (*this);
    }

    ParameterBag& ParameterBag::setParameter(const String& name, unsigned char value)
    {
        Parameter parameter;

        parameter.unsignedCharValue = value;
        parameter.type = Parameter::UnsignedCharType;

        m_parameters[name] = parameter;

        return (*this);
    }

    ParameterBag& ParameterBag::setParameter(const String& name, void* value, const Destructor& destructor)
    {
        Parameter parameter;

        parameter.pointerValue = value;
        parameter.destructor = destructor;
        parameter.type = Parameter::PointerType;

        m_parameters[name] = parameter;

        return (*this);
    }

    bool ParameterBag::getParameter(const String& name, int& value) const
    {
        if(hasParameter(name))
        {
            if(m_parameters.at(name).type == Parameter::IntType)
            {
                value = m_parameters.at(name).intValue;

                return true;
            }
        }

        return false;
    }

    bool ParameterBag::getParameter(const String& name, char& value) const
    {
        if(hasParameter(name))
        {
            if(m_parameters.at(name).type == Parameter::CharType)
            {
                value = m_parameters.at(name).charValue;

                return true;
            }
        }

        return false;
    }

    bool ParameterBag::getParameter(const String& name, long& value) const
    {
        if(hasParameter(name))
        {
            if(m_parameters.at(name).type == Parameter::LongType)
            {
                value = m_parameters.at(name).longValue;

                return true;
            }
        }

        return false;
    }

    bool ParameterBag::getParameter(const String& name, float& value) const
    {
        if(hasParameter(name))
        {
            if(m_parameters.at(name).type == Parameter::FloatType)
            {
                value = m_parameters.at(name).floatValue;

                return true;
            }
        }

        return false;
    }

    bool ParameterBag::getParameter(const String& name, void*& value) const
    {
        if(hasParameter(name))
        {
            if(m_parameters.at(name).type == Parameter::PointerType)
            {
                value = m_parameters.at(name).pointerValue;

                return true;
            }
        }

        return false;
    }

    bool ParameterBag::getParameter(const String& name, double& value) const
    {
        if(hasParameter(name))
        {
            if(m_parameters.at(name).type == Parameter::DoubleType)
            {
                value = m_parameters.at(name).doubleValue;

                return true;
            }
        }

        return false;
    }

    bool ParameterBag::getParameter(const String& name, String& value) const
    {
        if(hasParameter(name))
        {
            if(m_parameters.at(name).type == Parameter::StringType)
            {
                value = m_parameters.at(name).stringValue;

                return true;
            }
        }

        return false;
    }

    bool ParameterBag::getParameter(const String& name, unsigned int& value) const
    {
        if(hasParameter(name))
        {
            if(m_parameters.at(name).type == Parameter::UnsignedIntType)
            {
                value = m_parameters.at(name).unsignedIntValue;

                return true;
            }
        }

        return false;
    }

    bool ParameterBag::getParameter(const String& name, unsigned char& value) const
    {
        if(hasParameter(name))
        {
            if(m_parameters.at(name).type == Parameter::UnsignedCharType)
            {
                value = m_parameters.at(name).unsignedCharValue;

                return true;
            }
        }

        return false;
    }

    bool ParameterBag::hasParameter(const String& name) const
    {
        m_parameters.find(name) != m_parameters.end();
    }

    ParameterBag& ParameterBag::removeParameter(const String& name)
    {
        m_parameters.erase(name);
    }

    void ParameterBag::clear()
    {
        m_parameters.clear();
    }
}