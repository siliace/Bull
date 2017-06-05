#ifndef BULL_XLIB_HPP
#define BULL_XLIB_HPP

#include <X11/Xlib.h>
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
        typedef ::Atom    XAtom;
        typedef ::Cursor  XCursor;
        typedef ::Window  XWindow;
        typedef ::Display XDisplay;
    }
}

#endif //BULL_XLIB_HPP
