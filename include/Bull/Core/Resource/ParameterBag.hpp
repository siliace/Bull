#ifndef BULL_CORE_LOADER_PARAMETERBAG_HPP
#define BULL_CORE_LOADER_PARAMETERBAG_HPP

#include <cstring>
#include <map>

#include <Bull/Core/Export.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Utility/Color.hpp>

namespace Bull
{
    class BULL_CORE_API ParameterBag
    {
    public:

        /*! \brief Default constructor
         *
         */
        ParameterBag() = default;

        bool hasParameter(const String& name) const;

        ParameterBag& setParameter(const String& name, int value);
        bool getParameter(const String& name, int* value) const;

        ParameterBag& setParameter(const String& name, const Color& value);
        bool getParameter(const String& name, Color* value) const;

        ParameterBag& setParameter(const String& name, float value);
        bool getParameter(const String& name, float* value) const;

        ParameterBag& setParameter(const String& name, const String& value);
        bool getParameter(const String& name, String* value) const;

        ParameterBag& setParameter(const String& name, bool value);
        bool getParameter(const String& name, bool* value) const;

        ParameterBag& setParameter(const String& name, void* value);
        bool getParameter(const String& name, void** value) const;

    private:

        struct Parameter
        {
            enum Type
            {
                IntType,
                ColorType,
                FloatType,
                StringType,
                BooleanType,
                PointerType,
            };

            union Value
            {
                Value();
                Value(const Value& copy);
                ~Value();
                Value& operator=(const Value& right);

                int    intValue;
                Color  colorValue;
                float  floatValue;
                String stringValue;
                bool   booleanValue;
                void*  pointerValue;
            };

            Parameter();
            Parameter& operator=(const Parameter& right);

            Type  type;
            Value value;
        };

        std::map<String, Parameter> m_parameters;
    };
}

#endif // BULL_CORE_LOADER_PARAMETERBAG_HPP
