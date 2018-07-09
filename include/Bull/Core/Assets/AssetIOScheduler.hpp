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

        /*! \brief Wait every Asset has been loaded
         *
         */
        void wait()
        {
            for(std::future<void>& future : m_futures)
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
