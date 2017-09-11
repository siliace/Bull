#ifndef BULL_CORE_LOADER_RESOURCE_HPP
#define BULL_CORE_LOADER_RESOURCE_HPP

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/IO/InStream.hpp>

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

        /*! \brief Load the Resource from a file
         *
         * \param path The path to this file
         *
         * \return True if the Resource was loaded successfully
         *
         */
        virtual bool loadFromPath(const Path& path) = 0;

        /*! \brief Load the Resource from a stream
         *
         * \param path The stream
         *
         * \return True if the Resource was loaded successfully
         *
         */
        virtual bool loadFromStream(InStream& stream) = 0;

        /*! \brief Load the Resource from the memory
         *
         * \param data   The memory to load
         * \param length The length of the memory
         *
         * \return True if the Resource was loaded successfully
         *
         */
        virtual bool loadFromMemory(const void* data, Index length) = 0;

    private:

        Path m_path;
    };
}

#endif // BULL_CORE_LOADER_RESOURCE_HPP
