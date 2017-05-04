#ifndef Bull_InOutStream_hpp
#define Bull_InOutStream_hpp

#include <Bull/Core/IO/InStream.hpp>
#include <Bull/Core/IO/OutStream.hpp>

namespace Bull
{
    struct BULL_CORE_API InOutStream : public virtual InStream, public virtual OutStream
    {
        /*! \brief Destructor
         *
         */
        virtual ~InOutStream()
        {
            /// Nothing
        }
    };
}

#endif // Bull_InOutStream_hpp
