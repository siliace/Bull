#ifndef BULL_CORE_PATTERN_SHAREDSINGLETON_HPP
#define BULL_CORE_PATTERN_SHAREDSINGLETON_HPP

#include <mutex>
#include <memory>

#include <Bull/Core/RunTime.hpp>

namespace Bull
{
    template <typename T>
    class BULL_CORE_API SharedSingleton : public NonCopyable
    {
    public:

        using Instance = T&;

    public:

        /** \brief Import a SharedSingleton::Instance from another runtime
         *
         * \param runtime The RumTime to import the Instance from
         *
         * \return The imported Instance
         *
         */
        static Instance import(const RunTime& runTime)
        {
            s_instance = runTime.getSingleton<T>();

            return *s_instance;
        }

        /** \brief Get the Instance of the Singleton. Create the instance if needed
         *
         * \return The Instance
         *
         */
        static Instance getInstance()
        {
            if(!s_instance)
            {
                std::lock_guard<std::mutex> lock(s_mutex);

                if(!s_instance)
                {
                    s_instance.reset(new T());

                    RunTime::getInstance().registerSingleton<T>(s_instance);
                }
            }

            return *s_instance;
        }

    private:

        static std::mutex s_mutex;
        static std::shared_ptr<T> s_instance;
    };

    template <typename T>
    std::mutex SharedSingleton<T>::s_mutex;

    template <typename T>
    std::shared_ptr<T> SharedSingleton<T>::s_instance;
}

#endif // BULL_CORE_PATTERN_SHAREDSINGLETON_HPP
