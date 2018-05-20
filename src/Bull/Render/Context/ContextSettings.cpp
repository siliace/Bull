#include <Bull/Render/Context/ContextSettings.hpp>

namespace Bull
{
    ContextSettings ContextSettings::Best  = ContextSettings(24, 8, 16, 4, 6);
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
        type(ContextSettingsType_Default),
        depths(depths),
        profile(ContextSettingsProfile_Core),
        stencil(stencil),
        antialiasing(antialiasing)
    {
        /// Nothing
    }

    bool ContextSettings::operator==(const ContextSettings& right) const
    {
        return type         == right.type         &&
               major        == right.major        &&
               minor        == right.minor        &&
               depths       == right.depths       &&
               profile      == right.profile      &&
               stencil      == right.stencil      &&
               antialiasing == right.antialiasing;
    }

    bool ContextSettings::operator!=(const ContextSettings& right) const
    {
        return !((*this) == right);
    }
}
