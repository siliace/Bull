#ifndef Bull_Singleton_hpp
#define Bull_Singleton_hpp

#include <memory>

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/Thread/Mutex.hpp>

namespace Bull
{
    template <typename TChild>
    class BULL_API Singleton : public NonCopyable
    {
    public:

        typedef std::shared_ptr<TChild> Instance;

        /*! \brief Get the instance of the singleton
         *
         * \param Return the instance of the singleton
         *
         */
        static Instance get();

    private:

        static Mutex m_mutex;
        static Instance m_instance;

    };

    template <typename TChild>
    Mutex Singleton<TChild>::m_mutex;

    template <typename TChild>
    std::shared_ptr<TChild> Singleton<TChild>::m_instance = std::shared_ptr<TChild>(nullptr);
}

#include <Bull/Core/Pattern/Singleton.inl>

#endif // Bull_Singleton_hpp
