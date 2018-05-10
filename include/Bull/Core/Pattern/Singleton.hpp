#ifndef BULL_CORE_PATTERN_SINGLETON_HPP
#define BULL_CORE_PATTERN_SINGLETON_HPP

#include <memory>

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Concurrency/Lock.hpp>

namespace Bull
{
    template<typename T>
    class BULL_CORE_API Singleton : public NonCopyable
    {
    public:

        struct Instance
        {
            /*! \brief Default constructor
             *
             * Create the instance is not exists
             *
             */
            Instance()
            {
                if(!s_instance)
                {
                    Lock lock(s_mutex);

                    if(!s_instance)
                    {
                        s_instance.reset(new T());
                    }
                }
            }

            /*! \brief Access operator
             *
             * \return A pointer to the instance
             *
             */
            T* operator->()
            {
                return s_instance.get();
            }
        };

    public:

        /*! \brief Get the Instance of the Singleton. Create the instance if needed
         *
         * \return The Instance
         *
         */
        static Instance getInstance()
        {
            return Instance();
        }

        /*! \brief Reset the Instance
         *
         */
        static void destroyInstance()
        {
            s_instance.reset();
        }

    private:

        static Mutex              s_mutex;
        static std::unique_ptr<T> s_instance;
    };

    template <typename T>
    Mutex Singleton<T>::s_mutex;

    template <typename T>
    std::unique_ptr<T> Singleton<T>::s_instance;
}

#endif // BULL_CORE_PATTERN_SINGLETON_HPP
