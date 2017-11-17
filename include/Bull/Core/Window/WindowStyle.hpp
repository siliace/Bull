#ifndef BULL_CORE_WINDOW_WINDOWSTYLE_HPP
#define BULL_CORE_WINDOW_WINDOWSTYLE_HPP

namespace Bull
{
    enum WindowStyle
    {
        WindowStyle_None        = 0x0,  /*!< The Window do not have any decoration */
        WindowStyle_Closable    = 0x1,  /*!< The Window has a exit button */
        WindowStyle_Minimizable = 0x2,  /*!< The Window has a minimize button */
        WindowStyle_Maximizable = 0x4,  /*!< The Window has a maximize button */
        WindowStyle_Resizable   = 0x8, /*!< The Window is resizable with drag&drop */
        WindowStyle_Fullscreen  = 0x16, /*!< The Window is in full screen */
        WindowStyle_Default     = WindowStyle_Closable | WindowStyle_Minimizable | WindowStyle_Maximizable | WindowStyle_Resizable
    };
}

#endif // BULL_CORE_WINDOW_WINDOWSTYLE_HPP
