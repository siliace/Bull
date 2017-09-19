#ifndef BULL_SYSTEMABSTRACTJOYSTICKMANAGER_HPP
#define BULL_SYSTEMABSTRACTJOYSTICKMANAGER_HPP

#include <Bull/System/AbstractInputManager.hpp>

namespace Bull
{
    namespace prv
    {
        struct AbstractJoystickManager : public AbstractInputManager
        {
            /*! \brief Set the threshold of an axis movement to trigger an event
             *
             * \param threshold The threshold to use
             *
             */
            virtual void setThreshold(float threshold) = 0;

            /*! \brief Get the threshold of an axis movement to trigger an event
             *
             * \return threshold The threshold used
             *
             */
            virtual float getThreshold() const = 0;
        };
    }
}

#endif // BULL_SYSTEMABSTRACTJOYSTICKMANAGER_HPP
