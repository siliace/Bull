#include <Bull/Core/Support/Xlib/WMHints.hpp>

namespace Bull
{
    namespace prv
    {
        WMHints::WMHints() :
                flags(Flag_Decorations | Flag_Functions),
                state(0),
                functions(0),
                inputMode(0),
                decorations(0)
        {
            /// Nothing
        }
    }
}
