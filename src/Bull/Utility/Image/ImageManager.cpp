#include <Bull/Utility/Image/ImageManager.hpp>
#include <Bull/Utility/Image/STBSaver.hpp>
#include <Bull/Utility/Image/STBLoader.hpp>

namespace Bull
{
    Image& ImageManager::loadFromPixels(const ByteArray& pixels, const Vector2UI& size, const String& name, const ImageParameters& parameters)
    {
        std::unique_ptr<Image> resource = std::make_unique<Image>();

        if(hasResource(name))
        {
            return getResource(name);
        }

        ImageParameters resolvedParameters = parameters;

        if(resolveParameters(&resolvedParameters, pixels, size))
        {
            if(getLoader()->loadFromPixels(resource, pixels, size, resolvedParameters))
            {
                return pushResource(name, resource);
            }
        }

        throw FailedToLoad<Image>(name, castToReference(resource));
    }

    bool ImageManager::resolveParameters(ImageParameters* parameters, const ByteArray& pixels, const Vector2UI& size) const
    {
        return true;
    }

    std::unique_ptr<AbstractImageSaver>& ImageManager::getSaver()
    {
        if(!m_saver)
        {
            m_saver = std::make_unique<prv::STBSaver>();
        }

        return m_saver;
    }

    std::unique_ptr<AbstractImageLoader>& ImageManager::getLoader()
    {
        if(!m_loader)
        {
            m_loader = std::make_unique<prv::STBLoader>();
        }

        return m_loader;
    }

    Image* ImageManager::getEmptyResource() const
    {
        return new Image();
    }
}