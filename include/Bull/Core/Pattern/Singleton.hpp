#ifndef BULL_SINGLETON_HPP
#define BULL_SINGLETON_HPP

#include <memory>

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Thread/Lock.hpp>

namespace Bull
{
    template<typename TChild>
    class Singleton : public NonCopyable
    {
    public:

        typedef TChild* Instance;

        /*! \brief Get the instance of the singleton. Create the instance if needed
         *
         * \param args Arguments to use to create the instance
         *
         * \return Return the instance of the singleton
         *
         */
        template<typename... Args>
        static Instance get(Args... args)
        {
            if(!s_instance)
            {
                Lock lock(s_mutex);

                if(!s_instance)
                {
                    s_instance = new TChild(args...);
                }
            }

            return s_instance;
        }

        /*! \brief Get the instance only if exists
         *
         * \return Return the instance is exists, nullptr otherwise
         *
         */
        static Instance getIfExists()
        {
            return isSet() ? s_instance : nullptr;
        }

        /*! \brief Check whether the instance is set
         *
         * \param Return true if the instance is set, false otherwise
         *
         */
        static bool isSet()
        {
            return s_instance != nullptr;
        }

        /*! \brief Destroy the instance
         *
         */
        static void destroy()
        {
            delete s_instance;
            s_instance = nullptr;
        }

    private:

        static Mutex s_mutex;
        static Instance s_instance;
    };

    template <typename TChild>
    Mutex Singleton<TChild>::s_mutex;

    template <typename TChild>
    TChild* Singleton<TChild>::s_instance = nullptr;
}

#endif // BULL_SINGLETON_HPP
