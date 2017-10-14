#include <Bull/Core/Resource/ParameterBag.hpp>

namespace Bull
{
    ParameterBag::Parameter::Value::Value() :
        pointerValue(nullptr)
    {
        /// Nothing
    }

    ParameterBag::Parameter::Value::Value(const Value& copy)
    {
        std::memcpy(this, &copy, sizeof(Value));
    }

    ParameterBag::Parameter::Value::~Value()
    {
        /// Nothing
    }

    ParameterBag::Parameter::Value& ParameterBag::Parameter::Value::operator=(const ParameterBag::Parameter::Value& right)
    {
        std::memcpy(this, &right, sizeof(Value));

        return (*this);
    }

    ParameterBag::Parameter::Parameter() :
        type(PointerType)
    {
        /// Nothing
    }

    ParameterBag::Parameter& ParameterBag::Parameter::operator=(const ParameterBag::Parameter& right)
    {
        type  = right.type;
        value = right.value;

        return (*this);
    }
}