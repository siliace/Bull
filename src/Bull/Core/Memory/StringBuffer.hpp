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
            explicit StringBuffer(std::size_t size);

            /*! \brief Constructor
             *
             * \param size     The size of the SharedString
             * \param capacity The capacity of the SharedString
             *
             */
            StringBuffer(std::size_t size, std::size_t capacity);

            std::size_t                   size;
            std::unique_ptr<char[]> string;
            std::size_t                   capacity;
        };
    }
}

#endif // BULL_CORE_MEMORY_STRINGBUFFER_HPP
