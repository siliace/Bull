#ifndef BULL_COREABSTRACTJOYSTICKMANAGER_HPP
#define BULL_COREABSTRACTJOYSTICKMANAGER_HPP

#include <Bull/Core/Window/AbstractInputManager.hpp>

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

#endif // BULL_COREABSTRACTJOYSTICKMANAGER_HPP
