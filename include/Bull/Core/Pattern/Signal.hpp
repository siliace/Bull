#ifndef BULL_CORE_PATTERN_SIGNAL_HPP
#define BULL_CORE_PATTERN_SIGNAL_HPP

#include <functional>
#include <vector>

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/System/Integer.hpp>
#include <Bull/Core/Thread/Lock.hpp>

namespace Bull
{
    template <typename... Args>
    class Signal : public NonCopyable
    {
    public:

        class Slot
        {
        public:

            using Function = std::function<void(Args...)>;

        private:

            static Uint64 s_nextId;

            static Mutex s_idMutex;

        public:

            /*! \brief Default constructor
             *
             */
            Slot();

            /*! \brief Constructor
             *
             * \param function The function handled by the Slot
             *
             */
            Slot(const Function& function);

            /*! \brief Constructor
             *
             * \param instance
             * \param method
             *
             */
            template <typename Object>
            Slot(Object* instance, void(Object::*method)(Args...));

            /*! \brief Constructor
             *
             * \param instance
             * \param method
             *
             */
            template <typename Object>
            Slot(Object& instance, void(Object::*method)(Args...));

            /*! \brief Constructor
             *
             * \param instance
             * \param method
             *
             */
            template <typename Object>
            Slot(const Object* instance, void(Object::*method)(Args...) const);

            /*! \brief Constructor
             *
             * \param instance
             * \param method
             *
             */
            template <typename Object>
            Slot(const Object& instance, void(Object::*method)(Args...) const);

            /*! \brief Destructor
             *
             */
            ~Slot();

            /*! \brief Reset the function handled by the Slot
             *
             * \param function The function handled by the Slot
             *
             */
            void reset(const Function& function);

            /*! \brief
             *
             * \param instance
             * \param method
             *
             */
            template <typename Object>
            void reset(Object* instance, void(Object::*method)(Args...));

            /*! \brief
             *
             * \param instance
             * \param method
             *
             */
            template <typename Object>
            void reset(Object& instance, void(Object::*method)(Args...));

            /*! \brief
             *
             * \param instance
             * \param method
             *
             */
            template <typename Object>
            void reset(const Object* instance, void(Object::*method)(Args...) const);

            /*! \brief
             *
             * \param instance
             * \param method
             *
             */
            template <typename Object>
            void reset(const Object& instance, void(Object::*method)(Args...) const);

        private:

            friend class Signal<Args...>;

            /*! \brief Call the function handled by the Slot
             *
             * \param Arguments to sent to the function
             *
             */
            void call(Args... args) const;

            /*! \brief Get the ID of the Slot
             *
             * \return The ID
             *
             */
            Uint64 getId() const;

            /*! \brief Add a Signal to the listening Signals
             *
             * \param signal The Signal to add
             *
             */
            void addSignal(Signal<Args...>* signal);

        private:

            Uint64                        m_id;
            std::vector<Signal<Args...>*> m_signals;
            Function                      m_function;
        };

    public:

        /*! \brief Bind a Slot to this Signal
         *
         * \param slot The Slot to bind
         *
         */
        void bind(Slot& slot);

        /*! \brief Emit a Signal
         *
         * \param args Arguments to send to listening slots
         *
         */
        void operator()(Args... args) const;

    private:

        friend class Slot;

        /*! \brief Unbind a slot from this Signal
         *
         * \param slotId The Id of the Slot to unbind
         *
         */
        void unbind(Uint64 slotId);

    private:

        std::vector<Slot> m_slots;
    };

    template <typename... Args>
    Uint64 Signal<Args...>::Slot::s_nextId = 0;

    template <typename... Args>
    Mutex Signal<Args...>::Slot::s_idMutex;
}

#include <Bull/Core/Pattern/Signal.inl>
#include <Bull/Core/Pattern/Slot.inl>

#endif // BULL_SIGNAL_HPP
