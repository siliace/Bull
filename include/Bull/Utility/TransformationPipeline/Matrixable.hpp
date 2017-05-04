#ifndef BULL_MATRIXABLE_HPP
#define BULL_MATRIXABLE_HPP

#include <Bull/Math/Matrix/Matrix4.hpp>

#include <Bull/Utility/Export.hpp>

namespace Bull
{
    struct BULL_UTILITY_API Matrixable
    {
        /*! \brief Convert to a Matrix4F
         *
         * \return The Matrix4F
         *
         */
        virtual Matrix4F toMatrix() const = 0;
    };
}

#endif //BULL_MATRIXABLE_HPP
