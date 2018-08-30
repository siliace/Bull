#ifndef BULL_RENDER_SHADER_SHADERBINARY_HPP
#define BULL_RENDER_SHADER_SHADERBINARY_HPP

#include <vector>

#include <Bull/Core/Memory/ByteArray.hpp>

#include <Bull/Render/Context/ContextResource.hpp>

namespace Bull
{
    struct BULL_RENDER_API ShaderBinary : public ContextResource
    {
        /*! \brief Get the list of supported shader binary formats
         *
         * \return The list of supported formats
         *
         */
        static std::vector<int> getSupportedFormats();

        /*! \brief Default constructor
         *
         */
        ShaderBinary();

        /*! \brief Tell whether the ShaderBinary is valid
         *
         * \return True if the ShaderBinary is valid
         *
         */
        bool isValid() const;

        ByteArray content; /*!< The binary */
        unsigned int format; /*!< The binary format */
    };
}

#endif // BULL_RENDER_SHADER_SHADERBINARY_HPP
