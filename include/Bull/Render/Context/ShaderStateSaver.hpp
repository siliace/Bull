#ifndef Bull_ShaderStateSaver_hpp
#define Bull_ShaderStateSaver_hpp

#include <Bull/Core/Pattern/NonCopyable.hpp>

namespace Bull
{
    class ShaderStateSaver : public NonCopyable
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
