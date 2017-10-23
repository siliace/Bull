#include <Bull/Core/IO/StringStream.hpp>
#include <Bull/Core/Log/Log.hpp>
#include <Bull/Core/Pattern/RefCounted.hpp>

namespace Bull
{
    RefCounted::RefCounted(bool persistent) :
        m_isPersistent(persistent),
        m_referenceCounter(0)
    {
        /// Nothing
    }

    RefCounted::~RefCounted()
    {
        if(m_referenceCounter > 0)
        {
            StringStream ss;

            ss << "Deleting object with " << String::number(static_cast<unsigned int>(m_referenceCounter)) << " references";

            Log::get()->write(ss.toString(), LogLevel::LogLevel_Warning);
        }
    }

    void RefCounted::addReference()
    {
        m_referenceCounter++;
    }

    bool RefCounted::removeReference()
    {
        if(m_referenceCounter > 0)
        {
            if(--m_referenceCounter == 0 && !m_isPersistent)
            {
                delete this;

                return true;
            }
        }

        return false;
    }

    bool RefCounted::setPersistent(bool persistent, bool checkReference)
    {
        m_isPersistent = persistent;

        if(m_referenceCounter == 0 && !m_isPersistent && checkReference)
        {
            delete this;

            return true;
        }

        return false;
    }

    bool RefCounted::isPersistent() const
    {
        return m_isPersistent;
    }

    unsigned int RefCounted::getReferenceCount() const
    {
        return m_referenceCounter;
    }
}