#ifndef BULL_CORE_WINDOW_WINDOWSTYLE_HPP
#define BULL_CORE_WINDOW_WINDOWSTYLE_HPP

namespace Bull
{
    enum WindowStyle
    {
        None        = 0x0,  /*!< The Window do not have any decoration */

        Visible     = 0x1,  /*!< The Window is visible */
        Closable    = 0x2,  /*!< The Window has a exit button */
        Minimizable = 0x4,  /*!< The Window has a minimize button */
        Maximizable = 0x8,  /*!< The Window has a maximize button */
        Resizable   = 0x16, /*!< The Window is resizable with drag&drop */

        Fullscreen  = 0x32, /*!< The Window is in full screen */

        Default     = Visible | Closable | Minimizable | Maximizable | Resizable
    };
}

#endif // BULL_CORE_WINDOW_WINDOWSTYLE_HPP
