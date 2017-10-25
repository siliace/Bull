#ifndef BULL_RENDER_CONTEXT_CONTEXTSETTINGSTYPE_HPP
#define BULL_RENDER_CONTEXT_CONTEXTSETTINGSTYPE_HPP

namespace Bull
{
    enum ContextSettingsType
    {
        ContextSettingsType_Default           = 0x0,
        ContextSettingsType_ForwardCompatible = 0x1,
        ContextSettingsType_Debug             = 0x2,
        ContextSettingsType_NoError           = 0x4,
    };
}

#endif // BULL_RENDER_CONTEXT_CONTEXTSETTINGSTYPE_HPP
