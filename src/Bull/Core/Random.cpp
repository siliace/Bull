#include <cstdlib>

#include <Bull/Core/Random.hpp>

namespace Bull
{
    /*! \brief Generate a pseudo random number
     *
     * \param min The minimum of the random number
     * \param max The maximum of the random number
     *
     * \return Return a pseudo random number between min and max
     *
     */
    Uint64 Random::random(Uint64 min, Uint64 max)
    {
        return (rand() % (max - min)) + min;
    }

    /*! \brief Change the current seed
     *
     * \param seed The new seed to use
     *
     */
    void Random::setSeed(unsigned int seed)
    {
        m_seed = seed;
        srand(m_seed);
    }

    /*! \brief Get the current seed
     *
     * \return Return the current seed
     *
     */
    unsigned int Random::getSeed() const
    {
        return m_seed;
    }
}
