#ifndef Bull_DirectoryImplUnix_hpp
#define Bull_DirectoryImplUnix_hpp

#include <Bull/Core/FileSystem/DirectoryImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class DirectoryImplUnix : public DirectoryImpl
        {
        public:

            /*! \brief Create a directory
             *
             * \param path The path of the directory to create
             *
             * \return Return true if the file was created successfully, else otherwise
             *
             */
            static bool create(const String& path);

            /*! \brief Check if a directory exists
             *
             * \param path The path of the directory to check
             *
             * \return Return true if the directory exists, false otherwise
             *
             */
            static bool exists(const String& path);

            /*! \brief Delete a directory
             *
             * \param path The path of the directory to delete
             *
             * \return Return true if the directory was deleted successfully, false otherwise
             *
             */
            static bool remove(const String& path);

        public:

            /*! \brief Destructor
             *
             */
            virtual ~DirectoryImplUnix();

            /*! \brief Open a directory
             *
             * \param path The path of the directory
             *
             * \return Return true is the directory was opened successfully, false otherwise
             *
             */
            bool open(const String& path) override;

            /*! \brief Get the content of this Directory
             *
             * \param flags What we have to look for
             *
             * \return Return the list of content entity
             *
             */
            std::vector<Path> getContent(Uint32 flags) override;
        };
    }
}

#endif // Bull_DirectoryImplUnix_hpp
