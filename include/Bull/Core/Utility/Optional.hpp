#ifndef BULL_CORE_UTILITY_OPTIONAL_HPP
#define BULL_CORE_UTILITY_OPTIONAL_HPP

#include <memory>

#include <Bull/Core/Exception/DeclareException.hpp>
#include <Bull/Core/Exception/Exception.hpp>
#include <Bull/Core/Exception/Expect.hpp>
#include <Bull/Core/Exception/Throw.hpp>
#include <Bull/Core/Utility/Function.hpp>

namespace Bull
{
    DeclareException(EmptyOptional)

    template <typename T>
    class BULL_CORE_API Optional
    {
    public:

        /*! \brief Constructor
         *
         * \param value The optional value
         *
         */
        explicit Optional(T* value = nullptr) :
            m_value(value)
        {
            /// Nothing
        }

        /*! \brief Get the value of the Optional if not null, return a fallback value otherwise
         *
         * \param fallback The fallback value
         *
         * \return The value of the Optional
         *
         */
        const T* orElse(const T* fallback) const
        {
            return !isEmpty() ? m_value : fallback;
        }

        /*! \brief Get the value of the Optional if not null, return a fallback value generated from a provider otherwise
         *
         * \param provider The provider to use as fallback generator
         *
         * \return The value of the Optional
         *
         */
        const T* orElseGet(const Provider<const T*> provider) const
        {
            return !isEmpty() ? m_value : provider();
        }

        /*! \brief Get the value of the Optional if not null, throw an exception otherwise
         *
         * \tparam E The type of Exception to throw
         *
         * \return The value of the Optional
         *
         * \throw E if the Optional value is null
         *
         */
        template <typename E = EmptyOptional, typename = std::enable_if<std::is_base_of<Exception, E>::value>>
        const T* orElseThrow() const
        {
            Expect(!isEmpty(), Throw(E, "Optional::orElseThrow", "Empty optional"));

            return m_value;
        }

        /*! \brief Tell whether the Optional is empty
         *
         * \return True if the Optional is not empty
         *
         */
        bool isEmpty() const
        {
            return m_value == nullptr;
        }

        /*! \brief Consume the value of the Optional
         *
         * \param consumer The Consumer
         *
         */
        void ifNotEmpty(const Consumer<const T&>& consumer) const
        {
            if(!isEmpty())
            {
                consumer(*m_value);
            }
        }

    private:

        T* m_value;
    };
}

#endif // BULL_CORE_UTILITY_OPTIONAL_HPP
