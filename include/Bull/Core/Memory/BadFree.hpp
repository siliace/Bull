#ifndef BULL_CORE_MEMORY_BADFREE_HPP
#define BULL_CORE_MEMORY_BADFREE_HPP

#include <Bull/Core/Exception/Exception.hpp>

namespace Bull
{
    class BULL_CORE_API BadFree : public Exception
    {
    public:

        /*! \brief Constructor
         *
         * \param pointer The pointer that failed to free
         * \param array   True if the pointer is an array
         *
         */
        BadFree(const void* pointer, bool array);

        /*! \brief Tell whether the pointer is an array
         *
         * \return True if the pointer is an array
         *
         */
        bool isArray() const;

        /*! \brief Get the pointer that failed to be free
         *
         * \return The pointer
         *
         */
        const void* getPointer() const;

    protected:

        /*! \brief Get the log message
         *
         * \return The log message
         *
         */
        virtual String getLogMessage();

    private:

        const void* m_ptr;
        bool        m_array;
    };
}

#endif // BULL_CORE_MEMORY_BADFREE_HPP
