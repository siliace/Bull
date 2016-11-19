#ifndef Bull_TextureStateSaver_hpp
#define Bull_TextureStateSaver_hpp

#include <Bull/Core/Pattern/NonCopyable.hpp>

namespace Bull
{
    class TextureStateSaver : public NonCopyable
    {
    public:

        /*! \brief Default constructor
         *
         */
        TextureStateSaver();

        /*! \brief Destructor
         *
         */
        ~TextureStateSaver();

    private:

        int m_texture;
    };
}

#endif // Bull_TextureStateSaver_hpp

