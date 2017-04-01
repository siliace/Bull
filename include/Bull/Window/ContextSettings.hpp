#ifndef Bull_ContextSettings_hpp
#define Bull_ContextSettings_hpp

#include <Bull/Core/System/Integer.hpp>
#include <Bull/Core/System/Export.hpp>

namespace Bull
{
    struct BULL_API ContextSettings
    {
        enum Flag
        {
            Default           = 0x0,
            ForwardCompatible = 0x1,
            Debug             = 0x2,
            Compatibility     = 0x4,
        };

        static ContextSettings Best;
        static ContextSettings Worst;
        static ContextSettings Empty;

        /*! @brief Default constructor
         *
         */
        ContextSettings();

        /*! @brief Constructor
         *
         * @param depths
         * @param stencil
         * @param antialiasing
         * @param major
         * @param minor
         *
         */
        ContextSettings(Uint8 depths, Uint8 stencil, Uint8 antialiasing, Uint8 major, Uint8 minor);

        /*! @brief Compare two ContextSettings
         *
         * @param right The ContextSettings to compare to this one
         *
         * @return Return true if right and this are the same, false otherwise
         *
         */
        bool operator==(const ContextSettings& right) const;

        /*! @brief Compare two ContextSettings
         *
         * @param right The ContextSettings to compare to this one
         *
         * @return Return true if right and this are not the same, false otherwise
         *
         */
        bool operator!=(const ContextSettings& right) const;

        Uint8 major;
        Uint8 minor;
        Uint8 flags;
        Uint8 depths;
        Uint8 stencil;
        Uint8 antialiasing;
    };
}

#endif // Bull_ContextSettings_hpp
