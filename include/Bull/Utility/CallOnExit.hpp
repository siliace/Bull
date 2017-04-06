#ifndef Bull_CallOnExit_hpp
#define Bull_CallOnExit_hpp

#include <Bull/Core/Functor/Functor.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/System/Export.hpp>

namespace Bull
{
    class BULL_API CallOnExit : public NonCopyable
    {
    public:

        /*! @brief Constructor
         *
         * @param callback The function to call when the instance is destroyed
         *
         */
        CallOnExit(Functor<void> callback);

        /*! @brief Destructor
         *
         * Call the callback if enable
         *
         */
        ~CallOnExit();

        /*! @brief Change the callback
         *
         * @param callback The new callback
         *
         */
        void reset(Functor<void> callback);

        /*! @brief Enable or disable the callback
         *
         * @param enable Is the callback is enable?
         *
         */
        void enable(bool enable = true);

        /*! @brief Check if the callback is enable
         *
         * @return Return true if the callback is enable, false otherwise
         *
         */
        bool isEnable() const;

    private:

        Functor<void> m_callback;

        bool m_enable;
    };
}

#endif // Bull_CallOnExit_hpp
