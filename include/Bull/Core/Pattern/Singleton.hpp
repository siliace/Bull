#ifndef Bull_Singleton_hpp
#define Bull_Singleton_hpp

#include <memory>

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Thread/Mutex.hpp>

namespace Bull
{
    template<typename TChild>
    class BULL_API Singleton : public NonCopyable
    {
    public:

        typedef std::shared_ptr<TChild> Instance;

        /*! \brief Get the instance of the singleton. Create the instance if needed
         *
         * \param args Arguments to use to create the instance
         *
         * \return Return the instance of the singleton
         *
         */
        template<typename... Args>
        static Instance get(Args... args);

        /*! \brief Get the instance only if exists
         *
         * \return Return the instance is exists, nullptr otherwise
         *
         */
        static Instance getIfExists();

        /*! \brief Check whether the instance is set
         *
         * \param Return true if the instance is set, false otherwise
         *
         */
        static bool isSet();

        /*! \brief Destroy the instance
         *
         */
        static void destroy();

    private:

        static Mutex s_mutex;
        static Instance s_instance;

    };

    template <typename TChild>
    Mutex Singleton<TChild>::s_mutex;

    template <typename TChild>
    std::shared_ptr<TChild> Singleton<TChild>::s_instance = std::shared_ptr<TChild>(nullptr);
}

#include <Bull/Core/Pattern/Singleton.inl>

#endif // Bull_Singleton_hpp
