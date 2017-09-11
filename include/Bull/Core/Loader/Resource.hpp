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

        /*! \brief Set the file path of the Resource
         *
         * \param filePath The path
         *
         * \return This
         *
         */
        Resource& setFilePath(const Path& filePath);

        /*! \brief Get the file path of the Resource
         *
         * \return The path
         *
         */
        const Path& getFilePath() const;

    private:

        Path m_path;
    };
}

#endif // BULL_CORE_LOADER_RESOURCE_HPP
