#ifndef BULL_CORE_UTILITY_ATINIT_HPP
#define BULL_CORE_UTILITY_ATINIT_HPP

#include <functional>

#include <Bull/Core/Export.hpp>

namespace Bull
{
    class BULL_CORE_API AtInit
    {
    public:

        /*! \brief Constructor
         *
         * Call the init function
         *
         * \param init The init function
         *
         */
        explicit AtInit(const std::function<void()>& init);

        /*! \brief Constructor
         *
         * Call the init function
         *
         * \param init The init function
         * \param clean The clean function
         *
         */
        AtInit(const std::function<void()>& init, std::function<void()>& clean);

        /*! \brief Copy constructor
         *
         */
        AtInit(const AtInit&) = delete;

        /*! \brief Constructor by movement semantic
         *
         */
        AtInit(AtInit&&) = delete;

        /*! \brief Destructor
         *
         * Call the clean function
         *
         */
        ~AtInit();

        /*! \brief Basic assignment operator
         *
         */
        AtInit& operator=(const AtInit&) = delete;

        /*! \brief Basic assignment operator by movement semantic
         *
         */
        AtInit& operator=(const AtInit&&) = delete;

    private:

        std::function<void()> m_clean;
    };
}

#endif // BULL_CORE_UTILITY_ATINIT_HPP
