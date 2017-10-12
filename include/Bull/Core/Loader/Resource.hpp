#ifndef BULL_CORE_LOADER_RESOURCE_HPP
#define BULL_CORE_LOADER_RESOURCE_HPP

#include <Bull/Core/Export.hpp>
#include <Bull/Core/FileSystem/Path.hpp>

namespace Bull
{
    class BULL_CORE_API Resource
    {
    public:

        /*! \brief Get the Path of the Resource
         *
         * \return The Path
         *
         */
        const Path& getPath() const;

    protected:

        /*! \brief Default constructor
         *
         */
        Resource() = default;

    private:

        Path m_path;
    };
}

#endif // BULL_CORE_LOADER_RESOURCE_HPP
