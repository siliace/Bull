#ifndef BULL_CORE_ASSETS_ASSETLOADER_HPP
#define BULL_CORE_ASSETS_ASSETLOADER_HPP

#include <vector>

#include <Bull/Core/Thread/Thread.hpp>

namespace Bull
{
    template <typename T>
    class BULL_CORE_API AssetLoader
    {
    private:

        class Worker : public Runnable
        {
        public:

            /*! \brief Constructor
             *
             * \param function The function to run
             *
             */
            explicit Worker(const std::function<bool()>& function) :
                m_success(false),
                m_function(function)
            {
                /// Nothing
            }

            /*! \brief Load the resource
             *
             */
            void run() override
            {
                m_success = m_function();
            }

            /*! \brief Tell whether the Worker loaded de resource successfully
             *
             * \return True if the resource was loaded successfully
             *
             */
            bool isSuccess() const
            {
                return m_success;
            }

        private:

            bool                  m_success;
            std::function<bool()> m_function;
        };

        class ThreadWorker : public Thread
        {
        public:

            /*! \brief Constructor
             *
             * \param worker The Worker to run
             *
             */
            explicit ThreadWorker(std::unique_ptr<Worker> worker) :
                Thread(std::bind(&Worker::run, worker.get())),
                m_worker(std::move(worker))
            {
                /// Nothing
            }

            /*! \brief Get the Worker of the Thread
             *
             * \return The Worker
             *
             */
            const Worker& getWorker() const
            {
                return *m_worker;
            }

        private:

            std::unique_ptr<Worker> m_worker;
        };

    public:

        /*! \brief Get the percentage of loaded Asset
         *
         * \return The percentage of loaded Asset
         *
         */
        float getProgress() const
        {
            std::size_t count = 0;

            for(const std::unique_ptr<ThreadWorker>& thread : m_threads)
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
         * \return True if every Asset has been loaded successfully
         *
         */
        bool wait()
        {
            bool success = true;

            for(const std::unique_ptr<ThreadWorker>& thread : m_threads)
            {
                thread->wait();
                success &= thread->getWorker().isSuccess();
            }

            m_threads.clear();

            return success;
        }

    protected:

        /*! \brief Create a new task to run
         *
         * \param task The function to run
         *
         * \return True if the task was created successfully
         *
         */
        bool createTask(const std::function<bool()>& task)
        {
            std::unique_ptr<ThreadWorker> thread = std::make_unique<ThreadWorker>(std::make_unique<Worker>(task));

            if(!thread->start())
            {
                return false;
            }

            m_threads.emplace_back(std::move(thread));

            return true;
        }

    private:

        std::vector<std::unique_ptr<ThreadWorker>> m_threads;
    };
}

#endif // BULL_CORE_ASSETS_ASSETLOADER_HPP
