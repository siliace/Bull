#include <Bull/Core/Loader/ParameterBag.hpp>

namespace Bull
{
    bool ParameterBag::hasParameter(const String& name) const
    {
        return m_parameters.find(name) != m_parameters.end();
    }

    ParameterBag& ParameterBag::setParameter(const String& name, int value)
    {
        Parameter parameter;
        parameter.value.intValue = value;
        parameter.type = Parameter::IntType;

        m_parameters[name] = parameter;

        return (*this);
    }

    bool ParameterBag::getParameter(const String& name, int* value) const
    {
        if(hasParameter(name))
        {
            Parameter parameter = m_parameters[name];

            if(parameter.type == Parameter::IntType)
            {
                value = &parameter.value.intValue;

                return true;
            }
        }

        return false;
    }

    ParameterBag& ParameterBag::setParameter(const String& name, const Color& value)
    {
        Parameter parameter;
        parameter.value.colorValue = value;
        parameter.type = Parameter::ColorType;

        m_parameters[name] = parameter;

        return (*this);
    }

    bool ParameterBag::getParameter(const String& name, Color* value) const
    {
        if(hasParameter(name))
        {
            Parameter parameter = m_parameters[name];

            if(parameter.type == Parameter::ColorType)
            {
                value = &parameter.value.colorValue;

                return true;
            }
        }

        return false;
    }

    ParameterBag& ParameterBag::setParameter(const String& name, float value)
    {
        Parameter parameter;
        parameter.value.floatValue = value;
        parameter.type = Parameter::FloatType;

        m_parameters[name] = parameter;

        return (*this);
    }

    bool ParameterBag::getParameter(const String& name, float* value) const
    {
        if(hasParameter(name))
        {
            Parameter parameter = m_parameters[name];

            if(parameter.type == Parameter::FloatType)
            {
                value = &parameter.value.floatValue;

                return true;
            }
        }

        return false;
    }

    ParameterBag& ParameterBag::setParameter(const String& name, const String& value)
    {
        Parameter parameter;
        parameter.value.stringValue = value;
        parameter.type = Parameter::StringType;

        m_parameters[name] = parameter;

        return (*this);
    }

    bool ParameterBag::getParameter(const String& name, String* value) const
    {
        if(hasParameter(name))
        {
            Parameter parameter = m_parameters[name];

            if(parameter.type == Parameter::StringType)
            {
                value = &parameter.value.stringValue;

                return true;
            }
        }

        return false;
    }

    ParameterBag& ParameterBag::setParameter(const String& name, bool value)
    {
        Parameter parameter;
        parameter.value.booleanValue = value;
        parameter.type = Parameter::BooleanType;

        m_parameters[name] = parameter;

        return (*this);
    }

    bool ParameterBag::getParameter(const String& name, bool* value) const
    {
        if(hasParameter(name))
        {
            Parameter parameter = m_parameters[name];

            if(parameter.type == Parameter::BooleanType)
            {
                value = &parameter.value.booleanValue;

                return true;
            }
        }

        return false;
    }

    ParameterBag& ParameterBag::setParameter(const String& name, void* value)
    {
        Parameter parameter;
        parameter.value.pointerValue = value;
        parameter.type = Parameter::PointerType;

        m_parameters[name] = parameter;

        return (*this);
    }

    bool ParameterBag::getParameter(const String& name, void** value) const
    {
        if(hasParameter(name))
        {
            Parameter parameter = m_parameters[name];

            if(parameter.type == Parameter::PointerType)
            {
                value = &parameter.value.pointerValue;

                return true;
            }
        }

        return false;
    }
}