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
        depths(depths),
        stencil(stencil),
        antialiasing(antialiasing),
        major(major),
        minor(minor)
    {
        /// Nothing
    }

    bool ContextSettings::operator==(const ContextSettings& right) const
    {
        return (depths       == right.depths)       &&
               (stencil      == right.stencil)      &&
               (antialiasing == right.antialiasing) &&
               (major        == right.major)        &&
               (minor        == right.minor);
    }

    bool ContextSettings::operator!=(const ContextSettings& right) const
    {
        return !((*this) == right);
    }
}
