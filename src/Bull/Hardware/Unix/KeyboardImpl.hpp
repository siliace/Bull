#ifndef Bull_KeyboardImpl_hpp
#define Bull_KeyboardImpl_hpp

#include <Bull/Hardware/Keyboard.hpp>

namespace Bull
{
    namespace prv
    {
        class KeyboardImpl
        {
        public:

            /*! @brief Check if a key is pressed
             *
             * @param key To key to check the state
             *
             * @return Return true if the key is down, false otherwise
             *
             */
            static bool isKeyPressed(Keyboard::Key key);
        };
    }
}

#endif // Bull_KeyboardImpl_hpp

