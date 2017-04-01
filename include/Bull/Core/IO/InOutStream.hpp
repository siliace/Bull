#ifndef Bull_InOutStream_hpp
#define Bull_InOutStream_hpp

#include <Bull/Core/IO/InStream.hpp>
#include <Bull/Core/IO/OutStream.hpp>
#include <Bull/Core/System/Export.hpp>

namespace Bull
{
    struct BULL_API InOutStream : public virtual InStream, public virtual OutStream
    {
        /*! @brief Destructor
         *
         */
        virtual ~InOutStream()
        {
            /// Nothing
        }
    };
}

#endif // Bull_InOutStream_hpp
