#ifndef BULL_CORE_LOADER_RESOURCE_HPP
#define BULL_CORE_LOADER_RESOURCE_HPP

#include <Bull/Core/FileSystem/Path.hpp>

namespace Bull
{
    class BULL_CORE_API Resource
    {
    public:

        /*! \brief Destructor
         *
         */
        virtual ~Resource();

        /*! \return Set the Path of the Resource
         *
         * \param path The Path
         *
         * \return This
         *
         */
        Resource& setPath(const Path& path);

        /*! \brief Get the Path of the Resource
         *
         * \return The Path
         *
         */
        const Path& getPath() const;

    private:

        Path m_path;
    };
}

#endif // BULL_CORE_LOADER_RESOURCE_HPP
