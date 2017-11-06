#ifndef BULL_CORE_IO_CursorAwareINOUTSTREAM_HPP
#define BULL_CORE_IO_CursorAwareINOUTSTREAM_HPP

#include <Bull/Core/IO/CursorAwareInStream.hpp>
#include <Bull/Core/IO/CursorAwareOutStream.hpp>

namespace Bull
{
    struct BULL_CORE_API CursorAwareInOutStream : public virtual CursorAwareInStream, public virtual CursorAwareOutStream
    {
        /*! \brief Destructor
         *
         */
        virtual ~CursorAwareInOutStream();
    };
}

#endif // BULL_CORE_IO_CursorAwareINOUTSTREAM_HPP
