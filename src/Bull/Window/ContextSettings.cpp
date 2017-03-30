#include <Bull/Window/ContextSettings.hpp>

namespace Bull
{
    ContextSettings ContextSettings::Best  = ContextSettings(24, 8, 16, 4, 5);
    ContextSettings ContextSettings::Worst = ContextSettings(0,  0, 0,  1, 1);
    ContextSettings ContextSettings::Empty = ContextSettings(0,  0, 0,  0, 0);

    ContextSettings::ContextSettings() :
        ContextSettings(ContextSettings::Worst)
    {
        /// Nothing
    }

    ContextSettings::ContextSettings(Uint8 depths, Uint8 stencil, Uint8 antialiasing, Uint8 major, Uint8 minor) :
        major(major),
        minor(minor),
        flags(Flag::Default),
        depths(depths),
        stencil(stencil),
        antialiasing(antialiasing)
    {
        /// Nothing
    }

    bool ContextSettings::operator==(const ContextSettings& right) const
    {
        return major        == right.major        &&
               minor        == right.minor        &&
               flags        == right.flags        &&
               depths       == right.depths       &&
               stencil      == right.stencil      &&
               antialiasing == right.antialiasing;
    }

    bool ContextSettings::operator!=(const ContextSettings& right) const
    {
        return !((*this) == right);
    }
}
