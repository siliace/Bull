#ifndef BULL_UTILITY_IMAGE_IMAGEMANAGER_HPP
#define BULL_UTILITY_IMAGE_IMAGEMANAGER_HPP

#include <Bull/Core/Loader/ResourceManager.hpp>
#include <Bull/Core/Pattern/Singleton.hpp>

#include <Bull/Utility/Image/AbstractImageSaver.hpp>
#include <Bull/Utility/Image/AbstractImageLoader.hpp>
#include <Bull/Utility/Image/Image.hpp>

namespace Bull
{
    namespace prv
    {
        class STBSaver;
        class STBLoader;
    }

    class BULL_UTILITY_API ImageManager : public ResourceManager<Image, AbstractImageSaver, AbstractImageLoader>, public Singleton<ImageManager>
    {
    public:

        /*! \brief Default constructor
         *
         */
        ImageManager() = default;

        /*! \brief
         *
         * \param pixels
         * \param size
         * \param name
         *
         * \return
         *
         */
        Image& loadFromPixels(const ByteArray& pixels, const Vector2UI& size, const String& name);

    protected:

        /*! \brief Get the ResourceSaver for the Resource
         *
         * \return The ResourceSaver
         *
         */
        std::unique_ptr<AbstractImageSaver>& getSaver() override;

        /*! \brief Get the ResourceLoader for the Resource
         *
         * \return The ResourceLoader
         *
         */
        std::unique_ptr<AbstractImageLoader>& getLoader() override;

        /*! \brief Get an empty Resource
         *
         * \return An empty Resource
         *
         */
        Image* getEmptyResource() const override;

    private:

        std::unique_ptr<AbstractImageSaver>  m_saver;
        std::unique_ptr<AbstractImageLoader> m_loader;
    };
}

#endif // BULL_UTILITY_IMAGE_IMAGEMANAGER_HPP
