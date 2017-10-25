#ifndef BULL_RENDER_CONTEXT_CONTEXTSETTINGS_HPP
#define BULL_RENDER_CONTEXT_CONTEXTSETTINGS_HPP

#include <Bull/Core/Configuration/Integer.hpp>

#include <Bull/Render/Context/ContextSettingsProfile.hpp>
#include <Bull/Render/Context/ContextSettingsType.hpp>
#include <Bull/Render/Export.hpp>

namespace Bull
{
    struct BULL_RENDER_API ContextSettings
    {
        static ContextSettings Best;
        static ContextSettings Worst;
        static ContextSettings Empty;

        /*! \brief Default constructor
         *
         */
        ContextSettings();

        /*! \brief Constructor
         *
         * \param depths
         * \param stencil
         * \param antialiasing
         * \param major
         * \param minor
         *
         */
        ContextSettings(Uint8 depths, Uint8 stencil, Uint8 antialiasing, Uint8 major, Uint8 minor);

        /*! \brief Compare two ContextSettings
         *
         * \param right The ContextSettings to compare to this one
         *
         * \return Return true if right and this are the same, false otherwise
         *
         */
        bool operator==(const ContextSettings& right) const;

        /*! \brief Compare two ContextSettings
         *
         * \param right The ContextSettings to compare to this one
         *
         * \return Return true if right and this are not the same, false otherwise
         *
         */
        bool operator!=(const ContextSettings& right) const;

        Uint32                 type;
        Uint8                  major;
        Uint8                  minor;
        Uint8                  depths;
        ContextSettingsProfile profile;
        Uint8                  stencil;
        Uint8                  antialiasing;
    };
}

#endif // BULL_RENDER_CONTEXT_CONTEXTSETTINGS_HPP
