#ifndef BULL_SIGNAL_HPP
#define BULL_SIGNAL_HPP

#include <functional>
#include <memory>
#include <vector>

#include <Bull/Core/Export.hpp>

namespace Bull
{
    template <typename... Args>
    class BULL_CORE_API Signal
    {
    public:

        using Callback = std::function<void(Args...)>;

        class Slot
        {
        public:

            /*! \brief Constructor
             *
             * \param source The source signal
             *
             */
            Slot(const Signal* source, const Callback& callback) :
                m_source(source),
                m_callback(callback)
            {
                /// Nothing
            }

            /*! \brief Get the source signal of the Slot
             *
             * \return The source signal
             *
             */
            const Signal* getSource() const
            {
                return m_source;
            }

            /*! \brief Call the Slot
             *
             * \param
             *
             */
            void trigger(Args... args) const
            {
                m_callback(args...);
            }

        private:

            const Signal* m_source;
            Callback      m_callback;
        };

    private:

        using SlotPtr  = std::shared_ptr<Slot>;
        using SlotList = std::vector<SlotPtr>;

    public:

        /*! \brief Default constructor
         *
         */
        Signal() = default;

        /*! \brief Connect a function to the Signal
         *
         * \param callback The function
         *
         */
        void connect(const Callback& callback)
        {
            m_slots.push_back(std::make_shared<Slot>(this, callback));
        }

        template <typename O>
        void connect(O& instance, void(O::*method)(Args...))
        {
            connect([instance, method](Args... args){
                (instance.*method)(std::forward<Args>(args)...);
            });
        }

        template <typename O>
        void connect(const O& instance, void(O::*method)(Args...) const)
        {
            connect([instance, method](Args... args){
                (instance.*method)(std::forward<Args>(args)...);
            });
        }

        template <typename O>
        void connect(O* instance, void(O::*method)(Args...))
        {
            connect([instance, method](Args... args){
                (instance->*method)(std::forward<Args>(args)...);
            });
        }

        template <typename O>
        void connect(const O* instance, void(O::*method)(Args...) const)
        {
            connect([instance, method](Args... args){
                (instance->*method)(std::forward<Args>(args)...);
            });
        }

        /*! \brief Emit the Signal
         *
         * \param args Arguments to send to slots
         *
         */
        void emit(Args... args)
        {
            for(const SlotPtr& slot : m_slots)
            {
                slot->trigger(args...);
            }
        }

    private:

        SlotList m_slots;
    };
}

#endif // BULL_SIGNAL_HPP
