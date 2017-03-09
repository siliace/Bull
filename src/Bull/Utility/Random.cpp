#include <cstdlib>

#include <Bull/Utility/Random.hpp>

namespace Bull
{
    Uint64 Random::random(Uint64 min, Uint64 max)
    {
        return (rand() % (max - min)) + min;
    }

    void Random::setSeed(unsigned int seed)
    {
        m_seed = seed;
        srand(m_seed);
    }

    unsigned int Random::getSeed() const
    {
        return m_seed;
    }
}
