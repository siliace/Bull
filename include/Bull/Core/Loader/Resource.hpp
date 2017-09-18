#ifndef BULL_CORE_LOADER_RESOURCE_HPP
#define BULL_CORE_LOADER_RESOURCE_HPP

#include <memory>

#include <Bull/Core/Loader/AbstractResourceSaver.hpp>
#include <Bull/Core/Loader/AbstractResourceLoader.hpp>
#include <Bull/Core/Loader/ParameterBag.hpp>

namespace Bull
{
    template <typename T, typename S = AbstractResourceSaver<T>, typename L = AbstractResourceLoader<T>, typename P = ParameterBag>
    class BULL_CORE_API Resource
    {
    public:

        /*! \brief Set the saver instance of the Resource
         *
         * \param saver The saver
         *
         */
        static void setSaver(S* saver);

        /*! \brief Set the loader instance of the Resource
         *
         * \param loader The loader
         *
         */
        static void setLoader(L* loader);

    private:

        static std::unique_ptr<S> s_saver;
        static std::unique_ptr<L> s_loader;

    public:

        /*! \brief Destructor
         *
         */
        virtual ~Resource();

        /*! \brief Load a Resource from a Path
         *
         * \param path       The path
         * \param parameters Parameters to create the resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        virtual bool loadFromPath(const Path& path, const P& parameters) = 0;

        /*! \brief Load a Resource from a Path
         *
         * \param stream     The stream to read to load
         * \param parameters Parameters to create the resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        virtual bool loadFromStream(InStream& stream, const P& parameters) = 0;

        /*! \brief Load a Resource from a memory area
         *
         * \param data       The memory
         * \param length     The length of data
         * \param parameters Parameters to create the resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        virtual bool loadFromMemory(const void* data, Index length, const P& parameters) = 0;

        /*! \brief Save a Resource to a file
         *
         * \param path       The Path to save the Resource
         * \param parameters Parameters to save the Resource
         *
         * \return True if the Resource was saved successfully
         *
         */
        virtual bool saveToPath(const Path& path, const P& parameters) const = 0;

        /*! \brief Save a Resource to a stream
         *
         * \param stream     The stream to write
         * \param parameters Parameters to save the Resource
         *
         * \return True if the Resource was saved successfully
         *
         */
        virtual bool saveToStream(OutStream& stream, const P& parameters) const = 0;

        /*! \brief Save a Resource to a memory area
         *
         * \param data       Memory to write to save the Resource
         * \param length     The length of the memory
         * \param parameters Parameters to save the Resource
         *
         * \return True if the Resource was saved successfully
         *
         */
        virtual bool saveToMemory(void* data, Index length, const P& parameters) const = 0;

    protected:

        /*! \brief Get the saver instance
         *
         * \return The saver
         *
         */
        const S* getSaver() const;

        /*! \brief Get the loader instance
         *
         * \return The loader
         *
         */
        const L* getLoader() const;
    };

    template <typename T, typename S, typename L, typename P>
    std::unique_ptr<S> Resource<T, S, L, P>::s_saver = std::make_unique<S>();

    template <typename T, typename S, typename L, typename P>
    std::unique_ptr<L> Resource<T, S, L, P>::s_loader = std::make_unique<L>();
}

#include <Bull/Core/Loader/Resource.inl>

#endif // BULL_CORE_LOADER_RESOURCE_HPP
