#ifndef BULL_CORE_UTILITY_RANDOM_HPP
#define BULL_CORE_UTILITY_RANDOM_HPP

#include <random>

#include <Bull/Core/Configuration/Integer.hpp>
#include <Bull/Core/Meta/TypeTrait.hpp>

namespace Bull
{
    class BULL_CORE_API RandomGenerator
    {
    public:

        /*! \brief Default constructor
         *
         */
        RandomGenerator();

        /*! \brief Constructor
         *
         * \param seed The seed to initialize the RandomGenerator
         *
         */
        explicit RandomGenerator(Uint64 seed);

        /*! \brief Generate a random number
         *
         * \param min The lowest value of the generated random number
         * \param max The biggest value of the generated random number
         *
         * \return The random number
         *
         */
        template <typename T>
        T number(T min = Min<T>::Value, T max = Max<T>::Value);

    private:

        std::mt19937 m_generator;
    };
}

#endif // BULL_CORE_UTILITY_RANDOM_HPP
