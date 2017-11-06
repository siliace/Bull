#ifndef BULL_CORE_IO_INOUTSTREAM_HPP
#define BULL_CORE_IO_INOUTSTREAM_HPP

#include <Bull/Core/IO/InStream.hpp>
#include <Bull/Core/IO/OutStream.hpp>

namespace Bull
{
    struct BULL_CORE_API InOutStream : public virtual InStream, public virtual OutStream
    {
        /*! \brief Destructor
         *
         */
        virtual ~InOutStream();
    };
}

#endif // BULL_CORE_IO_INOUTSTREAM_HPP