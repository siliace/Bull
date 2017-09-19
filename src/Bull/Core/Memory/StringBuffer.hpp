#ifndef BULL_CORE_MEMORY_STRINGBUFFER_HPP
#define BULL_CORE_MEMORY_STRINGBUFFER_HPP

#include <memory>

#include <Bull/Core/Configuration/Integer.hpp>

namespace Bull
{
    namespace prv
    {
        struct StringBuffer
        {
            /*! \brief Default constructor
             *
             */
            StringBuffer();

            /*! \brief Constructor
             *
             * \param size The size of the SharedString
             *
             */
            explicit StringBuffer(Index size);

            /*! \brief Constructor
             *
             * \param size     The size of the SharedString
             * \param capacity The capacity of the SharedString
             *
             */
            StringBuffer(Index size, Index capacity);

            Index                   size;
            std::unique_ptr<char[]> string;
            Index                   capacity;
        };
    }
}

#endif // BULL_CORE_MEMORY_STRINGBUFFER_HPP
