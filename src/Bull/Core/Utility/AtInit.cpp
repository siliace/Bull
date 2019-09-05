#include <Bull/Core/Utility/AtInit.hpp>

namespace Bull
{
    AtInit::AtInit(const std::function<void()>& init)
    {
        if(init)
        {
            init();
        }
    }

    AtInit::AtInit(const std::function<void()>& init, const std::function<void()>& clean) :
            m_clean(clean)
    {
        if(init)
        {
            init();
        }
    }

    AtInit::~AtInit()
    {
        if(m_clean)
        {
            m_clean();
        }
    }
}