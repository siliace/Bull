#ifndef BULL_CORE_UTILITY_CALLONEXIT_HPP
#define BULL_CORE_UTILITY_CALLONEXIT_HPP

#include <Bull/Core/Functor/Functor.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

namespace Bull
{
    class BULL_CORE_API CleanupCallback : public NonCopyable
    {
    public:

        /*! \brief Default constructor
         *
         */
        CleanupCallback();

        /*! \brief Constructor
         *
         * \param callback The function to call when the instance is destroyed
         *
         */
        explicit CleanupCallback(Functor<void> callback);

        /*! \brief Destructor
         *
         * Call the callback if enable
         *
         */
        ~CleanupCallback();

        /*! \brief Change the callback
         *
         * \param callback The new callback
         *
         */
        void reset(Functor<void> callback);

        /*! \brief Enable or disable the callback
         *
         * \param enable Is the callback is enable?
         *
         */
        void enable(bool enable = true);

        /*! \brief Check if the callback is enable
         *
         * \return Return true if the callback is enable, false otherwise
         *
         */
        bool isEnable() const;

    private:

        bool          m_enable;
        Functor<void> m_callback;
    };
}

#endif // BULL_CORE_UTILITY_CALLONEXIT_HPP