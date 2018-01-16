#ifndef BULL_CORE_PATTERN_SINGLETON_HPP
#define BULL_CORE_PATTERN_SINGLETON_HPP

#include <memory>

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Concurrency/Lock.hpp>

namespace Bull
{
    template<typename TChild>
    class BULL_CORE_API Singleton : public NonCopyable
    {
    public:

        typedef std::unique_ptr<TChild>& Instance;

        /*! \brief Get the instance of the singleton. Create the instance if needed
         *
         * \param args Arguments to use to create the instance
         *
         * \return Return the instance of the singleton
         *
         */
        template<typename... Args>
        static Instance getInstance(Args&&... args)
        {
            if(!s_instance)
            {
                Lock lock(s_mutex);

                if(!s_instance)
                {
                    s_instance = std::make_unique<TChild>(std::forward<Args>(args)...);
                }
            }

            return s_instance;
        }

    private:

        static Mutex                   s_mutex;
        static std::unique_ptr<TChild> s_instance;
    };

    template <typename TChild>
    Mutex Singleton<TChild>::s_mutex;

    template <typename TChild>
    std::unique_ptr<TChild> Singleton<TChild>::s_instance;
}

#endif // BULL_CORE_PATTERN_SINGLETON_HPP
