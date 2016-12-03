#ifndef Bull_Path_hpp
#define Bull_Path_hpp

#include <Bull/Core/Integer.hpp>
#include <Bull/Core/String.hpp>
#include <Bull/Core/Time/Date.hpp>

namespace Bull
{
    struct BULL_API Path
    {
        /*! \brief Default constructor
         *
         */
        Path();

        /*! \brief Constructor
         *
         * \param target The path
         *
         */
        Path(const String& target);

        String pathName;
        bool   isFile;
        bool   isDirectory;
        Uint64 size;
        Date   creationDate;
        Date   lastAccessDate;
        Date   lastWriteDate;
    };
}

#endif // Bull_Path_hpp
