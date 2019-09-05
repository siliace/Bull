#ifndef BULL_CORE_PATTERN_SINGLETON_HPP
#define BULL_CORE_PATTERN_SINGLETON_HPP

#include <memory>
#include <mutex>

#include <Bull/Core/Pattern/NonCopyable.hpp>

namespace Bull
{
    template <typename T>
    class BULL_CORE_API Singleton : public NonCopyable
    {
    public:

        using Instance = T&;

    public:

        static Instance getInstance()
        {
            if(!s_instance)
            {
                std::lock_guard<std::mutex> lock(s_mutex);

                if(!s_instance)
                {
                    s_instance.reset(new T());
                }
            }

            return *s_instance;
        }

        static void destroy()
        {
            s_instance.reset();
        }

    private:

        static std::mutex s_mutex;
        static std::unique_ptr<T> s_instance;
    };

    template <typename T>
    std::mutex Singleton<T>::s_mutex;

    template <typename T>
    std::unique_ptr<T> Singleton<T>::s_instance;
}

#endif // BULL_CORE_PATTERN_SINGLETON_HPP
