#ifndef Bull_Random_hpp
#define Bull_Random_hpp

#include <ctime>

#include <Bull/Core/Pattern/Singleton.hpp>
#include <Bull/Core/Integer.hpp>

namespace Bull
{
    class BULL_API Random : public Singleton<Random>
    {
    public:

        /*! \brief Generate a pseudo random number
         *
         * \param min The minimum of the random number
         * \param max The maximum of the random number
         *
         * \return Return a pseudo random number between min and max
         *
         */
        Uint64 random(Uint64 min, Uint64 max);

        /*! \brief Change the current seed
         *
         * \param seed The new seed to use
         *
         */
        void setSeed(unsigned int seed);

        /*! \brief Get the current seed
         *
         * \return Return the current seed
         *
         */
        unsigned int getSeed() const;

    private:

        unsigned int m_seed = time(nullptr); /*!< The seed */
    };
}

#endif // Bull_Random_hpp
