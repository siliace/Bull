#ifndef BULL_CORE_SUPPORT_XLIB_WMHINTS_HPP
#define BULL_CORE_SUPPORT_XLIB_WMHINTS_HPP

namespace Bull
{
    namespace prv
    {
        struct WMHints
        {
            enum Flag
            {
                Flag_Functions = 1 << 0,
                Flag_Decorations = 1 << 1,
            };

            enum Decor
            {
                Decor_All = 1 << 0,
                Decor_Border = 1 << 1,
                Decor_ResizeH = 1 << 2,
                Decor_Title = 1 << 3,
                Decor_Menu = 1 << 4,
                Decor_Minimize = 1 << 5,
                Decor_Maximize = 1 << 6,
            };

            enum Function
            {
                Function_All = 1 << 0,
                Function_Resize = 1 << 1,
                Function_Move = 1 << 2,
                Function_Minimize = 1 << 3,
                Function_Maximize = 1 << 4,
                Function_Close = 1 << 5,
            };

            /** \brief Default constructor
             *
             */
            WMHints();

            unsigned long flags;
            unsigned long functions;
            unsigned long decorations;
            long inputMode;
            unsigned long state;
        };
    }
}

#endif // BULL_CORE_SUPPORT_XLIB_WMHINTS_HPP
