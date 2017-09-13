#ifndef BULL_CORE_LOADER_PARAMETERBAG_HPP
#define BULL_CORE_LOADER_PARAMETERBAG_HPP

#include <functional>
#include <map>

#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    class BULL_CORE_API ParameterBag
    {
    public:

        using Destructor = std::function<void(void*)>;

        /*! \brief Get a default destructor callback
         *
         * \return The callback
         *
         */
        static Destructor getDefaultDestructor();

    public:

        /*! \brief Set a parameter in the ParameterBag
         *
         * \param name  The name of the parameter to set
         * \param value The value of the parameter to set
         *
         * \return This
         *
         */
        ParameterBag& setParameter(const String& name, int value);

        /*! \brief Set a parameter in the ParameterBag
         *
         * \param name  The name of the parameter to set
         * \param value The value of the parameter to set
         *
         * \return This
         *
         */
        ParameterBag& setParameter(const String& name, bool value);

        /*! \brief Set a parameter in the ParameterBag
         *
         * \param name  The name of the parameter to set
         * \param value The value of the parameter to set
         *
         * \return This
         *
         */
        ParameterBag& setParameter(const String& name, char value);

        /*! \brief Set a parameter in the ParameterBag
         *
         * \param name  The name of the parameter to set
         * \param value The value of the parameter to set
         *
         * \return This
         *
         */
        ParameterBag& setParameter(const String& name, long value);

        /*! \brief Set a parameter in the ParameterBag
         *
         * \param name  The name of the parameter to set
         * \param value The value of the parameter to set
         *
         * \return This
         *
         */
        ParameterBag& setParameter(const String& name, float value);

        /*! \brief Set a parameter in the ParameterBag
         *
         * \param name  The name of the parameter to set
         * \param value The value of the parameter to set
         *
         * \return This
         *
         */
        ParameterBag& setParameter(const String& name, void* value);

        /*! \brief Set a parameter in the ParameterBag
         *
         * \param name  The name of the parameter to set
         * \param value The value of the parameter to set
         *
         * \return This
         *
         */
        ParameterBag& setParameter(const String& name, double  value);

        /*! \brief Set a parameter in the ParameterBag
         *
         * \param name  The name of the parameter to set
         * \param value The value of the parameter to set
         *
         * \return This
         *
         */
        ParameterBag& setParameter(const String& name, unsigned int value);

        /*! \brief Set a parameter in the ParameterBag
         *
         * \param name  The name of the parameter to set
         * \param value The value of the parameter to set
         *
         * \return This
         *
         */
        ParameterBag& setParameter(const String& name, unsigned char value);

        /*! \brief Set a parameter in the ParameterBag
         *
         * \param name       The name of the parameter to set
         * \param value      The value of the parameter to set
         * \param destructor The callback to free the pointer
         *
         * \return This
         */
        ParameterBag& setParameter(const String& name, void* value, const Destructor& destructor);

        /*! \brief Get a parameter from the ParameterBag
         *
         * \param name  The name of the parameter to get
         * \param value A pointer to get the value
         *
         * \return True if the requested parameter exists
         *
         */
        bool getParameter(const String& name, int& value) const;

        /*! \brief Get a parameter from the ParameterBag
         *
         * \param name  The name of the parameter to get
         * \param value A pointer to get the value
         *
         * \return True if the requested parameter exists
         *
         */
        bool getParameter(const String& name, bool& value) const;

        /*! \brief Get a parameter from the ParameterBag
         *
         * \param name  The name of the parameter to get
         * \param value A pointer to get the value
         *
         * \return True if the requested parameter exists
         *
         */
        bool getParameter(const String& name, char& value) const;

        /*! \brief Get a parameter from the ParameterBag
         *
         * \param name  The name of the parameter to get
         * \param value A pointer to get the value
         *
         * \return True if the requested parameter exists
         *
         */
        bool getParameter(const String& name, long& value) const;

        /*! \brief Get a parameter from the ParameterBag
         *
         * \param name  The name of the parameter to get
         * \param value A pointer to get the value
         *
         * \return True if the requested parameter exists
         *
         */
        bool getParameter(const String& name, float& value) const;

        /*! \brief Get a parameter from the ParameterBag
         *
         * \param name  The name of the parameter to get
         * \param value A pointer to get the value
         *
         * \return True if the requested parameter exists
         *
         */
        bool getParameter(const String& name, void*& value) const;

        /*! \brief Get a parameter from the ParameterBag
         *
         * \param name  The name of the parameter to get
         * \param value A pointer to get the value
         *
         * \return True if the requested parameter exists
         *
         */
        bool getParameter(const String& name, double& value) const;

        /*! \brief Get a parameter from the ParameterBag
         *
         * \param name  The name of the parameter to get
         * \param value A pointer to get the value
         *
         * \return True if the requested parameter exists
         *
         */
        bool getParameter(const String& name, String& value) const;

        /*! \brief Get a parameter from the ParameterBag
         *
         * \param name  The name of the parameter to get
         * \param value A pointer to get the value
         *
         * \return True if the requested parameter exists
         *
         */
        bool getParameter(const String& name, unsigned int& value) const;

        /*! \brief Get a parameter from the ParameterBag
         *
         * \param name  The name of the parameter to get
         * \param value A pointer to get the value
         *
         * \return True if the requested parameter exists
         *
         */
        bool getParameter(const String& name, unsigned char& value) const;

        /*! \brief Tell whether a parameter exists
         *
         * \param name The name of the parameter
         *
         * \return True if the parameter exists
         *
         */
        bool hasParameter(const String& name) const;

        /*! \brief Remove a paramter from the ParameterBag
         *
         * \param name The name of the parameter
         *
         * \return This
         *
         */
        ParameterBag& removeParameter(const String& name);

        /*! \brief Clear the ParameterBag
         *
         */
        void clear();

    private:

        struct Parameter
        {
            enum Type
            {
                IntType,
                CharType,
                LongType,
                FloatType,
                DoubleType,
                StringType,
                PointerType,
                BooleanType,
                UnsignedIntType,
                UnsignedCharType,
            };

            /*! \brief Destructor
             *
             */
            ~Parameter()
            {
                if(type == PointerType && destructor)
                {
                    destructor(pointerValue);
                }
            }

            Type       type;
            Destructor destructor;

            ///TODO: use an union
            int           intValue;
            bool          boolValue;
            char          charValue;
            long          longValue;
            float         floatValue;
            double        doubleValue;
            String        stringValue;
            void*         pointerValue;
            unsigned int  unsignedIntValue;
            unsigned char unsignedCharValue;
        };

        std::map<String, Parameter> m_parameters;
    };
}

#endif // BULL_CORE_LOADER_PARAMETERBAG_HPP
