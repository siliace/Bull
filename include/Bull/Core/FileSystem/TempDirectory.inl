namespace Bull
{
    template <typename... Args>
    TempDirectoryRef TempDirectory::make(Args&&... args)
    {
        TempDirectory* tempDirectory = new TempDirectory(std::forward<Args>(args)...);
        tempDirectory->setPersistent(false);

        return tempDirectory;
    }
}