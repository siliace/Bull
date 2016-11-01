#include <Bull/Render/Context/ContextSettings.hpp>

namespace Bull
{
    ContextSettings ContextSettings::Best  = ContextSettings(24, 8, 16, 4, 5);
    ContextSettings ContextSettings::Worst = ContextSettings(0,  0, 0,  1, 1);
    ContextSettings ContextSettings::Empty = ContextSettings(0,  0, 0,  0, 0);

    /*! \brief Default constructor
     *
     */
    ContextSettings::ContextSettings() :
        ContextSettings(ContextSettings::Worst)
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param depths
     * \param stencil
     * \param antialiasing
     * \param major
     * \param minor
     *
     */
    ContextSettings::ContextSettings(Uint8 depths, Uint8 stencil, Uint8 antialiasing, Uint8 major, Uint8 minor) :
        depths(depths),
        stencil(stencil),
        antialiasing(antialiasing),
        major(major),
        minor(minor)
    {
        /// Nothing
    }

    /*! \brief Compare two ContextSettings
     *
     * \param right The ContextSettings to compare to this one
     *
     * \return Return true if right and this are the same, false otherwise
     *
     */
    bool ContextSettings::operator==(const ContextSettings& right) const
    {
        return (depths       == right.depths)       &&
               (stencil      == right.stencil)      &&
               (antialiasing == right.antialiasing) &&
               (major        == right.major)        &&
               (minor        == right.minor);
    }

    /*! \brief Compare two ContextSettings
     *
     * \param right The ContextSettings to compare to this one
     *
     * \return Return true if right and this are not the same, false otherwise
     *
     */
    bool ContextSettings::operator!=(const ContextSettings& right) const
    {
        return !((*this) == right);
    }
}
