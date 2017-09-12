#ifndef BULL_CORE_LOADER_RESOURCEMANAGER_HPP
#define BULL_CORE_LOADER_RESOURCEMANAGER_HPP

#include <map>

#include <Bull/Core/Functor/Functor.hpp>
#include <Bull/Core/Loader/AbstractResourceLoader.hpp>
#include <Bull/Core/Loader/AbstractResourceSaver.hpp>

namespace Bull
{
    template <typename T, typename Saver = AbstractResourceSaver<T>, typename Loader = AbstractResourceLoader<T>>
    class BULL_CORE_API ResourceManager
    {
    protected:

        /*! \brief Cast a resource pointer to a reference
         *
         * \param resource The resource
         *
         * \return The reference
         *
         */
        static T& castToReference(std::unique_ptr<T>& resource);

    public:

        /*! \brief Register a Resource to manage
         *
         * \param resource The Resource to manage
         * \param name     The name of the Resource
         *
         * \return True if the Resource was registered successfully
         *
         */
        bool registerResource(T* resource, const String& name);

        /*! \brief Tell whether a Resource exists
         *
         * \param name The name of the Resource
         *
         * \return True if the Resource exists
         *
         */
        bool hasResource(const String& name) const;

        /*! \brief Load a Resource from a Path
         *
         * \param path The path
         * \param name The name of the Resource
         *
         * \return The Resource
         *
         */
        T& loadFromPath(const Path& path, const String& name);

        /*! \brief Load a Resource from a Stream
         *
         * \param stream The stream
         * \param name   The name of the Resource
         *
         * \return The Resource
         *
         */
        T& loadFromStream(InStream& stream, const String& name);

        /*! \brief Load a Resource from a memory area
         *
         * \param data   The memory
         * \param length The length of data
         * \param name   The name of the Resource
         *
         * \return The Resource
         *
         */
        T& loadFromMemory(const void* data, Index length, const String& name);

        /*! \brief Get or create a Resource by its name
         *
         * \param name The name
         *
         * \return The Resource
         *
         */
        T& getResource(const String& name);

        /*! \brief Save a Resource to a file
         *
         * \param resource The Resource to save
         * \param path     The Path to save the Resource
         *
         * \return True if the Resource was saved successfully
         *
         */
        bool saveToPath(const T& resource, const Path& path);

        /*! \brief Save a Resource to a stream
         *
         * \param resource The Resource to save
         * \param stream
         *
         * \return True if the Resource was saved successfully
         *
         */
        bool saveToStream(const T& resource, OutStream& stream);

        /*! \brief Save a Resource to a memory area
         *
         * \param resource The Resource to save
         * \param data     The memory area to save the Resource
         * \param length   The length of data
         *
         * \return True if the Resource was saved successfully
         *
         */
        bool saveToMemory(const T& resource, void* data, Index length);

        /*! \brief Unregister a Resource
         *
         * \param name The name of the Resource
         *
         * \return The unregistered Resource
         *
         */
        T* unregisterResource(const String& name);

        /*! \brief Delete every Resources
         *
         */
        void purge();

    protected:

        /*! \brief Get the ResourceSaver for the Resource
         *
         * \return The ResourceSaver
         *
         */
        virtual std::unique_ptr<Saver>& getSaver() = 0;

        /*! \brief Get the ResourceLoader for the Resource
         *
         * \return The ResourceLoader
         *
         */
        virtual std::unique_ptr<Loader>& getLoader() = 0;

        /*! \brief Get an empty Resource
         *
         * \return An empty Resource
         *
         */
        virtual T* getEmptyResource() const = 0;

        /*! \brief Push a resource in the resources map
         *
         * \param name     The name of the resource
         * \param resource The resource
         *
         * \return A reference to the pushed resource
         *
         */
        T& pushResource(const String& name, std::unique_ptr<T>& resource);

    private:

        std::map<String, std::unique_ptr<T>> m_resources;
    };
}

#include <Bull/Core/Loader/ResourceManager.inl>

#endif // BULL_CORE_LOADER_RESOURCEMANAGER_HPP
