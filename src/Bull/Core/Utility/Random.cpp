#include <cstdlib>

#include <Bull/Core/Utility/Random.hpp>

namespace Bull
{
    Random::Random()
    {
        setSeed(time(nullptr));
    }

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
