#ifndef BULL_CORE_ASSETS_ASSETIOSCHEDULER_HPP
#define BULL_CORE_ASSETS_ASSETIOSCHEDULER_HPP

#include <vector>

#include <Bull/Core/Assets/Asset.hpp>
#include <Bull/Core/Concurrency/Thread.hpp>

namespace Bull
{
    template <typename T, typename = std::enable_if<std::is_base_of<Asset, T>::value>>
    class BULL_CORE_API AssetIOScheduler
    {
    public:

        /*! \brief Get the percentage of loaded Asset
         *
         * \return The percentage of loaded Asset
         *
         */
        float getProgress() const
        {
            std::size_t count = 0;

            for(auto& thread : m_threads)
            {
                if(!thread->isRunning())
                {
                    count++;
                }
            }

            return (count / m_threads.size()) * 100.f;
        }

        /*! \brief Wait every Asset has been loaded
         *
         */
        void wait()
        {
            for(auto& thread : m_threads)
            {
                thread->wait();
            }

            m_threads.clear();
        }

    protected:

        /*! \brief Create a new task to run
         *
         * \param task The function to run
         *
         */
        void createTask(const std::function<void()>& task)
        {
            std::unique_ptr<Thread> thread = std::make_unique<Thread>(task);
            thread->start();

            m_threads.emplace_back(std::move(thread));
        }

    private:

        std::vector<std::unique_ptr<Thread>> m_threads;
    };
}

#endif // BULL_CORE_ASSETS_ASSETIOSCHEDULER_HPP
