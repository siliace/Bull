#ifndef BULL_CORE_RUNTIME_HPP
#define BULL_CORE_RUNTIME_HPP

#include <typeindex>
#include <unordered_map>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Pattern/Singleton.hpp>

namespace Bull
{
    class BULL_CORE_API RunTime : public Singleton<RunTime>
    {
    public:

        DeclareException(NoInstanceException);

        /** \brief Get the name of a Type
         *
         * \tparam T The type
         *
         * \return The name of the Type
         *
         */
        template <typename T>
        static std::string typeName()
        {
            return typeid(T).name();
        }

        /** \brief Get the std::type_index of a Type
         *
         * \tparam T The type
         *
         * \return The std::type_index of the Type
         *
         */
        template <typename T>
        static std::type_index typeIndex()
        {
            return std::type_index(typeid(T));
        }

    public:

        /** \brief Register an instance of a SharedSingleton
         *
         * \tparam T The type of the SharedSingleton to register
         *
         * \param singleton The instance to register
         *
         */
        template <typename T>
        void registerSingleton(std::shared_ptr<T>& singleton)
        {
            m_instances[typeIndex<T>()] = &singleton;
        }

        /** \brief Get the instance of a SharedSingleton
         *
         * \tparam T The type of the SharedSingleton to get
         *
         * \return The instance
         *
         */
        template <typename T>
        std::shared_ptr<T> getSingleton() const
        {
            std::shared_ptr<T> instance;
            auto it = m_instances.find(typeIndex<T>());

            Expect(it != m_instances.end(), Throw(NoInstanceException, "No singleton registered for type " + typeName<T>()));

            return *static_cast<std::shared_ptr<T>*>(it->second);
        }

    private:

        friend class Singleton<RunTime>;

        /** \brief Default constructor
         *
         */
        RunTime() = default;

    private:

        std::unordered_map<std::type_index, void*> m_instances;
    };
}

#endif // BULL_CORE_RUNTIME_HPP
