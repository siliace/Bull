#ifndef BULL_CORE_PATTERN_SINGLETON_HPP
#define BULL_CORE_PATTERN_SINGLETON_HPP

#include <mutex>
#include <memory>

#include <Bull/Core/Pattern/NonCopyable.hpp>

namespace Bull
{
    template<typename T>
    class BULL_CORE_API Singleton : public NonCopyable
    {
    public:

        /*! \brief Get the Instance of the Singleton. Create the instance if needed
         *
         * \return The Instance
         *
         */
        static T& getInstance()
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

        /*! \brief Reset the Instance
         *
         */
        static void destroyInstance()
        {
            s_instance.reset();
        }

    private:

        static std::mutex         s_mutex;
        static std::unique_ptr<T> s_instance;
    };

    template <typename T>
    std::mutex Singleton<T>::s_mutex;

    template <typename T>
    std::unique_ptr<T> Singleton<T>::s_instance;
}

#endif // BULL_CORE_PATTERN_SINGLETON_HPP
