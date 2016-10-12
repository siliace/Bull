#include <Bull/Core/System/Config.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Core/FileSystem/Win32/DirectoryImplWin32.hpp>
    typedef Bull::prv::DirectoryImplWin32 DirectoryImplType;
#else
    #include <Bull/Core/FileSystem/Unix/DirectoryImplUnix.hpp>
    typedef Bull::prv::DirectoryImplUnix DirectoryImplType;
#endif // defined

namespace Bull
{
    namespace prv
    {
        /*! \brief Create a OS specific DirectoryImpl
         *
         * \param name The name of the directory to open
         *
         * \return Return the instance of the DirectoryImpl
         *
         */
        DirectoryImpl* DirectoryImpl::createInstance(const String& name)
        {
            DirectoryImplType* impl = new DirectoryImplType();

            if(impl->open(name))
            {
                return impl;
            }

            delete impl;
            return nullptr;
        }

        /*! \brief Create a directory
         *
         * \param name The name of the directory to create
         *
         * \return Return true if the file was created successfully, else otherwise
         *
         */
        bool DirectoryImpl::create(const String& name)
        {
            return DirectoryImplType::create(name);
        }

        /*! \brief Check if a directory exists
         *
         * \param name The name of the directory to check
         *
         * \return Return true if the directory exists, false otherwise
         *
         */
        bool DirectoryImpl::exists(const String& name)
        {
            return DirectoryImplType::exists(name);
        }

        /*! \brief Delete a directory
         *
         * \param name The name of the directory to delete
         *
         * \return Return true if the directory was deleted successfully, false otherwise
         *
         */
        bool DirectoryImpl::remove(const String& name)
        {
            return DirectoryImpl::remove(name);
        }

        /*! \brief Destructor
         *
         */
        DirectoryImpl::~DirectoryImpl()
        {
            /// Nothing
        }
    }
}

