#ifndef BULL_CORE_ASSETS_ASSETIOSCHEDULER_HPP
#define BULL_CORE_ASSETS_ASSETIOSCHEDULER_HPP

#include <future>
#include <vector>

#include <Bull/Core/Export.hpp>

namespace Bull
{
    template <typename T>
    class BULL_CORE_API AssetIOScheduler
    {
    public:

        /*! \brief Get the loading progression in percentage
         *
         * \return The progression
         *
         */
        float getProgression() const
        {
            std::size_t ready = 0;

            for(const auto& future : m_futures)
            {
                if(future.wait_for(std::chrono::seconds::zero()) == std::future_status::ready)
                {
                    ready += 1;
                }
            }

            return (ready / m_futures.size()) * 100.f;
        }

        /*! \brief Wait every Asset has been loaded
         *
         */
        void wait()
        {
            for(auto& future : m_futures)
            {
                future.get();
            }

            m_futures.clear();
        }

    protected:

        /*! \brief Create a new task to run
         *
         * \param task The function to run
         *
         */
        void createTask(const std::function<void()>& task)
        {
            m_futures.emplace_back(std::async(task));
        }

    private:

        std::vector<std::future<void>> m_futures;
    };
}

#endif // BULL_CORE_ASSETS_ASSETIOSCHEDULER_HPP
