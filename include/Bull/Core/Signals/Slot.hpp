#ifndef BULL_CORE_SIGNALS_SLOT_HPP
#define BULL_CORE_SIGNALS_SLOT_HPP

#include <functional>

#include <Bull/Core/Pattern/NonCopyable.hpp>

namespace Bull
{
    template <typename T>
    class BULL_CORE_API Slot : public NonCopyable
    {
    public:

        using Callable = std::function<void(T)>;

    public:

        /*! \brief Default constructor
         *
         */
        Slot() = default;

        /*! \brief Constructor
         *
         * \param callable The function to call
         *
         */
        explicit Slot(const Callable& callable) :
            m_function(callable)
        {
            /// Nothing
        }

        template <typename... Args>
        void emit(Args&&... args)
        {
            m_function(std::forward<Args>(args)...);
        }

        template <typename... Args>
        void operator()(Args&&... args)
        {
            emit(std::forward<Args>(args)...);
        }

    private:

        Callable m_function;
    };
}

#endif // BULL_CORE_SIGNALS_SLOT_HPP
