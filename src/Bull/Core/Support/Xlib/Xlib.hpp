#ifndef BULL_XLIB_HPP
#define BULL_XLIB_HPP

#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/keysym.h>
#include <X11/Xutil.h>

/// WTF, WHY DID THEY DEFINE NONE !?!
#if defined None
    #undef None
    #define XNone 0L
#endif

namespace Bull
{
    namespace prv
    {
        typedef ::GC       XGC;
        typedef ::Atom     XAtom;
        typedef ::Font     XFont;
        typedef ::Mask     XMask;
        typedef ::Time     XTime;
        typedef ::Cursor   XCursor;
        typedef ::Pixmap   XPixmap;
        typedef ::Window   XWindow;
        typedef ::Display  XDisplay;
        typedef ::Colormap XColormap;
        typedef ::Drawable XDrawable;
        typedef ::GContext XGContext;
    }
}

#endif //BULL_XLIB_HPP
