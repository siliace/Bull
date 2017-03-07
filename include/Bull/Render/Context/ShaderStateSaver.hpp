#ifndef Bull_ShaderStateSaver_hpp
#define Bull_ShaderStateSaver_hpp

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/System/Export.hpp>

namespace Bull
{
    class BULL_API ShaderStateSaver : public NonCopyable
    {
    public:

        /*! \brief Default constructor
         *
         */
        ShaderStateSaver();

        /*! \brief Destructor
         *
         */
        ~ShaderStateSaver();

    private:

        int m_shader;
    };
}

#endif // Bull_ShaderStateSaver_hpp
