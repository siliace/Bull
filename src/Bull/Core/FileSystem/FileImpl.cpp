#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/FileSystem/FileImpl.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/FileSystem/Win32/FileImplWin32.hpp>
    typedef Bull::prv::FileImplWin32 FileImplType;
#else
    #include <Bull/Core/FileSystem/Unix/FileImplUnix.hpp>
    typedef Bull::prv::FileImplUnix FileImplType;
#endif

namespace Bull
{
    namespace prv
    {
        /*! \brief Create a OS specific FileImpl
         *
         * \param name The name of the file to open
         * \param mode The opening mode of the file
         *
         * \return Return the instance of the FileImpl if the file exist, nullptr otherwise
         *
         */
        FileImpl* FileImpl::createInstance(const Path& name, Uint32 mode)
        {
            FileImplType* impl = new FileImplType();

            if(impl->open(name, mode))
            {
                return impl;
            }

            delete impl;
            return nullptr;
        }

        /*! \brief Create a file
         *
         * \param name The name of the file to create
         *
         * \return Return true if the file was created successfully, else otherwise
         *
         */
        bool FileImpl::create(const String& name)
        {
            return FileImplType::create(name);
        }

        /*! \brief Check if a file exists
         *
         * \param name The name of the file to check
         *
         * \return Return true if the file exists, false otherwise
         *
         */
        bool FileImpl::exists(const String& name)
        {
            return FileImplType::exists(name);
        }

        /*! \brief Copy a file
         *
         * \param path The path (relative or absolute) of the file to copy
         * \param path The new path (relative or absolute) of the file
         *
         * \return Return true if the copy was successfully, false otherwise
         *
         */
        bool FileImpl::copy(const Path& path, const String& newPath)
        {
            return FileImplType::copy(path, newPath);
        }

        /*! \brief Delete a file
         *
         * \param name The name of the file to delete
         *
         * \return Return true if the file was deleted successfully, false otherwise
         *
         */
        bool FileImpl::remove(const Path& name)
        {
            return FileImplType::remove(name);
        }

        /*! \brief Destructor
         *
         */
        FileImpl::~FileImpl() = default;
    }
}
