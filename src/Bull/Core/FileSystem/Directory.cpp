#include <cstdio>

#include <Bull/Core/FileSystem/Directory.hpp>
#include <Bull/Core/FileSystem/DirectoryImpl.hpp>
#include <Bull/Core/FileSystem/File.hpp>

namespace Bull
{
    /*! \brief Create a directory
     *
     * \param path The path of the directory to create
     *
     * \return Return true if the file was created successfully, else otherwise
     *
     */
    bool Directory::create(const String& path)
    {
        return prv::DirectoryImpl::create(path);
    }

    /*! \brief Check if a directory exists
     *
     * \param path The path of the directory to check
     *
     * \return Return true if the directory exists, false otherwise
     *
     */
    bool Directory::exists(const String& path)
    {
        return prv::DirectoryImpl::exists(path);
    }

    /*! \brief Copy a directory
     *
     * \param path The path (relative or absolute) of the directory to copy
     * \param path The new path (relative or absolute) of the directory
     *
     * \return Return true if the copy was successfully, false otherwise
     *
     */
    bool Directory::copy(const String& path, const String& newPath)
    {
        Directory target(path);
        bool success = true;

        if(!Directory::exists(newPath))
        {
            Directory::create(newPath);
        }

        if(!target.isOpen())
        {
            return false;
        }

        for(const Path& entity : target.getContent())
        {
            if(entity.pathName != "." && entity.pathName != "..")
            {
                if(entity.isDirectory)
                {
                    success &= Directory::copy(path + "/" + entity.pathName, newPath + "/" + entity.pathName);
                }
                else
                {
                    success &= File::copy(path + "/" + entity.pathName, newPath + "/" + entity.pathName);
                }
            }
        }

        return success;
    }

    /*! \brief Rename a directory
     *
     * \param path The path of the directory to rename
     * \param newPath The new path of the directory
     *
     * \return Return true if the directory was renamed successfully, false otherwise
     *
     */
    bool Directory::rename(const String& path, const String& newPath)
    {
        if(exists(path) && !exists(newPath))
        {
            return ::rename(path, newPath);
        }

        return false;
    }

    /*! \brief Delete a directory
     *
     * \param path The path of the directory to delete
     *
     * \return Return true if the directory was deleted successfully, false otherwise
     *
     */
    bool Directory::remove(const String& path)
    {
        return prv::DirectoryImpl::remove(path);
    }

    /*! \brief Default constructor
     *
     */
    Directory::Directory()
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param path The path of the directory
     *
     */
    Directory::Directory(const String& path)
    {
        open(path);
    }

    /*! \brief Destructor
     *
     */
    Directory::~Directory()
    {
        close();
    }

    /*! \brief Open a directory
     *
     * \param path The name of the directory
     *
     */
    bool Directory::open(const String& path)
    {
        m_path = path;

        m_impl.reset(prv::DirectoryImpl::createInstance(path));

        return true;
    }

    /*! \brief Check whether the directory is open
     *
     * \return Return true if the directory is open, false otherwise
     *
     */
    bool Directory::isOpen() const
    {
        return m_impl.get() != nullptr;
    }

    /*! \brief Close the directory
     *
     */
    void Directory::close()
    {
        m_path.clear();
        m_impl.reset();
    }

    /*! \brief Get the content of this Directory
     *
     * \param flags What we have to look for
     *
     * \return Return the list of content entity
     *
     */
    std::vector<Path> Directory::getContent(Uint32 flags)
    {
        if(m_impl)
        {
            return m_impl->getContent(flags);
        }

        return std::vector<Path>();
    }

    /*! \brief Get the path of the directory
     *
     * \return Return the path of the directory
     *
     */
    String Directory::getPath() const
    {
        return m_path;
    }
}
